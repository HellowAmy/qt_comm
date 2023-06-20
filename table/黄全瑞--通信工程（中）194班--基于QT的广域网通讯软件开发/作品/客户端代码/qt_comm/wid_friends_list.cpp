#include "wid_friends_list.h"

wid_friends_list::wid_friends_list(QWidget *parent) : wid_change(parent)
{
    this->resize(250,600);
    this->open_translucent();
    this->open_lessframe();
    this->open_backdrop(":/pic/pic_bake_friends_list.png");

    QDir dir(v_file_path);
    if(dir.exists() == false) dir.mkpath(v_file_path);

    //创建滑动区域
    area = new qt_area_slide(this);
    wid_slide = area->get_wid_slide();
    wid_slide->resize(v_wide+20,v_high);
    area->move(0,v_less/2);
    area->resize(v_wide+20,v_high-v_less);
    area->less_frame();
    area->setPalette(QPalette(QPalette::Window,(QColor(0,0,0,0))));//背景透明

    //添加好友界面
    wid_add = new wid_add_friend;
    wid_add->close();

    //关闭位置
    butt_close = new qt_button(this);
    butt_close->resize(100,45);
    butt_close->move(this->width()/2 - butt_close->width(),
                     this->height() - butt_close->height());
    butt_close->set_txt("<=退出=>");

    butt_add = new qt_button(this);
    butt_add->resize(100,45);
    butt_add->move(butt_close->x()+butt_add->width(),
                     this->height() - butt_close->height());
    butt_add->set_txt("<=添加=>");

    //添加好友反馈
    connect(wid_add,&wid_add_friend::fa_add_friend,this,[=](long long account){
        emit fa_add_friend(account);
    });

    //添加好友
    connect(butt_add,&qt_button::fa_press,this,[=](){
        wid_add->show();
    });

    //关闭窗口
    connect(butt_close,&qt_button::fa_press,this,[=](){
        for(auto &a:map_wid_talk) { a.wid->close(); }
        this->close();
    });
}

wid_friends_list::~wid_friends_list()
{
    clear_wid_talk();
}

void wid_friends_list::set_account(long long account)
{ v_account = account; wid_add->set_account(v_account); }

void wid_friends_list::into_friends(QMap<long long, std::string> map)
{
    clear_wid_talk();
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
        QString filename = v_file_path+QString::number(v_account)+"_"+QString::number(it.key())+".txt";
        ct.wid->set_filename(filename);
        ct.wid->set_info(v_account,it.key(),QString::fromStdString(it.value()));
        ct.wid->hide();

        map_wid_talk.insert(it.key(),std::move(ct));//插入到容器

        vlogd(vv(it.value())  vv(map_wid_talk.size()));
    }

    //添加到自动排序容器
    qt_move_it vec_move(wid_slide);
    for(auto it = map_wid_talk.begin();it != map_wid_talk.end();it++)
    {
        vec_move.add_wid(it->butt);//添加到自动排序容器

        //连接信号--显示聊天窗口
        connect(it->butt,&qt_button::fa_press,this,[=](){
            it->wid->load_news();
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

void wid_friends_list::clear_wid_talk()
{ for(auto &a:map_wid_talk) { delete a.wid; delete a.butt; } }
