#ifndef QT_NEWS_H
#define QT_NEWS_H

#include <QWidget>
#include <QPainter>
#include <QDateTime>
#include <QLabel>

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
    explicit qt_news(QWidget *parent = nullptr);
    virtual QString to_string_info() = 0;
    void set_size(int wide,int high);
    void set_self(bool self);
    void set_news_time(QString time);
    QString get_self_str(bool self);
    QWidget* get_news_wid();

signals:

protected:
    QWidget *wid_news;
    QString str_news_time;
    QString flg = "##=##=##=##=##";


    bool is_self = true;//标记显示方向（我方左，对方右）
    int v_mini = 30;//最小距离
    int v_space = 5;//绘画间隔
    int v_begin = 40;//显示窗口起点位置

    QFont v_font;
    QString get_time();

    //子类快速写入历史消息
    QString to_info(QString type,bool self,QString time,QString content);

    void draw_time(QPainter *show);
    void paintEvent(QPaintEvent *event) override;
};

class qt_news_word : public qt_news
{
    Q_OBJECT
public:
    explicit qt_news_word(QWidget *parent = nullptr);
    explicit qt_news_word(QString word,bool self = true);//通用接口

    QString to_string_info() override;//返回的历史记录
    void set_word(QString word);//目前只开放了构造函数，不用这个

    //计算文字长度
    int size_calculate(QString word);

    //超过长度则在最大字符前插入换行符
    int line_wrap_max(const QString &str_old,
                      QString &str_new, int max = 345);

signals:

protected:
    QString v_word;
    QString v_info;

    QString type = "WORD";
};

#endif // QT_NEWS_H
