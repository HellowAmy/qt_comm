#include "qt_butt_friend.h"

qt_butt_friend::qt_butt_friend(QWidget *parent)
    : qt_button{parent}
{

}

void qt_butt_friend::set_back(QString pic)
{
    pic_bake=pic;
}

void qt_butt_friend::paintEvent(QPaintEvent *e)
{


    QPainter *show=new QPainter(this);
    show->drawPixmap(0,0,QPixmap(pic_bake));
    show->end();

    qt_button::paintEvent(e);
//    show->setPen(v_pen);
//    show->setRenderHint(QPainter::Antialiasing);
//    QRect rect(v_space,v_space,this->width()-v_space-1,this->height()-v_space-1);
//    QRect rect2(v_space*2,v_space*2,this->width()-v_space*3-1,this->height()-v_space*3-1);
//    show->drawRoundedRect(rect,50,50,Qt::RelativeSize);
//    show->drawRoundedRect(rect2,50,50,Qt::RelativeSize);
//    show->drawText(this->rect(),Qt::AlignCenter,v_txt);

}
