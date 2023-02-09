#include "wid_friends_list.h"

#include <QDebug>
#define out qDebug()

wid_friends_list::wid_friends_list(QWidget *parent)
    : wid_change{parent}
{
    this->resize(250,600);
    this->open_translucent();
    this->open_lessframe();
    this->open_backdrop(":/pic/pic_bake_friends_list.png");

    //创建滑动区域
    area = new qt_area_slide(this);
    wid_slide = area->get_wid_slide();
    wid_slide->resize(v_wide+20,v_high);
    area->move(0,v_less/2);
    area->resize(v_wide+20,v_high-v_less);
    area->less_frame();
    area->setPalette(QPalette(QPalette::Window,(QColor(0,0,0,0))));//背景透明

    //关闭位置
    butt_close = new qt_button(this);
    butt_close->resize(100,45);
    butt_close->move(this->width()/2 - butt_close->width()/2,
                     this->height() - butt_close->height());
    butt_close->set_txt("<=退出=>");

    //== 测试===
    QVector<QString> vet_s;
    for(int i=0;i<20;i++)
    {
        vet_s.push_back("你是谁abCD第 "+QString::number(i)+" 位");
    }
    //== 测试===


//    创建好友列表
//    set_friends(vet_s);

    //关闭窗口
    connect(butt_close,&qt_button::fa_press,this,[=](){
        for(auto &a:map_wid_talk) { a->close(); }
        this->close();
    });
}

//void wid_friends_list::set_net(const shared_ptr<net_connect> &net)
//{
//    sp_net = net;
//}

wid_friends_list::~wid_friends_list()
{
    for(auto &a:map_wid_talk) { delete a; }
}

void wid_friends_list::set_friends(QVector<ct_friends_info> vec)
{
    //插入到容器
    for(int i=0;i<vec.size();i++)
    {
        //添加按钮
        qt_button *butt = new qt_button(wid_slide);
        butt->show();
        butt->set_txt(QString::fromStdString(vec[i].name));//按钮名称
        butt->resize(v_wide-4,v_less/2);//设置按钮大小

        //添加聊天窗口
        wid_talk *wid = new wid_talk;
        wid->set_info(vec[i].account,QString::fromStdString(vec[i].name));
        wid->hide();

        map_wid_talk.insert(butt,wid);//插入到容器
    }

    //添加到自动排序容器
    qt_move_it vec_move(wid_slide);
    for(auto it = map_wid_talk.begin();it != map_wid_talk.end();it++)
    {
        vec_move.add_wid(it.key());//添加到自动排序容器

        //显示聊天窗口
        connect(it.key(),&qt_button::fa_press,this,[=](){
            it.value()->show();
        });

        //转发信息
        connect(it.value(),&wid_talk::fa_send_news,this,
                [=](en_info en,long long account,QString txt){
            this->fa_send_news(en,account,txt.toStdString());
        });
    }
    vec_move.set_vert(QPoint(0,0));//设置排序方式
}

//void wid_friends_list::set_friends(QVector<long long> vec)
//{
//    for(int i=0;i<vec.size();i++)
//    {
//                        wid_talk *temp = new wid_talk;
//                        temp->show();
//                        temp->set_info(vec_butt[i]->get_txt());
//                        map_wid_talk.insert(vec_butt[i],temp);
//        map_wid_talk.insert(vec[i],temp);
//    }
//}

//void wid_friends_list::set_friends(QVector<QString> vec_str)
//{
//    //为容器创建按钮
//    for(int i=0;i<vec_str.size();i++)
//    {
//        qt_button *temp=new qt_button(wid_slide);
//        temp->set_txt(vec_str[i]);//按钮名称
//        temp->resize(v_wide-4,v_less/2);//设置按钮大小

//        vec_butt.push_back(temp);//添加到按钮容器
//    }

//    //添加到自动排序容器
//    qt_move_it *vec_move = new qt_move_it(wid_slide);
//    for(int i=0;i<vec_str.size();i++)
//    {
//        vec_move->add_wid(vec_butt[i]);//添加到自动排序容器
//    }
//    vec_move->set_vert(QPoint(0,0));//设置排序方式

//    wid_slide->resize(v_wide+20,vec_move->get_count_high());//设置窗口大小

//    //容器按钮信号槽
//    for(int i=0;i<vec_butt.size();i++)
//    {
//        connect(vec_butt[i],&qt_button::fa_press,this,[=]{
//            auto it = map_wid_talk.find(vec_butt[i]);
//            if(it == map_wid_talk.end())
//            {
//                wid_talk *temp = new wid_talk;
//                temp->show();
//                temp->set_title(vec_butt[i]->get_txt());
//                map_wid_talk.insert(vec_butt[i],temp);
//            }
//            else it.value()->show();

//            //点击不同好友的反馈==========测试
////            sp_net->send_txt(187241241,"123qwe");
//            QString temp = vec_butt[i]->get_txt();
////            out<<"点击了："+temp;
//        });
//    }
//}
