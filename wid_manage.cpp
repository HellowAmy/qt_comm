#include "wid_manage.h"

#include <QTimer>

wid_manage::wid_manage(QWidget *parent)
    : QObject{parent}
{
    v_login = new wid_login;//登录窗口
    v_login->show();

    v_friends_list = new wid_friends_list;//好友列表
    v_friends_list->close();


    QVector<ct_friends_info> vec;
    vec.push_back(ct_friends_info{1256757890,"ty1256757890"});
    vec.push_back(ct_friends_info{1251251890,"t212y1251251890"});
    vec.push_back(ct_friends_info{1212471890,"1212471890"});
    vec.push_back(ct_friends_info{3456757890,"阿uh"});
    vec.push_back(ct_friends_info{6786757890,"阿角色大赛的"});
    vec.push_back(ct_friends_info{1256757890,"4574"});
    vec.push_back(ct_friends_info{8568464564,"3498斯蒂芬"});


    //发送--发送到网络//========================
    connect(v_friends_list,&wid_friends_list::fa_send_news,this,
            [=](en_info en,long long account,string txt){
        if(en == en_info::e_send_txt)
        {
            vlogf("en_info" vv(account) vv(txt));
        }
    });

    //发送--发送到网络//========================
    connect(v_login,&wid_login::fa_login,this,[=](long long account,string passwd){
        vlogf("en_info" vv(account) vv(passwd));

        QTimer::singleShot(1000,this,[=](){
            v_friends_list->move(v_login->pos());
            v_friends_list->show();
            v_friends_list->set_friends(vec);
            v_login->close();
        });
    });

    //网络返回--注册//========================
    connect(v_login,&wid_login::fa_register,this,[=](string passwd){
        vlogf(vv(passwd));
        QTimer::singleShot(1000,this,[=](){
            v_login->show_register_back(true,1234567890);
        });
    });
}

wid_manage::~wid_manage()
{
    delete v_login;
    delete v_friends_list;
}

bool wid_manage::init_net()
{


    return true;
}
