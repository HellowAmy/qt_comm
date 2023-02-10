#ifndef WID_REGISTER_H
#define WID_REGISTER_H

#include <QWidget>
#include <QLabel>

#include "wid_dialog.h"
#include "wid_change.h"
#include "wid_edit.h"
#include "qt_button.h"
#include "qt_move_it.h"

//!
//! 功能:提供一个账号注册界面
//!
class wid_register : public wid_change
{
    Q_OBJECT
public:
    explicit wid_register(QWidget *parent = nullptr);

signals:
    emit void fa_back();
    emit void fa_register(QString name,QString passwd);

protected:
    wid_edit *edit_name;
    wid_edit *edit_passwd;
    wid_edit *edit_passwd_ok;
    qt_button *butt_transmit;
    qt_button *butt_back;

    //限制:不能输入"#"符号,或者密码过长(超过60位)
    bool is_valid(QString str);

};

#endif // WID_REGISTER_H
