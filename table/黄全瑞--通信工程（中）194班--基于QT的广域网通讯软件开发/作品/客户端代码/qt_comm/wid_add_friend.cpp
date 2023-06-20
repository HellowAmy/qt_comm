#include "wid_add_friend.h"

wid_add_friend::wid_add_friend(QWidget *parent) : wid_change(parent)
{
    this->resize(270,300);
    this->open_translucent();
    this->open_lessframe();
    this->open_backdrop(":/pic/pic_bake_login.png");

    edit_account_from = new wid_edit(this);
    edit_account_from->setEnabled(false);
    edit_account_from->set_txt_lab("账号");

    edit_add_friend = new wid_edit(this);
    edit_add_friend->set_txt_lab("添加");
    edit_add_friend->set_txt("");

    //确定添加
    butt_send = new qt_button(this);
    butt_send->set_txt("发送");

    //关闭位置
    butt_close = new qt_button(this);
    butt_close->set_txt("关闭");

    //添加到自动布局
    qt_move_it *vec_move = new qt_move_it(this);
    vec_move->add_wid(edit_account_from);
    vec_move->add_wid(edit_add_friend);
    vec_move->add_wid(butt_send);
    vec_move->add_wid(butt_close);
    vec_move->set_vert();

    //点击发送
    connect(butt_send,&qt_button::fa_press,this,[=](){
        if(edit_add_friend->get_txt().size() == 10)
        {
            wid_dialog temp("确认请求添加的好友: "+edit_add_friend->get_txt());
            temp.exec();
            if(temp.get_status())
            { emit fa_add_friend(edit_add_friend->get_txt().toLongLong()); }
            butt_close->fa_press();
        }
        else { wid_dialog temp("请输入正确的账号"); temp.exec(); }
    });

    connect(butt_close,&qt_button::fa_press,this,&QWidget::close);//关闭窗口
}

void wid_add_friend::set_account(long long account)
{
    edit_account_from->set_txt(QString::number(account));

}
