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

enum en_info
{
    e_send_txt,
    e_send_file
};

//!
//! \brief The wid_talk class
//! 功能说明：
//!     1.该窗口统一输入时显示两个区域，显示区域负责保存历史内容，
//!     2.输入区域将内容面板压入显示界面，显示界面只负责排版
//!     3.内容利用qt_news类承载信息
//!
class wid_talk : public wid_change
{
    Q_OBJECT
public:
    explicit wid_talk(QWidget *parent = nullptr);
    void set_info(long long account,QString title);
    long long get_account();

signals:
    emit void fa_send_news(en_info en,long long account,QString txt);

protected:
    long long v_account;
    QLabel *lab_title;
    qt_button *butt_transmit;
    qt_button *butt_hide;

    qt_edit_text *edit_in;//输入区域
    wid_slide_list *wid_show;//显示区域

    QPoint pos_lien_up;
    QPoint pos_lien_down;
    void paintEvent(QPaintEvent *event) override;

    void send_word();//发送到显示区域
};

#endif // WID_TALK_H
