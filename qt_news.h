#ifndef QT_NEWS_H
#define QT_NEWS_H

#include <QWidget>
#include <QPainter>
#include <QDateTime>
#include <QLabel>

class qt_news : public QWidget
{
    Q_OBJECT
public:
    explicit qt_news(QWidget *parent = nullptr);
    virtual QString to_string_info() = 0;
    void set_size(int wide,int high);
    void set_self(bool self);
    void set_news_time(QString time);
    QWidget* get_news_wid();

signals:

protected:
    QWidget *wid_news;
    QString str_news_time;
    bool is_self = true;//标记显示方向（我方左，对方右）
    int v_mini = 30;//最小距离
    int v_space = 5;//绘画间隔
    int v_begin = 40;//显示窗口起点位置

    void paintEvent(QPaintEvent *event) override;
    QString get_time();

    void draw_time(QPainter *show);
};

class qt_news_word : public qt_news
{
    Q_OBJECT
public:
    explicit qt_news_word(QWidget *parent = nullptr);
    explicit qt_news_word(QString word,bool self = true);
    QString to_string_info() override;
    void set_word(QString word);



signals:

protected:
    QString v_word;

};

#endif // QT_NEWS_H
