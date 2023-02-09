#ifndef WID_DIALOG_H
#define WID_DIALOG_H

//#include <QWidget>
#include <QDialog>
#include "wid_change.h"
#include "qt_button.h"
#include "lab_tips.h"

class wid_dialog : public QDialog
{
    Q_OBJECT
public:
    explicit wid_dialog(QString info = "提示",int wide = 400,QWidget *parent = nullptr);
    bool get_status();

signals:
    emit void fa_back(bool is_ok);

protected:
    lab_tips *lab_info;
    qt_button *butt_ok;
    qt_button *butt_cancel;

    bool is_ok = false;
};

#endif // WID_DIALOG_H
