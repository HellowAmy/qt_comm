#include "wid_talk.h"

wid_talk::wid_talk(QWidget *parent)
    : wid_change{parent}
{
    //本窗口初始化
    this->resize(600,600);
    this->open_translucent();
    this->open_lessframe();
    this->open_backdrop(":/pic/pic_bake_talk.png");
    this->show();

    set_drag();

    //== 标题 ==
    lab_title = new QLabel(this);
    lab_title->show();
    lab_title->move(-5,-5);
    lab_title->resize(this->width()+10,40+5);
    lab_title->setText("===== ? =====");
    lab_title->setFont(QFont("微软雅黑",16));
    lab_title->setAlignment(Qt::AlignCenter);
    lab_title->setFrameShape(QFrame::Box);
    lab_title->setLineWidth(3);
    QPalette pe;
    pe.setColor(QPalette::WindowText,0xe96366);
    lab_title->setPalette(pe);
    //== 标题 ==

    //输入框初始化
    int space = 60;//输入框与底部间隔
    edit_in = new qt_edit_text(this);
    edit_in->resize(this->width() - space*2,this->height()/6);
    edit_in->move(space,this->height() - edit_in->height() - space);
    edit_in->show();

    //记录输入框范围距离，为画线条准备
    pos_lien_up = QPoint(0,this->height() - edit_in->height() - space);
    pos_lien_down = QPoint(0,this->height() - space);

    //按钮——发送到服务器
    butt_transmit = new qt_button(this);
    butt_transmit->move(this->width() - butt_transmit->width()*2 + 30,
                        this->height() - butt_transmit->height() - 5);
    butt_transmit->set_txt("发送");
    butt_transmit->show();

    //按钮——隐藏窗口
    butt_hide = new qt_button(this);
    butt_hide->move(50,this->height() - butt_hide->height() - 5);
    butt_hide->set_txt("关闭");
    butt_hide->show();

    //按钮——打开文件
    butt_file = new qt_button(this);
    butt_file->move(butt_hide->pos()+QPoint(butt_hide->width(),0));
    butt_file->set_txt("文件");
    butt_file->show();

    //消息滑动窗口
    wid_show = new wid_slide_list(this);
    wid_show->move(10,40);
    wid_show->set_size(this->width() - 10*2,390);


    map_task_into.insert(en_info::e_send_txt,std::bind(&wid_talk::show_word,this,_1));
    map_task_into.insert(en_info::e_send_pic,std::bind(&wid_talk::show_pic,this,_1));
    map_task_into.insert(en_info::e_send_file,std::bind(&wid_talk::show_file,this,_1));
    map_task_into.insert(en_info::e_send_file_prog,std::bind(&wid_talk::show_file_prog,this,_1));


//    if(en == en_info::e_send_txt)
//    { show_word(info); }
//    else if (en == en_info::e_send_pic)
//    { show_pic(info); }
//    else if (en == en_info::e_send_file)
//    { show_file(info); }
//    else { vlogw("into_news not find"); }

//    //
//    QLabel *uw=new QLabel(wid_show);
//    uw->resize(wid_show->size());
//    uw->setText("QFrame::Box: wid_slide_list");
//    uw->setFrameShape(QFrame::Box);
//    uw->show();
//    vlogf("QFrame::Box: wid_slide_list");

//    qout<<wid_show->size()<<"|"<<wid_show->get_show_wid()->size();

//    wid_show->set_size()

    //设置窗口背景透明
    wid_show->setPalette
            (QPalette(QPalette::Window,(QColor(0,0,0,0))));

    //发送信号--按钮
    connect(butt_transmit,&qt_button::fa_press,this,[=](){
        send_word();
    });

    //发送信号--回车
    connect(edit_in,&qt_edit_text::fa_press_enter,this,[=](){
        send_word();
    });

    //发送文件
    connect(butt_file,&qt_button::fa_press,this,[=](){
        QStringList list = QFileDialog::getOpenFileNames(this,"Send Files","/home/red/test/");
        for(auto a:list)
        { send_file(a); }

    });

    //隐藏窗口
    connect(butt_hide,&qt_button::fa_press,this,[=](){
        this->hide();
    });
}

void wid_talk::set_info(long long account, QString title)
{
    v_account = account;
    lab_title->setText(title);
}

long long wid_talk::get_account()
{
    return v_account;
}

void wid_talk::set_drag(bool drag)
{
    is_drag = drag;
    this->setAcceptDrops(drag);
}

void wid_talk::into_news(en_info en, QString info)
{
    this->show();
    auto it = map_task_into.find(en);
    if(it != map_task_into.end())
    { it.value()(info); }
    else { vlogw("map_task_into: into_news not find"); }
}

