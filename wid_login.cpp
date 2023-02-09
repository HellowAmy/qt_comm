#include "wid_login.h"


#include <QDebug>
#define out qDebug()

wid_login::wid_login(QWidget *parent)
    : wid_change{parent}
{
    this->resize(270,300);
    this->open_translucent();
    this->open_lessframe();
    this->open_backdrop(":/pic/pic_bake_login.png");

    //显示成功注册的账号
    v_register_back = new wid_register_back;
    v_register_back->hide();

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
    butt_register = new qt_button(this);
    butt_register->set_txt("注册账号");

    //关闭位置
    butt_close = new qt_button(this);
    butt_close->set_txt("关闭");

    //添加到自动布局
    qt_move_it *vec_move = new qt_move_it(this);
    vec_move->add_wid(edit_account);
    vec_move->add_wid(edit_passwd);
    vec_move->add_wid(butt_login);
    vec_move->add_wid(butt_register);
    vec_move->add_wid(butt_close);
    vec_move->set_vert();

    //注册窗口返回
    connect(v_reginster,&wid_register::fa_back,this,[=](){
        this->move(v_reginster->pos());
        this->show();
        v_reginster->close();
    });

    //注册密码
    connect(v_reginster,&wid_register::fa_register,
            this,[=](QString passwd){
        emit fa_register(passwd.toStdString());
    });

    //点击登陆
    connect(butt_login,&qt_button::fa_press,this,[=](){
        emit fa_login(edit_account->get_txt().toLongLong(),edit_passwd->get_txt().toStdString());
    });

    //进入注册界面
    connect(butt_register,&qt_button::fa_press,this,[=](){
        v_reginster->move(this->pos());
        v_reginster->show();
        this->close();
    });

    //关闭反馈界面
    connect(v_register_back,&wid_register_back::fa_back,this,[=](){
//        this->fa_back();
        this->move(v_register_back->pos());
        this->show();
        v_register_back->close();

//        butt_close->fa_press();
//        v_register_back->close();
    });

    connect(butt_close,&qt_button::fa_press,this,&QWidget::close);//关闭窗口

}

void wid_login::show_register_back(bool is_success, long long account)
{
    v_reginster->close();
    v_register_back->move(v_reginster->pos());
    v_register_back->set_status(is_success,QString::number(account));
    v_register_back->show();
}

wid_login::~wid_login()
{
    delete v_reginster;
}
