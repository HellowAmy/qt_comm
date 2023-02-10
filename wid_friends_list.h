#ifndef WID_FRIENDS_LIST_H
#define WID_FRIENDS_LIST_H

#include <QWidget>
#include <QScrollArea>
#include <QPicture>
#include <QPen>
#include <QMap>
#include <QSet>

//#include "net_connect.h"
#include "wid_change.h"
#include "wid_edit.h"
#include "qt_button.h"
#include "qt_move_it.h"
#include "qt_butt_friend.h"
//#include "c_define.h"
#include "qt_area_slide.h"
#include "wid_talk.h"

#include <string>
using std::string;


struct ct_friends_info
{
    long long account;//账号
    string name;//昵称
};

struct ct_friends_index
{
    qt_button* butt;//按钮
    wid_talk* wid;//按钮的对应窗口
};

//!
//! \brief The wid_friends_list class
//! 功能:登陆成功之后的好友显示窗口,点击好友按钮可以显示聊天窗口
//!     1.提供map_wid_talk存放按钮和对应窗口的映射
//!
class wid_friends_list : public wid_change
{
    Q_OBJECT
public:
    explicit wid_friends_list(QWidget *parent = nullptr);
    ~wid_friends_list();

    //将容器内昵称转为按钮
    //（参数1：昵称容器）
    void into_friends(QMap<long long,string> map);
    void into_news(en_info en,long long account,QString info);

signals:
    emit void fa_send_news(en_info en,long long account,string txt);

protected:
    QMap<long long,ct_friends_index> map_wid_talk;
    QWidget *wid_slide;
    qt_area_slide *area;
    qt_button *butt_close;

//    shared_ptr<net_connect> sp_net;

    int v_wide=250;
    int v_high=600;
    int v_less=100;
};

#endif // WID_FRIENDS_LIST_H
