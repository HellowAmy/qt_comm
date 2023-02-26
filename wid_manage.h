#ifndef WID_MANAGE_H
#define WID_MANAGE_H

#include <QObject>
#include <QThread>
#include <QTimer>

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
    int init_net();
    ~wid_manage();

signals:
    emit void fa_show_register(QString account,QString passwd);

protected:
    wid_login *v_login;
    wid_friends_list *v_friends_list;
    net_connect *v_net;
    QString ip = "127.0.0.1";
    int port = 5005;
};

#endif // WID_MANAGE_H
