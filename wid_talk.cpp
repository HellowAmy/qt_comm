#include "wid_talk.h"

#include <QDebug>
#define out qDebug()

wid_talk::wid_talk(QWidget *parent)
    : wid_change{parent}
{
    //本窗口初始化
    this->resize(600,600);
    this->open_translucent();
    this->open_lessframe();
    this->open_backdrop(":/pic/pic_bake_talk.png");
    this->show();


    //== 标题 ==
    lab_title = new QLabel(this);
    lab_title->show();
    lab_title->move(-5,-5);
    lab_title->resize(this->width()+10,40+5);
    lab_title->setText("===== ? =====");
    lab_title->setFont(QFont("微软雅黑",16));
    lab_title->setAlignment(Qt::AlignCenter);
    lab_title->setFrameShape(QFrame::Box);
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
    butt_transmit->move(this->width() - butt_transmit->width()*2,
                        this->height() - butt_transmit->height() - 5);
    butt_transmit->set_txt("发送");
    butt_transmit->show();


    //按钮——隐藏窗口
    butt_hide = new qt_button(this);
    butt_hide->move(20,this->height() - butt_hide->height() - 5);
    butt_hide->set_txt("关闭");
    butt_hide->show();


    //消息滑动窗口
    wid_show = new wid_slide_list(this);
    wid_show->move(60,50);
    wid_show->set_size(this->width() - 60*2,350);

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
        emit fa_send_news(en_info::e_send_txt,v_account,word);
        wid_show->add_widget(new qt_news_word(word));
        edit_in->setText("");
    }

    //==test history ret
//    QVector<QString> vec = wid_show->get_history();
//    for(auto a:vec)
//    {
//        out<<"in: "<<a<<endl;
//    }
}
