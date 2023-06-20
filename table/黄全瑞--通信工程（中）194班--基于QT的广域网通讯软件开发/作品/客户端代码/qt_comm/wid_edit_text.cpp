#include "wid_edit_text.h"

wid_edit_text::wid_edit_text(QWidget *parent)
    : QWidget{parent}
{
    edit_in = new qt_edit_text(this);
    lab_round = new QLabel(this);

    this->setWindowFlag(Qt::FramelessWindowHint);//无边框
    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明



}

void wid_edit_text::open_edit()
{
    lab_round->resize(this->size());
    lab_round->setAttribute(Qt::WA_TransparentForMouseEvents);//鼠标穿透
    lab_round->setWindowFlag(Qt::FramelessWindowHint);//无边框
    lab_round->setAttribute(Qt::WA_TranslucentBackground);//背景透明

    edit_in->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏横向滚动条
    edit_in->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏竖向滚动条

    QPicture pic;
    pic.setBoundingRect(lab_round->rect());

    QPainter show(&pic);
    show.setRenderHint(QPainter::Antialiasing);

    int v_space = 5;
    QRect rect(v_space,v_space,this->width()-v_space-1,this->height()-v_space-1);
    QRect rect2(v_space*2,v_space*2,this->width()-v_space*3-1,this->height()-v_space*3-1);
    show.drawRoundedRect(rect,10,40,Qt::RelativeSize);
    show.drawRoundedRect(rect2,10,40,Qt::RelativeSize);

    lab_round->move(-2,-2);
    lab_round->setPicture(pic);

    lab_round->hide();
    edit_in->show();

    edit_in->move(v_space*2,v_space*5);
    edit_in->resize(this->width(),this->width()-20);






//        lab_round = new QLabel(this);
    //    lab_round->resize(this->size());
    //    lab_round->setAttribute(Qt::WA_TransparentForMouseEvents);//鼠标穿透
    ////    lab_round->setWindowFlag(Qt::FramelessWindowHint);//无边框
    ////    lab_round->setAttribute(Qt::WA_TranslucentBackground);//背景透明
    //    lab_round->setFrameShape(QFrame::Box);


    //    QPicture *pic = new QPicture;
    //    pic->setBoundingRect(lab_round->rect());



    //    QPainter *show = new QPainter(pic);


    //    QPainter *show=new QPainter(this);
    //    int v_space = 5;
    ////    show->setPen(v_pen);
    //    show->setRenderHint(QPainter::Antialiasing);
    //    QRect rect(v_space,v_space,this->width()-v_space-1,this->height()-v_space-1);
    //    QRect rect2(v_space*2,v_space*2,this->width()-v_space*3-1,this->height()-v_space*3-1);

    //    //设置窗口圆角，百分比
    //    show->drawRoundedRect(rect,10,10,Qt::RelativeSize);
    //    show->drawRoundedRect(rect2,10,10,Qt::RelativeSize);

    //    lab_round->setPicture(*pic);
    //    lab_round->show();

}
