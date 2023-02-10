#include "widget.h"
//#include "ui_widget.h"


//#include "wid_login.h"
//#include "wid_change.h"

//#include "wid_edit.h"

//#include "wid_register.h"

//#include "wid_friends_list.h"
//#include "wid_manage.h"

////#include "tcp_socket.h"

//#include "wid_talk.h"
#include "wid_register_back.h"

//#include "qt_area_slide.h"

//#include "wid_slide_list.h"

//#include "vlog.h"

#include "wid_dialog.h"
#include <QDialog>
//#include <QDebug>
//#define out qDebug()

#include "vts_vlog.h"

#include "wid_talk.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(600,600);
    this->show();



//    this->resize();
    wid_talk *hu = new wid_talk(this);
    hu->into_news(en_info::e_send_txt,"123456789012345678901234567890123456789012345678901234567890");
    hu->show();

//    QDialog ji;
//    ji.exec()
//    wid_dialog ji;
//    ji.exec();
//    out<< ji.get_status();

//    int hu = 100;
//    vlogf("123" vv(hu));
//    vlogd("123" vv(hu));
//    vlogw("123" vv(hu));
//    vloge("123" vv(hu));

//    ji.e

//    wid_register_back *w = new wid_register_back;
//    w->set_status(true,QString::number(1234567890));
//    w->show();

//    wid_register_back *w2 = new wid_register_back;
//    w2->set_status(false);
//    w2->show();




#if 1
    //全局管理，开启见效
//    wid_manage *wid_l=new wid_manage;
//    wid_l->
//    wid_l->hide();
#endif

    //==测试单元==

    //==测试单元==


}