void wid_talk::paintEvent(QPaintEvent *e)
{
    wid_change::paintEvent(e);
    QPainter *show=new QPainter(this);
    show->setPen(QPen(QColor(0x4c5765),6));

    //画横线——上下线
    show->drawLine(pos_lien_up,pos_lien_up + QPoint(this->width(),0));
    show->drawLine(pos_lien_down,pos_lien_down + QPoint(this->width(),0));

    //画横线——左右线
    show->drawLine(pos_lien_up + QPoint(edit_in->x(),0),
                   pos_lien_down + QPoint(edit_in->x(),0));
    show->drawLine(pos_lien_up + QPoint(edit_in->width() + edit_in->x(),0),
                   pos_lien_down + QPoint(edit_in->width()+ edit_in->x(),0));

    show->end();
}

void wid_talk::send_word()
{
    //发送信息并清屏
    QString word = edit_in->toPlainText();
    if(word.isEmpty() == false)
    {
        wid_show->add_widget(new qt_news_word(wid_show->get_show_wid(),word));
        emit fa_send_news(en_info::e_send_txt,v_account,word);
        edit_in->setText("");
    }
}

void wid_talk::send_file(QString filename)
{
    qt_news_file *temp = new qt_news_file(wid_show->get_show_wid(),filename);
    map_file_prog.insert(filename,temp);
    wid_show->add_widget(temp);
    emit fa_send_news(en_info::e_send_file,v_account,filename);
    vlogf("send_file");
}

void wid_talk::send_pic(QList<QString> list)
{
    QPixmap pix;
    for(auto it = list.begin();it != list.end();it++)
    {
        const QString &file_path = *it;
        if(pix.load(file_path))
        {
            wid_show->add_widget(new qt_news_pic(wid_show->get_show_wid(),pix,file_path));
            emit fa_send_news(en_info::e_send_pic,v_account,file_path);
        }
        else vlogw("load failed:" vv(file_path.toStdString()));
    }
    vlogf("send_pic");
}

void wid_talk::show_word(QString txt)
{
    wid_show->add_widget(new qt_news_word(wid_show->get_show_wid(),txt,false));
}

void wid_talk::show_pic(QString file_path)
{
    QPixmap pix(file_path);
    if(pix.isNull() == false)
    { wid_show->add_widget(new qt_news_pic(wid_show->get_show_wid(),pix,file_path,false)); }
    else vlogw("show_pic err");
}

void wid_talk::show_file(QString filename)
{
    qt_news_file *temp = new qt_news_file(wid_show->get_show_wid(),filename,false);
    map_file_prog.insert(filename,temp);
    wid_show->add_widget(temp);
    vlogw("show_file");
}

void wid_talk::show_file_prog(QString info)
{
    qout<<info;
    QString filename = info.section("##",0,0);
    QString prog = info.section("##",1,1);
    QString finish = info.section("##",2,2);
    if(filename.isEmpty() == false
            && prog.isEmpty() == false
            && finish.isEmpty() == false)
    {
        auto it = map_file_prog.find(filename);
        if(it != map_file_prog.end())
        {
            if(finish == "0") it.value()->set_status("发送进度",prog.toInt());
            else if(finish == "1") it.value()->set_status("发送完成",100);
            else vlogw("prog value");
        }
        else vlogw("map_file_prog not find");
    }
    else vlogw("info is empty");
}

//void wid_talk::show_file_finish(QString info)
//{
////    QString filename = info.section("##",0,0);
////    QString ok = info.section("##",1,1);
////    auto it = map_file_prog.find(filename);
////    if(it != map_file_prog.end())
////    {
//////        it.value()->set_status("发送完成",100);
//////        if(finish == "0") it.value()->set_status("发送进度",prog.toInt());
//////        else if(finish == "1")
//////        else vlogw("prog value");
////    }
////    else vlogw("map_file_prog not find");
//}

void wid_talk::dragEnterEvent(QDragEnterEvent *e)
{
    if(is_drag)
    {
        if(e->mimeData()->hasUrls())//判断数据类型
        { e->acceptProposedAction(); }
    }
}

void wid_talk::dropEvent(QDropEvent *e)
{
    if(e->mimeData()->hasUrls())//处理期望数据类型
    {
        QList<QString> list_str;
        QList<QUrl> list = e->mimeData()->urls();//获取数据并保存到链表中
        for(const auto &a:list)
        { list_str.append(a.toLocalFile()); }

        send_pic(list_str);
        vlogf(vv(list.size()));
//        for(int i = 0; i < list.count(); i++)
//        {
//            qDebug() << list[i].toLocalFile();
//        }
    }
}
