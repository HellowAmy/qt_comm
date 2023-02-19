#include "widget.h"
//#include "ui_widget.h"


//#include "wid_login.h"
//#include "wid_change.h"

//#include "wid_edit.h"

//#include "wid_register.h"

#include "wid_friends_list.h"
//#include "wid_manage.h"

////#include "tcp_socket.h"

//#include "wid_talk.h"
#include "wid_register_back.h"
#include "wid_add_friend.h"

//#include "qt_area_slide.h"

//#include "wid_slide_list.h"

//#include "vlog.h"

#include "wid_dialog.h"
#include <QDialog>
//#include <QDebug>
//#define out qDebug()

#include "vts_vlog.h"

#include "wid_add_friend.h"
#include "wid_talk.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{



#if 0
    //测试:好友申请
    wid_add_friend *tm = new wid_add_friend;
    tm->set_account(1234567890);
    tm->show();
#endif

#if 1
    //测试:好友列表
    wid_friends_list *tm = new wid_friends_list;
    QMap<long long,string> map;
    map.insert(1234567890,"1234567890");
    map.insert(1234567891,"1234567891");
    map.insert(1234567892,"1234567892");
    map.insert(1234567893,"1234567893");
    map.insert(1234567894,"1234567894");
    map.insert(1234567895,"1234567895");
    map.insert(1234567896,"1234567896");
    map.insert(1234567897,"1234567897");
    map.insert(1234567898,"1234567898");
    map.insert(1234567899,"1234567899");
    tm->into_friends(map);
    tm->set_account(1234567897);
    tm->show();
#endif


//    this->resize(600,600);
//    this->show();


    //==测试单元==

    //==测试单元==




//    this->resize();
//    wid_talk *hu = new wid_talk(this);
//    hu->into_news(en_info::e_send_txt,"123456789012345678901234567890123456789012345678901234567890");
//    hu->show();



}


