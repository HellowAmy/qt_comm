#ifndef QT_AREA_SLIDE_H
#define QT_AREA_SLIDE_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QScrollArea>

//!
//! 功能:创建一个可滑动窗口,用于显示好友列表的管理
//!     1.wid_slide为控制指针不释放资源,该类需要外部的QWidget才能显示,不提供默认显示
//!
class qt_area_slide : public QScrollArea
{
    Q_OBJECT
public:
    explicit qt_area_slide(QWidget *parent = nullptr);
    void set_size_wid(int wide, int high);//滑动区域大小
    void set_size_area(int wide, int high);//可见窗口大小
    void less_frame();//去除边框和滑动条
    QWidget* get_wid_slide();//返回滑动区域，以支持自定义添加控件

signals:

protected:
    QWidget *wid_slide;
};

#endif // QT_AREA_SLIDE_H
