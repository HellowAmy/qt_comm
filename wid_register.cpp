#include "wid_register.h"

wid_register::wid_register(QWidget *parent)
    : wid_change{parent}
{
    this->resize(270,300);
    this->open_translucent();
    this->open_lessframe();
    this->open_backdrop(":/pic/pic_bake_login.png");

    //输入密码
    edit_passwd = new wid_edit(this);
    edit_passwd->set_txt_lab("密码");

    //确认输入密码
    edit_passwd_ok = new wid_edit(this);
    edit_passwd_ok->set_txt_lab("确认");

    //发送到服务器
    butt_transmit = new qt_button(this);
    butt_transmit->set_txt("发送");

    //返回
    butt_back = new qt_button(this);
    butt_back->set_txt("返回");

    qt_move_it *vec_move = new qt_move_it(this);
    vec_move->add_wid(edit_passwd);
    vec_move->add_wid(edit_passwd_ok);
    vec_move->add_wid(butt_transmit);
    vec_move->add_wid(butt_back);
    vec_move->set_vert();

    //发送申请密码
    connect(butt_transmit,&qt_button::fa_press,this,[=](){ 
        emit fa_register_passwd(edit_passwd->get_txt());
    });

    //点击返回按钮
    connect(butt_back,&qt_button::fa_press,this,&wid_register::fa_back);
}
