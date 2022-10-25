#include "wid_slide_list.h"

wid_slide_list::wid_slide_list(QWidget *parent) : QWidget(parent)
{
    area = new qt_area_slide(this);
    area->set_size_wid(this->width(),this->height());
    area->less_frame();
    this->show();
}

wid_slide_list::~wid_slide_list()
{
    for(auto it = vec_history.begin();it != vec_history.end();it++)
    {
        delete *it;
    }
}

void wid_slide_list::add_widget(qt_news *wid)
{
    //设置并获取滑动窗口
    area->set_size_wid(this->width(),v_space + pos_current + wid->height());
    QWidget *wid_slide = area->get_wid_slide();

    //将控件与滑动窗口绑定
    wid->setParent(wid_slide);
    wid->move(0,v_space + pos_current);
    wid->resize(this->width(),wid->height());
    wid->show();


    vec_history.push_back(wid);//加入历史容器
    pos_current += wid->height() + v_space;//记录当前窗口的位置
}

void wid_slide_list::set_size(int wide, int high)
{
    this->resize(wide,high);
    area->set_size_area(wide,high);
}

void wid_slide_list::set_space(int space)
{
    v_space = space;
}
