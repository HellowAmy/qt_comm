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
#include "qt_area_slide.h"

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
    QVector<qt_button *>vec_butt;
    QWidget *wid_slide;
    qt_area_slide *area;
    qt_button *butt_close;

    int v_wide=250;
    int v_high=600;
    int v_less=100;

};

#endif // WID_FRIENDS_LIST_H
