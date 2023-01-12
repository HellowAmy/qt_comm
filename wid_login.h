#ifndef WID_LOGIN_H
#define WID_LOGIN_H

#include <QWidget>

//#include "c_define.h"
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
    ~wid_login();

signals:
    emit void fa_login(QString account,QString passwd);
    emit void fa_register_passwd(QString passwd);

protected:
    wid_edit *edit_account;
    wid_edit *edit_passwd;
    qt_button *butt_login;
    qt_button *butt_close;
    qt_button *butt_new;

    wid_register *v_reginster;
};

#endif // WID_LOGIN_H
