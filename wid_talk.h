#ifndef WID_TALK_H
#define WID_TALK_H

#include <QWidget>
#include <QTextEdit>
#include <QPalette>
#include <QLabel>
#include <QThread>

#include "wid_change.h"
#include "qt_edit_text.h"
#include "qt_button.h"
#include "wid_slide_list.h"

class wid_talk : public wid_change
{
    Q_OBJECT
public:
    explicit wid_talk(QWidget *parent = nullptr);

signals:

protected:
    qt_edit_text *edit_in;
    qt_button *butt_transmit;
    wid_slide_list *wid_show;

    QPoint pos_lien_up;
    QPoint pos_lien_down;
    void paintEvent(QPaintEvent *event) override;

    void send_word();



};

#endif // WID_TALK_H
