#ifndef WID_REGISTER_BACK_H
#define WID_REGISTER_BACK_H

#include <QObject>
#include <QWidget>
#include <QLabel>

#include "wid_change.h"
#include "wid_edit.h"
#include "qt_button.h"
#include "qt_move_it.h"
#include "lab_tips.h"

class wid_register_back : public wid_change
{
    Q_OBJECT
public:
    explicit wid_register_back(QWidget *parent = nullptr);
    void set_status(bool status,QString account = "");
signals:
    emit void fa_back();

protected:
    lab_tips *lab_title;
    lab_tips *lab_account;
    qt_button *butt_back;
};

#endif // WID_REGISTER_BACK_H
