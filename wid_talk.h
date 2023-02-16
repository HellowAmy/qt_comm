#ifndef WID_TALK_H
#define WID_TALK_H

#include <QWidget>
#include <QTextEdit>
#include <QPalette>
#include <QLabel>
#include <QThread>
#include <QDropEvent>
#include <QMimeData>
#include <QList>
#include <QFileDialog>

#include "wid_change.h"
#include "qt_edit_text.h"
#include "qt_button.h"
#include "wid_slide_list.h"

#include <functional>
using std::function;
using std::bind;
using std::placeholders::_1;

//传输信息类型
enum en_info
{
    e_send_txt,
    e_send_pic,
    e_send_file,
<<<<<<< HEAD
    e_send_file_prog,
=======
    e_send_file_ask,
    e_send_file_back,
    e_send_file_prog
>>>>>>> 2d0c690d5ed9e13c44ab5cf3ada654702d0712d0
};

//!
//! \brief The wid_talk class
//! 功能说明：
//!     1.该窗口统一输入时显示两个区域，显示区域负责保存历史内容，
//!     2.输入区域将内容面板压入显示界面，显示界面只负责排版
//!     3.内容利用qt_news类承载信息
//!
class wid_talk : public wid_change
{
    Q_OBJECT
public:
    explicit wid_talk(QWidget *parent = nullptr);
    void set_info(long long account,QString title);
    void into_news(en_info en,QString info);
    long long get_account();

    void set_drag(bool drag = true);//开启拖动

signals:
    //发送信息，文字或者文件
    emit void fa_send_news(en_info en,long long account,QString info);

protected:
    long long v_account;
    QLabel *lab_title;
    qt_button *butt_transmit;//发送按钮
    qt_button *butt_file;//打开文件
    qt_button *butt_hide;//隐藏窗口

    QMap<QString,qt_news_file*> map_file_prog;//文件进度查找
    QMap<en_info,std::function<void(QString)>> map_task_into;//传入的显示界面函数查询

    qt_edit_text *edit_in;//输入区域
    wid_slide_list *wid_show;//显示区域，控制显示区域的整体大小，加载qt_news

    //绘画窗口
    QPoint pos_lien_up;
    QPoint pos_lien_down;
    void paintEvent(QPaintEvent *event) override;

    //发送到显示区域(同时发送到网络)
    void send_word();//发送文字
    void send_pic(QList<QString> list);//发送图片
    void send_ask(QString filename);//发送文件请求
    void send_file(QString filename);//发送文件

    //通过网络回传的内容
    void show_word(QString txt);//显示文字
    void show_pic(QString file_path);//显示图片
    void show_ask(QString file_path);//显示文件请求
    void show_file(QString filename);//发送文件

    //文件进度(需要三个字段:文件名,进度值,是否完成(prog/finish))(分割符:##)
    void show_file_prog(QString info);

//    文件完成(需要两个字段:文件名,是否成功)(分割符:##)
//    void show_file_finish(QString info);

    //
    bool is_drag = true;
    virtual void dragEnterEvent(QDragEnterEvent *e) override;
    virtual void dropEvent(QDropEvent *e) override;

};

#endif // WID_TALK_H
