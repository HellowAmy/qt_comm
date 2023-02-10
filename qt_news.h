#ifndef QT_NEWS_H
#define QT_NEWS_H

#include <QWidget>
#include <QPainter>
#include <QDateTime>
#include <QLabel>
#include <QPixmap>

#include "vts_vlog.h"

//!
//! 功能：提供一个抽象的统一接口，可以自定义显示内容
//! 子类需要返回一个虚拟记录消息，用于写入历史文件
//! 消息格式：##[类型]##[对方]##[时间]##[内容]##
//! 预设（类型）：文字、图片、视频
//! 预设（对方）：发起方、接收方
//! 预设（时间）：发送时间
//! 预设（内容）：文件内容、文件路径
//!
class qt_news : public QWidget
{
    Q_OBJECT
public:
    QString get_info();//消息格式：[类型]##[对方]##[时间]##[内容]

signals:

protected:
    explicit qt_news(QWidget *parent = nullptr);

    QWidget* init_news(QWidget *parent,bool self,QString time,QString type,QString content);
    QString str_info;

    QWidget *wid_news;
    QString str_news_time;
    QString flg = "##=##=##=##=##";

    bool is_self = true;//标记显示方向（我方左，对方右）
    int v_mini = 30;//最小距离
    int v_space = 5;//绘画间隔
    int v_begin = 40;//显示窗口起点位置

    QFont v_font;
    QString get_time();
    void set_wid_high(QWidget *wid,int high);

    //子类快速写入历史消息
    QString to_info(QString type,bool self,QString time,QString content);

    //绘制时间
    void draw_time(QPainter *show);
    void paintEvent(QPaintEvent *event) override;
};

//显示文字
class qt_news_word : public qt_news
{
    Q_OBJECT
public:
    explicit qt_news_word(QWidget *parent,QString word,bool self = true);//通用接口

signals:

protected:
    //超过长度则在最大字符前插入换行符
    int line_wrap_max(const QString &str_old,
                      QString &str_new, int max = 390);
    int size_calculate(QString word);//计算文字长度
};

//显示图片
class qt_news_pic : public qt_news
{
    Q_OBJECT
public:
    explicit qt_news_pic(QWidget *parent,const QPixmap &pix,QString path,bool self = true);//通用接口

signals:

protected:

};

//显示发送文件
class qt_news_file : public qt_news
{
    Q_OBJECT
public:
    explicit qt_news_file(QWidget *parent,QString filename,bool self = true);//通用接口

signals:

protected:

};

#endif // QT_NEWS_H
