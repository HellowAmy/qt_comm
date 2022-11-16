#include "tcp_socket.h"

#include "vlog.h"

tcp_socket::tcp_socket(QObject *parent)
    : QTcpSocket{parent}
{
    //===== 接收函数登记 =====
    //账号注册函数
    map_func.insert(enum_transmit::e_register_back,
                    &tcp_socket::back_register);

    //账号登录反馈
    map_func.insert(enum_transmit::e_login_back,
                    &tcp_socket::back_login);

    //===== 接收函数登记 =====
}

void tcp_socket::open_socket(QString IP, int port)
{
    this->connectToHost(IP,port);//寻找连接对象
    recv_news();//准备读取函数
}

bool tcp_socket::send_register(const char *passwd)
{
    bool is_ok = false;

    if(this->state() == QAbstractSocket::ConnectedState)
    {
        out<<"发送请求--注册账号";

        //先发送协议包头再发送协议类型
        ct_cmd cmd;
        cmd.type = enum_transmit::e_register;

        ct_register ct;
        memset(&ct,0,sizeof(ct));
        strncpy(ct.passwd,passwd,sizeof(ct.passwd));

        this->write((const char*)&cmd,sizeof(cmd));
        this->write((const char*)&ct,sizeof(ct));
        this->flush();
        is_ok = true;
    }

    return is_ok;
}

bool tcp_socket::send_login(long long account, const char *passwd)
{
    bool is_ok = false;

    if(this->state() == QAbstractSocket::ConnectedState)
    {
        out<<"发送请求--账号登录";

        //先发送协议包头再发送协议类型
        ct_cmd cmd;
        cmd.type = enum_transmit::e_login;

        ct_login ct;
        memset(&ct,0,sizeof(ct));
        strncpy(ct.passwd,passwd,sizeof(ct.passwd));
        ct.account = account;

        this->write((const char*)&cmd,sizeof(cmd));
        this->write((const char*)&ct,sizeof(ct));
        this->flush();
        is_ok = true;
    }

    return is_ok;
}

bool tcp_socket::send_logout(long long account)
{
    bool is_ok = false;

    if(this->state() == QAbstractSocket::ConnectedState)
    {
        out<<"发送请求--退出账号";

        //先发送协议包头再发送协议类型
        ct_cmd cmd;
        cmd.type = enum_transmit::e_logout;

        ct_logout ct;
        ct.account = account;

        this->write((const char*)&cmd,sizeof(cmd));
        this->write((const char*)&ct,sizeof(ct));
        this->flush();
        is_ok = true;
    }

    return is_ok;
}

void tcp_socket::recv_news()
{
    //传送内容信号
    connect(this,&tcp_socket::readyRead,[=](){
        
        //循环接收所有包体
        while(this->size())
        {
            static ct_cmd cmd;
            static bool is_head = true;//判断本次为包头

            //拆包头--分析对应类型
            if(is_head)
            {
                is_head = false;
                int size = this->read((char*)&cmd,sizeof(cmd));
                if(size != sizeof(cmd)) is_head = true;

                out<<"[in]包头解析--读取结束状态:"<<is_head
                    <<" | 类型: "<<cmd.type;
            }
            else//分析类型
            {
                auto it_find = map_func.find((enum_transmit)cmd.type);

                //执行接收函数
                if(it_find != map_func.end())
                {
                    auto ptr = it_find.value();
                    is_head = (this->*ptr)();
                    out<<"[out]接收函数执行--读取结束状态:"<<is_head<<endl;
                }
                else
                {
                    out<<"查找匹配函数失败";
                    this->readAll();
                }
            }
        }

    });
}

bool tcp_socket::back_register()
{
    bool is_end = true;

    out<<"进入接收函数--注册账号";
    ct_register_back ct_back;
    memset(&ct_back,0,sizeof (ct_back));
    int size = this->read((char*)&ct_back,sizeof(ct_back));

    if(size > 0)
    {
        out<<"接收状态--成功";
        QString str_passwd;
        str_passwd = ct_back.passwd;
        emit fa_back_register(ct_back.account,str_passwd);
    }
    else out<<"接收状态--失败";

    return is_end;
}

bool tcp_socket::back_login()
{
    bool is_end = true;

    out<<"进入接收函数--账号登录";
    ct_login_back ct_back;
    memset(&ct_back,0,sizeof (ct_back));
    int size = this->read((char*)&ct_back,sizeof(ct_back));

    if(size > 0)
    {
        out<<"接收状态--成功";
        QString str_info;
        str_info = ct_back.info;
        emit fa_back_login(ct_back.flg,str_info);
    }
    else out<<"接收状态--失败";

    return is_end;
}
