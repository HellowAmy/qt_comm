﻿#include "ms_web_client.h"

ms_web_client::ms_web_client()
{
    vinit_c(vlog::e_info);

    set_file_path();

    //===== 添加任务函数到容器 =====
    //账号注册
    map_func.insert(pair<enum_transmit,function<void(const string&)>>
             (e_register_back,bind(&ms_web_client::back_register,this,_1)));
    //登录请求
    map_func.insert(pair<enum_transmit,function<void(const string&)>>
             (e_login_back,bind(&ms_web_client::back_login,this,_1)));
    //错误反馈
    map_func.insert(pair<enum_transmit,function<void(const string&)>>
             (e_error,bind(&ms_web_client::back_error,this,_1)));
    //数据交换
    map_func.insert(pair<enum_transmit,function<void(const string&)>>
             (e_swap_txt,bind(&ms_web_client::back_swap_txt,this,_1)));
    //文件交换
    map_func.insert(pair<enum_transmit,function<void(const string&)>>
             (e_swap_file,bind(&ms_web_client::back_swap_file,this,_1)));
    //===== 添加任务函数到容器 =====
}

void ms_web_client::set_file_path(std::string path)
{
    v_path_files = path;
}

int ms_web_client::ask_register(std::string passwd)
{
    vlogf("ask_register");
    ct_register ct;
    strncpy(ct.passwd,passwd.c_str(),sizeof(ct.passwd));
    string str = ux_manage::to_str<enum_transmit,ct_register>
            (enum_transmit::e_register,ct);
    return send_meg(str);
}

int ms_web_client::ask_login(long long account, std::string passwd)
{
    vlogf("ask_login");
    ct_login ct;
    ct.account = account;
    strncpy(ct.passwd,passwd.c_str(),sizeof(ct.passwd));
    string str = ux_manage::to_str<enum_transmit,ct_login>
            (enum_transmit::e_login,ct);
    return send_meg(str);
}

int ms_web_client::ask_swap_txt
    (long long account_from, long long account_to, std::string txt)
{
    vlogf("ask_swap_txt");
    ct_swap_txt ct;
    ct.account_from = account_from;
    ct.account_to = account_to;
    strncpy(ct.data,txt.c_str(),sizeof(ct.data));
    string str = ux_manage::to_str<enum_transmit,ct_swap_txt>
            (enum_transmit::e_swap_txt,ct);
    return send_meg(str);
}

void ms_web_client::ask_swap_file
    (long long account_from,long long account_to,std::string filename)
{
    vlogf("ask_swap_file");
    vlogf(vv(account_from) vv(account_to) vv(filename));
    auto func = [=](long long account_from,long long account_to,std::string filename)
    {
        vlevel(vlog::e_warning,vlog::e_warning);
        vlogf("func:in");
        bool is_err = false;
        ct_swap_file ct;
        ct.account_from = account_from;
        ct.account_to = account_to;

        fstream ofs(filename,ios::in | ios::binary);
        if(ofs.is_open())
        {
            vlogf("is_open");
            ofs.seekg(0,ios::end);
            ct.lenght = ofs.tellg();
            ofs.seekg(0,ios::beg);

            string temp = vts::stm(filename)("\\",-1,-1);
            strncpy(ct.filename,temp.c_str(),sizeof(ct.filename));

            long long size_sum = 0;
            while(ofs.eof() == false && this->sock().isConnected())
            {
                //发送文件时状态
                if(ofs.tellg() == 0) ct.status = 0;
                else ct.status = 1;

                ofs.read(ct.buf,sizeof(ct.buf));
                ct.buf_size = ofs.gcount();//记录发送真实字节
                size_sum += ofs.gcount();//累计发送字节
                if(size_sum == ct.lenght) ct.status = 2;//最后一次发送
                vlogf(vv(size_sum) vv(ct.lenght));

                string str = ux_manage::to_str<enum_transmit,ct_swap_file>
                        (enum_transmit::e_swap_file,ct);
                int send_size = send_meg(str);
                if(send_size == 0)
                {
                    size_t size_now = this->sock().channel->writeBufsize();
                    if(size_now > WRITE_BUFSIZE_HIGH_WATER)
                    {
                        for(int i=0;i<100000000;i++)
                        {
                            if(this->sock().isConnected() == false)
                                { is_err = true; break; }

                            size_t temp = this->sock().channel->writeBufsize();
                            if(temp < WRITE_BUFSIZE_HIGH_WATER/8)
                                { vlogw("break high line"); break; }
                            else if(temp > WRITE_BUFSIZE_HIGH_WATER*2)
                                { vlogw("out high line"); }
                        }
                    }
                }
                else if(send_size == -1) { vlogw("send flase"); is_err = true; break; }
            }
            ofs.close();
            vlogw("close: " vv(is_err));
        }
        else vlogw("open false: " vv(filename));
        vlevel(vlog::e_info,vlog::e_info);
    };

    std::thread th(func,account_from,account_to,filename);
    th.detach();
    vlogw("thread detach: out");
}

