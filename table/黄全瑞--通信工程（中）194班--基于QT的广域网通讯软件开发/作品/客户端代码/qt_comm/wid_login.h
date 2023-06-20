#ifndef WID_LOGIN_H
#define WID_LOGIN_H

#include <QWidget>

#include "wid_change.h"
#include "wid_edit.h"
#include "qt_button.h"
#include "qt_move_it.h"
#include "wid_register.h"
#include "wid_register_back.h"

#include <string>
using std::string;

//!
//! 功能:提供账号密码一个登陆界面
//!
class wid_login : public wid_change
{
    Q_OBJECT
public:
    explicit wid_login(QWidget *parent = nullptr);
    void show_register_back(bool is_success,long long account);
    ~wid_login();

signals:
    emit void fa_login(long long account,QString passwd);
    emit void fa_register(QString name,QString passwd);
    emit void fa_back();

protected:
    wid_edit *edit_account;
    wid_edit *edit_passwd;

    qt_button *butt_login;
    qt_button *butt_register;
    qt_button *butt_close;

    wid_register_back *v_register_back;
    wid_register *v_reginster;
};

#endif // WID_LOGIN_H
