#include "wid_talk.h"

wid_talk::wid_talk(QWidget *parent)
    : wid_change{parent}
{
    this->resize(600,600);
    this->open_translucent();
    this->open_lessframe();
    this->open_backdrop(":/pic/pic_bake_talk.png");

    //输入初始化
    int space=60;
    edit_in = new qt_edit_text(this);
    edit_in->resize(this->width(),this->height()/6);
    edit_in->move(0,this->height() - edit_in->height() - space);
    edit_in->show();
    pos_lien_up = QPoint(0,this->height() - edit_in->height() - space);
    pos_lien_down = QPoint(0,this->height() - space);

    //发送到服务器
    butt_transmit = new qt_button(this);
    butt_transmit->move(this->width()-butt_transmit->width()*2,this->height() - space);
    butt_transmit->set_txt("发送");


}

void wid_talk::paintEvent(QPaintEvent *e)
{
    wid_change::paintEvent(e);

    //画两条横线标记输入位置
    QPainter *show=new QPainter(this);
    show->setPen(QPen(QColor(0x4c5765),6));
    show->drawLine(pos_lien_up,pos_lien_up + QPoint(this->width(),0));
    show->drawLine(pos_lien_down,pos_lien_down + QPoint(this->width(),0));
    show->end();
}
