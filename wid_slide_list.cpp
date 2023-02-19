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
    v_file.close();
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
    QString temp = wid->get_info()+"\n";
    v_file.write(temp.toUtf8());//加入历史记录容器
    v_file.flush();

    wid->move(0,v_space + pos_current);//放置加入的窗口到滑动界面
    pos_current += wid->height() + v_space;//记录当前窗口的位置
}

void wid_slide_list::add_widget_history(qt_news *wid)
{
    //设置最底部滑动窗口大小
    area->get_wid_slide()->resize
            (this->width(),v_space + pos_current + wid->height());

    //发送信息时列表回滚触底 QScrollArea
    area->verticalScrollBar()->setValue
            (area->verticalScrollBar()->maximum());

//    wid->show();
    vec_news.push_back(wid);//加入消息列表

    wid->move(0,v_space + pos_current);//放置加入的窗口到滑动界面
    pos_current += wid->height() + v_space;//记录当前窗口的位置
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

void wid_slide_list::set_filename(QString filename)
{
    v_filename = filename;
    v_file.setFileName(filename);
    if(v_file.open(QIODevice::WriteOnly | QIODevice::Append) == false)
    { vloge("open err: " vv(filename.toStdString())); }
}

bool wid_slide_list::load_history()
{
    if(is_load) return true;
    is_load = true;
    QFile file(v_filename);
    QString flg = "##=##=##=##=##";
    if(file.open(QIODevice::ReadOnly))
    {
        //[1]写入类型,[2]是否为我方写入,[3]写入时间,[4]写入内容
        QVector<QString> vec;
        while(file.atEnd() == false)
        { vec.push_back(file.readLine()); }
        file.close();

        for(auto it = vec.begin();it != vec.end();it++)
        {
            QString str = *it;
            str = str.section("\n",0,0);
            QString type = str.section(flg,0,0);
            QString self = str.section(flg,1,1);
            QString time = str.section(flg,2,2);
            QString content = str.section(flg,3,-1);

            bool is_self = false;
            if(self == "YES") is_self = true;
            if(type == "WORD") add_widget_history(new qt_news_word(get_show_wid(),content,is_self));

            else if(type == "SPIC")
            {
                QPixmap pix;
                if(pix.load(content))
                    add_widget_history(new qt_news_pic(get_show_wid(),pix,content,is_self));
            }
            else if(type == "FILE")
            {
                qt_news_file *temp = new qt_news_file(get_show_wid(),content,is_self);
                temp->set_status("历史信息",100);
                add_widget_history(temp);
            }

            qout<<type<<"|"<<self<<"|"<<time<<"|"<<content;
        }



        return true;
    }
    return false;
}

QWidget *wid_slide_list::get_show_wid()
{
    return area->get_wid_slide();
}







