#include "wid_register_back.h"

wid_register_back::wid_register_back(QWidget *parent) : wid_change(parent)
{
    this->resize(270,300);
    this->open_translucent();
    this->open_lessframe();
    this->open_backdrop(":/pic/pic_bake_login.png");

    //显示账号
    lab_account = new lab_tips(this);
    lab_account->resize(200,45);
    lab_account->setText("账号：无效申请");
    lab_account->show();

    //显示提示信息
    lab_title = new lab_tips(this);
    lab_title->resize(lab_account->size());
    lab_title->setText("<< 申请账号失败 >>");
    lab_title->show();

    //返回
    butt_back = new qt_button(this);
    butt_back->set_txt("返回");

    qt_move_it *vec_move = new qt_move_it(this);
    vec_move->add_wid(lab_title);
    vec_move->add_wid(lab_account);
    vec_move->add_wid(butt_back);
    vec_move->set_vert();

    //点击返回按钮
    connect(butt_back,&qt_button::fa_press,this,&wid_register_back::fa_back);
}

void wid_register_back::set_status(bool status, QString account)
{
    if(status)
    {
        lab_account->setText("账号："+account);
        lab_title->setText("<< 申请账号成功 >>");
    }
}
