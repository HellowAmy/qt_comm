#ifndef WID_MANAGE_H
#define WID_MANAGE_H

#include <QObject>
#include <QThread>

//#include "net_connect.h"
//#include "ms_web_client.h"
#include "wid_login.h"
#include "wid_friends_list.h"

#include "../ms_comm/ms_comm_client/net_connect.h"

//!
//! 功能:提供管理类,分别管理: 登陆界面,注册界面,好友列表,网络通信
//!     1.所有的网络反馈到界面信息都会从该类下分发
//!
class wid_manage : public QObject
{
    Q_OBJECT
public:
    explicit wid_manage(QWidget *parent = nullptr);
    ~wid_manage();
    bool init_net();

signals:
    emit void fa_show_register(QString account,QString passwd);

protected:
    wid_login *v_login;
    wid_friends_list *v_friends_list;
    net_connect *v_net;
};

#endif // WID_MANAGE_H
