#include "wid_slide_list.h"

wid_slide_list::wid_slide_list(QWidget *parent) : QWidget(parent)
{
    area = new qt_area_slide(this);
    area->less_frame();
    this->show();
}

wid_slide_list::~wid_slide_list()
{
    for(auto it = vec_news.begin();it != vec_news.end();it++)
    {
        delete *it;
    }
}

void wid_slide_list::add_widget(qt_news *wid)
{
    //设置最底部滑动窗口大小
    area->get_wid_slide()->resize
            (this->width(),v_space + pos_current + wid->height());

    //发送信息时列表回滚触底 QScrollArea
    area->verticalScrollBar()->setValue
            (area->verticalScrollBar()->maximum());

    vec_news.push_back(wid);//加入消息列表
    vec_history.push_back(wid->get_info());//加入历史记录容器
    wid->move(0,v_space + pos_current);//放置加入的窗口到滑动界面
    pos_current += wid->height() + v_space;//记录当前窗口的位置

    //历史容器信息
    for(int i=0;i<vec_history.size();i++)
    {
        vlogf("P:"<<vec_history[i].toStdString());
        vlogf(vec_history.size());
    }
}

void wid_slide_list::set_size(int wide, int high)
{
    area->resize(wide,high);
    area->get_wid_slide()->resize(wide,high);
    this->resize(wide,high);
}

void wid_slide_list::set_space(int space)
{
    v_space = space;
}

QWidget *wid_slide_list::get_show_wid()
{
    return area->get_wid_slide();
}

QVector<QString> wid_slide_list::get_history()
{
    return vec_history;
}
