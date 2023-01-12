#include "wid_login.h"

wid_login::wid_login(QWidget *parent)
    : wid_change{parent}
{
    this->resize(270,300);
    this->open_translucent();
    this->open_lessframe();
    this->open_backdrop(":/pic/pic_bake_login.png");

    //注册窗口
    v_reginster = new wid_register;
    v_reginster->hide();

    //账号位置
    edit_account = new wid_edit(this);
    edit_account->set_txt_lab("账号");

    //密码位置
    edit_passwd = new wid_edit(this);
    edit_passwd->set_passwd(true);
    edit_passwd->set_size(10);
    edit_passwd->set_txt_lab("密码");

    //登录位置
    butt_login = new qt_button(this);
    butt_login->set_txt("登录");

    //注册位置
    butt_new = new qt_button(this);
    butt_new->set_txt("注册账号");

    //关闭位置
    butt_close = new qt_button(this);
    butt_close->set_txt("关闭");

    //添加到自动布局
    qt_move_it *vec_move = new qt_move_it(this);
    vec_move->add_wid(edit_account);
    vec_move->add_wid(edit_passwd);
    vec_move->add_wid(butt_login);
    vec_move->add_wid(butt_new);
    vec_move->add_wid(butt_close);
    vec_move->set_vert();

    //注册窗口返回
    connect(v_reginster,&wid_register::fa_back,this,[=](){
        this->move(v_reginster->pos());
        this->show();
        v_reginster->close();
    });

    //注册密码
    connect(v_reginster,&wid_register::fa_register_passwd,
            this,&wid_login::fa_register_passwd);

    connect(butt_login,&qt_button::fa_press,this,[=](){
        emit fa_login(edit_account->get_txt(),edit_passwd->get_txt());
    });

    //进入注册界面
    connect(butt_new,&qt_button::fa_press,this,[=](){
        v_reginster->move(this->pos());
        v_reginster->show();
        this->hide();
    });

    //关闭窗口
    connect(butt_close,&qt_button::fa_press,this,&QWidget::close);
}

wid_login::~wid_login()
{
    delete v_reginster;
}
