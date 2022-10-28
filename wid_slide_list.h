#ifndef WID_SLIDE_LIST_H
#define WID_SLIDE_LIST_H

#include <QWidget>
#include <QVector>
#include <QScrollBar>

#include "qt_area_slide.h"
#include "qt_news.h"

class wid_slide_list : public QWidget
{
    Q_OBJECT
public:
    explicit wid_slide_list(QWidget *parent = nullptr);
    ~wid_slide_list();
    void add_widget(qt_news *wid);//添加控件到滑动窗口
    void set_size(int wide,int high);//设置可见窗口大小
    void set_space(int space);//设置添加滑动窗口间隔

    QVector<QString> get_history();

signals:

protected:
    QVector<qt_news*> vec_news;//按钮容器
    QVector<QString> vec_history;//历史容器
    qt_area_slide *area;//滑动区域
    int pos_current = 0;//当前的控件高度
    int v_space = 5;
};

#endif // WID_SLIDE_LIST_H
