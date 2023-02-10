#include "wid_register.h"

wid_register::wid_register(QWidget *parent)
    : wid_change{parent}
{
    this->resize(270,300);
    this->open_translucent();
    this->open_lessframe();
    this->open_backdrop(":/pic/pic_bake_login.png");

    //输入昵称
    edit_name = new wid_edit(this);
    edit_name->set_txt_lab("昵称");

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
    vec_move->add_wid(edit_name);
    vec_move->add_wid(edit_passwd);
    vec_move->add_wid(edit_passwd_ok);
    vec_move->add_wid(butt_transmit);
    vec_move->add_wid(butt_back);
    vec_move->set_vert();

    //发送申请密码
    connect(butt_transmit,&qt_button::fa_press,this,[=](){ 
        if(edit_passwd_ok->get_txt() == edit_passwd->get_txt())
        {
            if(is_valid(edit_passwd_ok->get_txt()) == false)
                wid_dialog("限制:不能输入'#',或者密码过长").exec();
            else emit fa_register(edit_name->get_txt(),edit_passwd->get_txt());
        }
        else { wid_dialog("输入的密码不一致").exec(); }
    });

    //点击返回按钮
    connect(butt_back,&qt_button::fa_press,this,&wid_register::fa_back);
}

bool wid_register::is_valid(QString str)
{
    if(str.size() > 60) return false;
    for(const auto &a:str)
    { if(a == '#') return false; }
    return true;
}
