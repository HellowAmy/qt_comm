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

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    wid_manage *wid_l=new wid_manage;
    wid_l->hide();

//    wid_register *wid_r=new wid_register;
//    wid_r->show();

//    wid_friends_list *wid_f=new wid_friends_list;
//    wid_f->show();

//    wid_talk *wid_t=new wid_talk;
//    wid_t->show();


    //    tcp_socket *ts=new tcp_socket(this);
    //    ts->open_socket("192.168.188.130",5005);

    //    out<<ts->get_host_ip();

//    connect(ts,&tcp_socket::fa_connect_socket,this,[=](){
//        out<<"=====ok_socket=====";
////        ts->write_word("192.168.188.100",5005,"000ahfuahskfjagfia000");


//        //传送内容信号
//        connect(ts,&tcp_socket::readyRead,[=](){
//            out<<"op: "<<ts->readAll();
//        });
//    });





}

Widget::~Widget()
{
    delete ui;
}

