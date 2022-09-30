#ifndef WID_EDIT_TEXT_H
#define WID_EDIT_TEXT_H

#include <QWidget>
#include <QLabel>

#include "qt_edit_text.h"

class wid_edit_text : public QWidget
{
    Q_OBJECT
public:
    explicit wid_edit_text(QWidget *parent = nullptr);
    void open_edit();

signals:

protected:
    qt_edit_text *edit_in;

    QLabel *lab_round;



};

#endif // WID_EDIT_TEXT_H
