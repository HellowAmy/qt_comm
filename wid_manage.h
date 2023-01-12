#ifndef WID_MANAGE_H
#define WID_MANAGE_H

#include <QObject>

#include "net_connect.h"
#include "ms_web_client.h"
#include "wid_login.h"
#include "wid_friends_list.h"

#include <memory>

using std::shared_ptr;
using std::make_shared;
using vts::vlog;

class wid_manage : public QObject
{
    Q_OBJECT
public:
    explicit wid_manage(QWidget *parent = nullptr);
    ~wid_manage();

signals:
    emit void fa_show_register(QString account,QString passwd);

protected:
    wid_login *v_login;
    wid_friends_list *v_friends_list;
    ms_web_client *v_register;
    shared_ptr<net_connect> sp_net;

};

#endif // WID_MANAGE_H
