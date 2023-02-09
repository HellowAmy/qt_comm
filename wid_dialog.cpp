#include "wid_dialog.h"

wid_dialog::wid_dialog(QString info,int wide,QWidget *parent) : QDialog(parent)
{
    int space = 10;
    int high = 170;
    this->setFixedSize(wide,high);
    QPalette palette;
    palette.setColor(QPalette::Window,QColor(230,200,160));//255,255,200
    this->setPalette(palette);

    //显示账号
    lab_info = new lab_tips(this,Qt::red);
    lab_info->move(space,space);
    lab_info->resize(wide-space*2,high/2);
    lab_info->setText(info);
    lab_info->show();

    butt_ok = new qt_button(this);
    butt_ok->show();
    butt_ok->move(wide/2 - butt_ok->width() - space,high/2 + space*2);
    butt_ok->set_txt("确认");

    butt_cancel = new qt_button(this);
    butt_cancel->show();
    butt_cancel->move(wide/2 + space,high/2 + space*2);
    butt_cancel->set_txt("取消");

    connect(butt_ok,&qt_button::fa_press,this,[=](){
        is_ok = true;
        emit fa_back(is_ok);
        this->close();
    });
    connect(butt_cancel,&qt_button::fa_press,this,[=](){
        is_ok = false;
        emit fa_back(false);
        this->close();
    });
}

bool wid_dialog::get_status()
{ return is_ok; }

