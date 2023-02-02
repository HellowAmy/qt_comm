#include "wid_manage.h"

wid_manage::wid_manage(QWidget *parent)
    : QObject{parent}
{
    vinit_c(vlog::e_info);

    //发送信息的网络连接
    sp_net = make_shared<net_connect>();

    //注册机
    v_register = new ms_web_client;
    v_register->open();

    //登录窗口
    v_login = new wid_login;
    v_login->show();

    //好友列表
    v_friends_list = new wid_friends_list;
    v_friends_list->close();

    v_register->func_register_back = [=](long long account,string passwd,bool ok){
        if(ok)
        {
            emit fa_show_register (QString::number(account),
                                   QString::fromStdString(passwd));
        }
        vlogw("func_register_back: " vv(account) vv(passwd) vv(ok));
    };

    connect(this,&wid_manage::fa_show_register,
            this,[=](QString account,QString passwd){
        vlogf("fa_show_register: " vv(account.toStdString()) vv(passwd.toStdString()));
        v_register->close_client();
    });

    connect(v_login,&wid_login::fa_login,
            this,[=](QString account,QString passwd){

        v_friends_list->show();
//        sp_net->open_client(account.toLongLong(),passwd.toStdString());
    });

    connect(v_login,&wid_login::fa_register_passwd,
            this,[=](QString passwd){
        if(v_register->is_connect())
            { v_register->ask_register(passwd.toStdString()); }
        vlogf("fa_register_passwd: " vv(v_register->is_connect()));
    });

    connect(sp_net.get(),&net_connect::fa_login_status,this,[=](bool ok){
        vlogf("fa_login_status: " vv(ok));
        if(ok)
        {
            v_friends_list->move(v_login->pos());
            v_friends_list->show();
            v_login->hide();
        }
    });

}

wid_manage::~wid_manage()
{
    delete v_login;
    delete v_friends_list;
    delete v_register;
}
