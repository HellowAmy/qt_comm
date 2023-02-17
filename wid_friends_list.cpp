#include "wid_friends_list.h"

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

    //关闭窗口
    connect(butt_close,&qt_button::fa_press,this,[=](){
        for(auto &a:map_wid_talk) { a.wid->close(); }
        this->close();
    });
}

wid_friends_list::~wid_friends_list()
{
    for(auto &a:map_wid_talk) { delete a.wid; delete a.butt; }
}

void wid_friends_list::into_friends(QMap<long long, std::string> map)
{
    for(auto it = map.begin();it != map.end();it++)
    {
        //添加按钮
        ct_friends_index ct;
        ct.butt = new qt_button(wid_slide);
        ct.butt->show();
        ct.butt->set_txt(QString::fromStdString(it.value()));//按钮名称
        ct.butt->resize(v_wide-4,v_less/2);//设置按钮大小

        //添加聊天窗口
        ct.wid = new wid_talk;
        ct.wid->set_info(it.key(),QString::fromStdString(it.value()));
        ct.wid->hide();

        map_wid_talk.insert(it.key(),std::move(ct));//插入到容器
    }

    //添加到自动排序容器
    qt_move_it vec_move(wid_slide);
    for(auto it = map_wid_talk.begin();it != map_wid_talk.end();it++)
    {
        vec_move.add_wid(it->butt);//添加到自动排序容器

        //连接信号--显示聊天窗口
        connect(it->butt,&qt_button::fa_press,this,[=](){
            it->wid->show();
        });

        //连接信号--转发信息
        connect(it->wid,&wid_talk::fa_send_news,this,
                [=](en_info en,long long account,QString txt){
            this->fa_send_news(en,account,txt);
        });
    }
    vec_move.set_vert(QPoint(0,0));//设置排序方式
}

void wid_friends_list::into_news(en_info en, long long account, QString info)
{
    auto it = map_wid_talk.find(account);
    if(it != map_wid_talk.end())
    { it->wid->into_news(en,info); }
    else vlogw("未找到账号:" vv(account));
}