bool ms_web_client::is_connect()
{
    return this->sock().isConnected();
}

void ms_web_client::on_open()
{
    vlogf("on_open");
    if(func_open) func_open();
}

void ms_web_client::on_message(const std::string &meg)
{
    vlevel(vlog::e_warning,vlog::e_warning);
    vlogf("on_message: " vv(std::this_thread::get_id()));

    //执行匹配的任务函数
    enum_transmit cmd = *(enum_transmit*)
            string(meg.begin(),meg.begin() + sizeof(enum_transmit)).c_str();
    auto it_find = map_func.find(cmd);
    if(it_find != map_func.end())
    {
        vlogf("on_message type: " vv(cmd));
        (std::bind(it_find->second,meg))();
    }
    else vlogw("on_message:not find");
    vlevel(vlog::e_info,vlog::e_info);
}

void ms_web_client::on_close()
{
    vlogw("on_close");
    if(func_close) func_close();
}

int ms_web_client::send_meg(const std::string &meg)
{
    int ret = 0;
    if(this->sock().isConnected()) ret = this->sock().send(meg.c_str(),meg.size());
    else { vlogw("isConnected false"); ret = -1; }
    return ret;
}

bool ms_web_client::write_file(shared_ptr<std::fstream> sp_ofs, const char *buf, int size)
{
    sp_ofs->write(buf,size);
    if(sp_ofs->fail()) { vlogw("write_file false"); return false; }
    else return true;
}

void ms_web_client::back_register(const std::string &meg)
{
    vlogw("back_register");
    ct_register_back ct;
    enum_transmit cmd;
    ux_manage::from_str<enum_transmit,ct_register_back>(meg,cmd,ct);
    if(func_register_back) func_register_back(ct.account,ct.passwd,ct.flg);
}

void ms_web_client::back_login(const std::string &meg)
{
    vlogw("back_login");
    ct_login_back ct;
    enum_transmit cmd;
    ux_manage::from_str<enum_transmit,ct_login_back>(meg,cmd,ct);
    if(func_login_back) func_login_back(ct.flg);
}

void ms_web_client::back_error(const std::string &meg)
{

}

void ms_web_client::back_swap_txt(const std::string &meg)
{
    vlogf("back_swap_txt");
    ct_swap_txt ct;
    enum_transmit cmd;
    ux_manage::from_str<enum_transmit,ct_swap_txt>(meg,cmd,ct);
    if(func_swap_txt) func_swap_txt(ct.account_from,ct.account_to,ct.data);
}

void ms_web_client::back_swap_file(const std::string &meg)
{
    ct_swap_file ct;
    enum_transmit cmd;
    ux_manage::from_str<enum_transmit,ct_swap_file>(meg,cmd,ct);

    //同名文件同时传输导致内容混乱并发生错误
    auto it = map_ofs.find(ct.filename);
    if(it == map_ofs.end())
    {
        vlogw("creator fstream: " vv(ct.filename));
        map_ofs.insert(pair<string,shared_ptr<fstream>>
                       (ct.filename,std::make_shared<fstream>()));
        it = map_ofs.find(ct.filename);
        if(it == map_ofs.end()) { vlogw("creator fstream false"); return; }
    }

    //接受状态
    if(ct.status == 1 && it->second->is_open())
    {
        if(write_file(it->second,ct.buf,ct.buf_size) == false)
            { vlogw("write_file and return: " vv(ct.status)); return; };
    }
    else if(ct.status == 2 && it->second->is_open())
    {
        if(write_file(it->second,ct.buf,ct.buf_size) == false)
            { vlogw("write_file: " vv(ct.status)); return; };
        it->second->close();
        map_ofs.erase(it);

        vlogw("func_swap_file" vv(ct.status));
        if(func_swap_file) func_swap_file(ct.account_from,ct.account_to,ct.filename);
    }
    else if(ct.status == 0)
    {
        //首次进入清空文件
        vlogw("func_swap_file open: " vv(v_path_files + it->first));
        it->second->open(v_path_files + it->first,ios::out);
        if(it->second->is_open()) it->second->close();

        it->second->open(v_path_files + it->first,ios::out|ios::binary|ios::app);
        if(it->second->is_open())
        {
            if(write_file(it->second,ct.buf,ct.buf_size) == false)
                { vlogw("write_file: " vv(ct.status)); };
        }
        else vlogw("file not open");
    }
    else vlogw("swap_file error" vv(it->second->is_open()) vv(ct.status));
}
