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


    QMap<long long,string> map;
    map.insert(1256757890,"ty1256757890");
    map.insert(1251251890,"t212y1251251890");
    map.insert(1212471890,"1212471890");
    map.insert(3456757890,"阿uh");
    map.insert(6786757890,"阿角色大赛的");
    map.insert(1256757890,"4574");
    map.insert(8568464564,"3498斯蒂芬");


    //发送--发送到网络//========================
    connect(v_friends_list,&wid_friends_list::fa_send_news,this,
            [=](en_info en,long long account,string txt){
        if(en == en_info::e_send_txt)
        {
            vlogf("en_info" vv(account) vv(txt));



            QTimer::singleShot(500,this,[=](){
                v_friends_list->into_news(en_info::e_send_txt,account,"你好吗？");
            });
        }
        else if(en == en_info::e_send_pic)
        {
            vlogf("en_info" vv(account) vv(txt));


            QTimer::singleShot(500,this,[=](){
                v_friends_list->into_news(en_info::e_send_pic,account,QString::fromStdString(txt));
            });
        }
        else if(en == en_info::e_send_file)
        {

            vlogf("en_info" vv(account) vv(txt));


            QTimer::singleShot(500,this,[=](){
                v_friends_list->into_news(en_info::e_send_file,account,QString::fromStdString(txt));
            });
        }
    });

    //发送--发送到网络//========================
    connect(v_login,&wid_login::fa_login,this,[=](long long account,string passwd){
        //记录登陆信息
        v_account = account;
        v_passwd = passwd;
        vlogf("en_info" vv(v_account) vv(v_passwd));


        //登陆成功：隐藏登陆窗口，显示好友列表
        //登陆失败：失败提示，返回到登陆窗口
        QTimer::singleShot(500,this,[=](){
            v_friends_list->move(v_login->pos());
            v_friends_list->show();
            v_friends_list->into_friends(map);
            v_login->close();
        });
    });

    //网络返回--注册//========================
    connect(v_login,&wid_login::fa_register,this,
            [=](string name,string passwd){
        vlogf(vv(passwd));
        vlogf(vv(name));


        QTimer::singleShot(500,this,[=](){
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
