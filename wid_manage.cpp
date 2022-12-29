#include "wid_manage.h"

wid_manage::wid_manage(QWidget *parent)
    : QObject{parent}
{
    //登录窗口
    v_login = new wid_login;
    v_login->show();

    //好友列表
    v_friends_list = new wid_friends_list;
    v_friends_list->close();


    connect(v_login,&wid_login::fa_info,this,[=](QString str){
        //测试==============
        QString account;
        QString passwd;
        bool is_ok=v_login->return_detail(str,account,passwd);

        if(is_ok)
        {
            v_friends_list->move(v_login->pos());
            v_friends_list->show();
            v_login->close();
        }

//        out<<":"<<account<<passwd<<is_ok;
        //测试==============

    });

}

wid_manage::~wid_manage()
{
    delete v_login;
    delete v_friends_list;
}
