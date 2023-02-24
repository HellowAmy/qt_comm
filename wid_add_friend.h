#ifndef WID_ADD_FRIEND_H
#define WID_ADD_FRIEND_H

#include <QWidget>

#include "wid_dialog.h"
#include "wid_change.h"
#include "wid_edit.h"
#include "qt_button.h"
#include "qt_move_it.h"

//!
//! 功能:添加好友的窗口，提供好友账号的输入
//!
class wid_add_friend : public wid_change
{
    Q_OBJECT
public:
    explicit wid_add_friend(QWidget *parent = nullptr);
    void set_account(long long account);

signals:
    emit void fa_add_friend(long long account);
    emit void fa_back();

protected:
    wid_edit *edit_account_from;
    wid_edit *edit_add_friend;

    qt_button *butt_send;
    qt_button *butt_close;
};

#endif // WID_ADD_FRIEND_H
