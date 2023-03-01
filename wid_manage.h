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

protected:
    wid_login *v_login;                 //登陆窗口
    wid_friends_list *v_friends_list;   //好友列表窗口
    net_connect *v_net;                 //客户端网络连接接口
    QString ip = "127.0.0.1"; //实际连接到云服务器：139.159.196.60
    int port = 5005;
};

#endif // WID_MANAGE_H
