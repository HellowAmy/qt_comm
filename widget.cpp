#include "widget.h"
#include "ui_widget.h"


#include "wid_login.h"
#include "wid_change.h"

#include "wid_edit.h"

#include "wid_register.h"

#include "wid_friends_list.h"
#include "wid_manage.h"

#include "tcp_socket.h"

#include "wid_talk.h"

#include "qt_area_slide.h"

#include "wid_slide_list.h"

#include "vlog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //! =====各类功能=====
    //! 从wid_manage开始运行
    //!
    //! 全局控制类：wid_manage，控制登录窗口和进入后好友列表的切换
    //! 登录类：wid_login，有登录和注册功能，程序的入口
    //!         与服务器通信，返回登录验证是否通过
    //! 注册类：wid_register，被wid_login包含，只能被等待调用
    //!         负责与服务器进行注册通信，反馈注册结果
    //! 列表类：wid_friends，保存好友信息
    //!         通过服务器返回的好友信息对列表进行初始化（未实现）
    //!         附带点击弹出窗口功能（未实现）
    //! 聊天窗口类：wid_talk，这个窗口集成带有文字输入发送等所有功能...（未实现）
    //!         窗口发送信息时应该加入历史记录，并带有动态调节文字显示窗口（未实现）
    //!         信息接收之后发往这个窗口，应该准备接口（未实现）
    //!
    //! =====数据表格式=====
    //!
    //! （服务器记录IP和port，方便回执）
    //! 客户端注册信息：#####[类型]#####[密码]#####
    //! 服务器注册回执：#####[类型]#####[账号]#####[密码]#####
    //!
    //! （服务器记录IP和port，并与账号绑定，完成后续通信）
    //! 客户端登录信息：#####[类型]#####[账号]#####[秘密]#####
    //! 客户端登录回执：#####[类型]#####[登录许可]#####
    //!
    //! 客户端发送信息：#####[类型]#####[对方账号]#####[本人账号]#####[内容]#####
    //!
    //! =====链接方式=====
    //! 快速链接：不会绑定账号，结构体内只记录通信IP、port和fd
    //! 长期链接：会记录账号，稳定长期联系
    //!
    //!
    //! =====服务器账号管理=====
    //! 创建生成账号的工具，生成的账号确保与文件内账号不重复
    //! 暂时使用文件代替数据库，文件中保存账号密码
    //! 启动服务器时将账号密码加载到容器提升速度
    //! 账号注册时立刻更新文件
    //!
    //!





    //全局管理，开启见效
//    wid_manage *wid_l=new wid_manage;
//    wid_l->hide();


    //==测试单元==


    //== 换行
//    this->show();
//    QFont font("微软雅黑",16);
////    QLabel hu
//    QString str = "123";
//    QString str2 = "12345678asdfagsdfaygsd111";
//    QFontMetrics me(font);
//    out<<me.size(Qt::TextSingleLine,str);
//    out<<me.size(Qt::TextSingleLine,str2);

//    QLabel *hu = new QLabel(this);
//    hu->resize(100,100);
//    hu->setWordWrap(true);
//    hu->setText(str);
//    hu->setFrameShape(QFrame::Box);
//    hu->show();

//    QLabel *hu2 = new QLabel(this);
//    hu2->move(100,100);
//    hu2->resize(100,100);
//    hu2->setWordWrap(true);
//    hu2->setText(str2);
//    hu2->setFrameShape(QFrame::Box);
//    hu2->show();

//    this->resize(me.size(Qt::TextSingleLine,str));
//    this->resize(me.size(Qt::TextSingleLine,str));
    //== 换行


//    this->show();
//    QLabel *hu = new QLabel(this);
//    hu->resize(500,100);
//    hu->setText("qingshura请输入文字");
//    hu->setFont(QFont("微软雅黑",12));
//    hu->setFrameShape(QFrame::Box);
//    hu->show();


//    wid_slide_list *ju = new wid_slide_list(this);
//    ju->move(10,10);
//    ju->set_size(100,100);

//    for(int i=0;i<20;i++)
//    {
//        QLabel *hu = new QLabel;
////        hu->show();
//        hu->resize(100,30);
//        hu->setFrameShape(QFrame::Box);
//        QString tr = "这是第"+QString::number(i)+"位";
//        hu->setText(tr);
//        ju->add_widget(hu);
//    }





//    qt_area_slide *fd = new qt_area_slide(this);
//    fd->setFrameShape(QFrame::Box);
////    fd->show();
//    fd->move(100,100);
//    fd->set_size_area(100,100);
//    fd->set_size_wid(100,500);
//    QWidget *hu = fd->get_wid_slide();


//    QPushButton *t1 = new QPushButton(hu);
//    t1->show();
//    QPushButton *t2 = new QPushButton(hu);
//    t2->show();
//    t2->move(0,20);




//    wid_register *wid_r=new wid_register;
//    wid_r->show();

//    wid_friends_list *wid_f=new wid_friends_list;
//    wid_f->show();

//    wid_talk *wid_t=new wid_talk;
//    wid_t->show();

//    vlog<<"asjdas"<<endl;

//    vlog("in asdk=%d",123);
//    show_word<QString>("asdasd");

    out<<"init";

    tcp_socket *ts = new tcp_socket(this);
    ts->open_socket("192.168.188.2",5005);
//    ts->recv_news();

//    ct_cmd cmd;
//    cmd.type = enum_transmit::e_register;

//    ct_register ct;
//    ct.passwd = 123482123;

    connect(ts,&tcp_socket::connected,this,[=](){
        out<<"=====ok_socket=====";

        ts->send_register("123qwe");
//        ts->send_register("qweasd");
//        ts->send_login(12341,"gdgdsfg");
//        ts->send_register("gdgdsfg");
//        ts->send_register("asdfab72bd28111pp====");
        ts->send_login(12341,"gdgdsfg");

        ts->send_logout(12341);

        ts->send_login(123123,"123123");
        ts->send_register("123qwe");



        out<<"=====end=====";


    });


    connect(ts,&tcp_socket::fa_back_register,this,[=](long long ac,QString pa){
        out<<ac<<"|"<<pa;
    });

    connect(ts,&tcp_socket::fa_back_login,this,[=](int flg,QString info){
        out<<flg<<"|"<<info;
    });

//    connect(ts,&tcp_socket::fa_connect_socket,this,[=](){
//        vlog<<"=====ok_socket====="<<endl;
//        out<<"ok_in";
////        ts->write_word("192.168.188.100",5005,"000ahfuahskfjagfia000");


//        //传送内容信号
//        connect(ts,&tcp_socket::readyRead,[=](){
//            out<<"op: "<<ts->readAll();
//        });
//    });

    //==测试单元==





}

Widget::~Widget()
{
    delete ui;
}

