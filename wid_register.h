#ifndef WID_REGISTER_H
#define WID_REGISTER_H

#include <QWidget>
#include <QLabel>

#include "wid_change.h"
#include "wid_edit.h"
#include "qt_button.h"
#include "qt_move_it.h"

class wid_register : public wid_change
{
    Q_OBJECT
public:
    explicit wid_register(QWidget *parent = nullptr);

signals:
    emit void fa_back();

protected:
    QLabel *lab_account;
    wid_edit *edit_passwd;
    wid_edit *edit_passwd_ok;
    qt_button *butt_transmit;
    qt_button *butt_back;
};

#endif // WID_REGISTER_H
