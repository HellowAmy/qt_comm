#ifndef WID_LOGIN_H
#define WID_LOGIN_H

#include <QWidget>

#include "c_define.h"
#include "wid_change.h"
#include "wid_edit.h"
#include "qt_button.h"
#include "qt_move_it.h"
#include "wid_register.h"

class wid_login : public wid_change
{
    Q_OBJECT
public:
    explicit wid_login(QWidget *parent = nullptr);

    //（参数1：传入请求连接信号发送值）（参数2：返回的账号）（参数3：返回的密码）
    //（返回值：是否可以连接）
    bool return_detail(QString detail,QString &account,QString &passwd);

signals:
    emit void fa_info(QString str);//请求连接信号——封装格式: #账号#密码#是否可连接#

protected:
    wid_edit *edit_account;
    wid_edit *edit_passwd;
    qt_button *butt_login;
    qt_button *butt_close;
    qt_button *butt_new;

    wid_register *v_reginster;
};

#endif // WID_LOGIN_H
