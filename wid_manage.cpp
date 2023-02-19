#include "wid_manage.h"

#include <QTimer>


#define qfrs(str) QString::fromStdString(str)
#define qtos(str) str.toStdString()

wid_manage::wid_manage(QWidget *parent)
    : QObject{parent}
{
    v_login = new wid_login;//登录窗口
    v_login->show();

    v_friends_list = new wid_friends_list;//好友列表
    v_friends_list->close();

    v_net = new net_connect;
    if(v_net->open_connect() < 0) { vloge("open_connect err"); };

    //发送--用户输入信息
    connect(v_friends_list,&wid_friends_list::fa_send_news,this,
            [=](en_info en,long long account,QString info){

        if(en == en_info::e_send_txt)
        {
            vlogf("e_send_txt" vv(account) vv(qtos(info)));
            v_net->ask_swap_txt(account,info);
        }
        else if(en == en_info::e_send_pic)
        {
            vlogf("e_send_pic" vv(account) vv(qtos(info)));
            QFileInfo info_file(info);
            v_net->ask_swap_file(account,info_file.fileName(),info,en_build_file::e_spic);
        }
        else if(en == en_info::e_send_file)
        {
            vlogf("e_send_file" vv(account) vv(qtos(info)));
            QFileInfo info_file(info);
            v_net->ask_swap_file(account,info_file.fileName(),info,en_build_file::e_file);
        }
    });

    //发送--添加好友请求
    connect(v_friends_list,&wid_friends_list::fa_add_friend,this,
            [=](long long account){
        v_net->ask_swap_add_friend(account);
    });

    //发送--发送到网络//========================
    connect(v_login,&wid_login::fa_login,this,
            [=](long long account,QString passwd){

        vlogf("fa_login" vv(account) vv(qtos(passwd)));
        v_net->ask_login(account,passwd);
    });

    //网络返回--注册//========================
    connect(v_login,&wid_login::fa_register,this,
            [=](QString name,QString passwd){

        vlogf("fa_register" vv(qtos(passwd)) vv(qtos(name)));
        v_net->ask_register(passwd);
    });

    //===== 网络反馈 =====
    //==服务器响应
    connect(v_net,&net_connect::fa_open,this,[=](){
        vlogf("fa_open");//
    });

    connect(v_net,&net_connect::fa_close,this,[=](){
        vlogf("fa_close");//
    });

    connect(v_net,&net_connect::fa_register_back,this,
            [=](long long account,QString passwd,bool ok){

        vlogf("fa_register" vv(account) vv(qtos(passwd)) vv(ok));//
        v_login->show_register_back(ok,account);
    });

    connect(v_net,&net_connect::fa_login_back,this,
            [=](long long account,bool ok){

        vlogf("fa_login_back" vv(account) vv(ok));
        if(ok) { v_net->ask_friends_list(v_net->get_account()); }
    });

    connect(v_net,&net_connect::fa_logout_back,this,
            [=](long long account,bool ok){

        vlogf("fa_logout_back" vv(account) vv(ok));
        if(ok) v_net->close_connect();
    });

    connect(v_net,&net_connect::fa_recover_passwd_back,this,
            [=](long long account,QString passwd,bool ok){

        vlogf("fa_recover_passwd_back" vv(account) vv(qtos(passwd)) vv(ok));//
        if(ok) v_net->close_connect();
    });

    connect(v_net,&net_connect::fa_friends_list_back,this,
            [=](QMap<long long,string> map){

        for(auto it=map.begin();it!=map.end();it++)
        {
            vlogf(vv(it.key()) vv(it.value()));
        }

        if(v_login->isHidden() == false)
        {
            v_friends_list->set_account(v_net->get_account());
            v_friends_list->move(v_login->pos());
            v_login->close();
        }

        v_friends_list->into_friends(map);
        v_friends_list->show();
    });

    connect(v_net,&net_connect::fa_add_ret_back,this,
            [=](long long account,bool ok,bool self){
        if(self == true) { v_net->ask_friends_list(v_net->get_account()); }
        else
        {
            QString info;
            if(ok) { info = "成功添加账号: " + QString::number(account); }
            else { info = "对方不同意添加为好友: " + QString::number(account);  }
            wid_dialog temp(info);
            temp.exec();

            if(ok) { v_net->ask_friends_list(v_net->get_account()); }
        }
    });

    //交换函数
    connect(v_net,&net_connect::fa_swap_txt,this,
            [=](long long account_from,QString txt){

        vlogf("fa_prog_send" vv(account_from) vv(qtos(txt)));//
        v_friends_list->into_news(en_info::e_send_txt,account_from,txt);
    });

    connect(v_net,&net_connect::fa_swap_add_friend,this,
            [=](long long account_from){
        QString info = "同意添加[ "+ QString::number(account_from) +" ]为好友吗";
        wid_dialog temp(info);
        temp.exec();
        v_net->ask_add_ret(account_from,temp.get_status());
    });

    connect(v_net,&net_connect::fa_swap_build,this,
            [=](long long account_from,QString filename,en_build_file type){

        if(type == en_build_file::e_file)
        {
            vlogf("fa_prog_send" vv(account_from) vv(qtos(filename)));//
            v_friends_list->into_news(en_info::e_send_file,account_from,filename);
        }
    });

    connect(v_net,&net_connect::fa_swap_file_finish,this,
            [=](long long account_from,QString filename,en_build_file type,bool is_ok){

        if(type == en_build_file::e_file)
        {
            //文件进度(需要三个字段:文件名,进度值,是否完成(prog/finish))(分割符:##)
            QString info = filename+"##100##1";
            v_friends_list->into_news(en_info::e_send_file_prog,account_from,info);
        }
        else if(type == en_build_file::e_spic)
        { v_friends_list->into_news(en_info::e_send_pic,account_from,filename); }

        vlogf("fa_swap_file_finish" vv(account_from) vv(qtos(filename)) vv(type) vv(is_ok));//
    });

    connect(v_net,&net_connect::fa_swap_file_ret,this,
            [=](long long account_from,QString filename,en_build_file type,bool is_ok){

        if(type == en_build_file::e_file)
        {
            //文件进度(需要三个字段:文件名,进度值,是否完成(prog/finish))(分割符:##)
            QString info = filename+"##100##1";
            v_friends_list->into_news(en_info::e_send_file_prog,account_from,info);
        }
        vlogf("fa_swap_file_ret" vv(account_from) vv(qtos(filename)) vv(type) vv(is_ok));//
    });

    connect(v_net,&net_connect::fa_swap_error,this,
            [=](long long account_from,en_swap_error err){

        vlogf("fa_swap_error" vv(account_from) vv(err));//
    });

    connect(v_net,&net_connect::fa_prog_send,this,
            [=](QString filename,long long account_from,int now){

        //文件进度(需要三个字段:文件名,进度值,是否完成(prog/finish))(分割符:##)
        QString info = filename+"##"+QString::number(now)+"##0";
        v_friends_list->into_news(en_info::e_send_file_prog,account_from,info);
//        vlogf("fa_prog_send: " vv(qtos(filename)) vv(account_from)  vv(now));//
    });

    connect(v_net,&net_connect::fa_prog_recv,this,
            [=](QString filename,long long account_from,int now){

        //文件进度(需要三个字段:文件名,进度值,是否完成(prog/finish))(分割符:##)
        QString info = filename+"##"+QString::number(now)+"##0";
        v_friends_list->into_news(en_info::e_send_file_prog,account_from,info);
//        vlogf("fa_prog_recv: " vv(qtos(filename)) vv(account_from)  vv(now));//
    });
    //===== 网络反馈 =====
}

wid_manage::~wid_manage()
{
    delete v_login;
    delete v_friends_list;
    delete v_net;
}

bool wid_manage::init_net()
{
    return true;
}
