#include "qt_area_slide.h"

qt_area_slide::qt_area_slide(QWidget *parent) : QScrollArea(parent)
{
    wid_slide = new QWidget(parent);
    this->setWidget(wid_slide);
    this->show();
}

void qt_area_slide::set_size_wid(int wide, int high)
{
    wid_slide->resize(wide,high);
}

void qt_area_slide::set_size_area(int wide, int high)
{
    this->resize(wide,high);
}

void qt_area_slide::less_frame()
{
    this->setFrameShape(QFrame::NoFrame);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏横向滚动条
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏竖向滚动条
//    this->setPalette(QPalette(QPalette::Window,(QColor(0,0,0,0))));//窗口背景透明
}

QWidget *qt_area_slide::get_wid_slide()
{
    return wid_slide;
}
