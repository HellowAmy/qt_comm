#ifndef WID_FRIENDS_LIST_H
#define WID_FRIENDS_LIST_H

#include <QWidget>
#include <QScrollArea>
#include <QPicture>
#include <QPen>

#include "wid_change.h"
#include "wid_edit.h"
#include "qt_button.h"
#include "qt_move_it.h"
#include "qt_butt_friend.h"
#include "c_define.h"

class wid_friends_list : public wid_change
{
    Q_OBJECT
public:
    explicit wid_friends_list(QWidget *parent = nullptr);

    //将容器内昵称转为按钮
    //（参数1：昵称容器）
    void set_friends(QVector<QString> vec_str);

signals:

protected:
    //滑动区
    QScrollArea *area;
    QWidget *wid_temp;

    qt_button *butt_close;//关闭按钮

    QVector<qt_button *>vec_butt;//按钮容器
    int v_wide=250;
    int v_high=600;
    int v_less=100;

};

#endif // WID_FRIENDS_LIST_H
