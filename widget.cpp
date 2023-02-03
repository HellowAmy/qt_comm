#include "widget.h"
#include "ui_widget.h"


#include "wid_login.h"
#include "wid_change.h"

#include "wid_edit.h"

#include "wid_register.h"

#include "wid_friends_list.h"
#include "wid_manage.h"

#include "tcp_socket.h"

#include "wid_talk.h"
#include "wid_register_back.h"

#include "qt_area_slide.h"

#include "wid_slide_list.h"

#include "vlog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    wid_register_back *w = new wid_register_back;
    w->set_status(true,QString::number(1234567890));
    w->show();

    wid_register_back *w2 = new wid_register_back;
    w2->set_status(false);
    w2->show();




#if 1
    //全局管理，开启见效
//    wid_manage *wid_l=new wid_manage;
//    wid_l->
//    wid_l->hide();
#endif

    //==测试单元==

    //==测试单元==


}


