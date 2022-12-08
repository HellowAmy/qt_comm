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
    //! 程序退出时注册账号更新到文件
    //!
    //! =====数据转发=====
    //! 服务器无需多问，寻找账号并转发，客户端根据类型转发接收
    //!
    //! 文字：对方账号、数据、一次发完
    //! 文件：对方账号、数据、多次发完、标记类型、
    //!         标记总量、标记当前发送大小、标记累计大小
    //!




#if 1
    //全局管理，开启见效
    wid_manage *wid_l=new wid_manage;
    wid_l->hide();
#endif

    //==测试单元==




//    wid_register *wid_r=new wid_register;
//    wid_r->show();

//    wid_friends_list *wid_f=new wid_friends_list;
//    wid_f->show();

//    wid_talk *wid_t=new wid_talk;
//    wid_t->show();

//    vlog<<"asjdas"<<endl;

//    vlog("in asdk=%d",123);
//    show_word<QString>("asdasd");









//    out<<"init";

//    tcp_socket *ts = new tcp_socket(this);
//    ts->open_socket("192.168.188.2",5005);

//    connect(ts,&tcp_socket::connected,this,[=](){
//        out<<"=====ok_socket=====";
//        ts->send_login(6334967572,"123qwe");
//        QThread::sleep(1);
//        out<<"=====end=====";
//    });

//    connect(ts,&tcp_socket::fa_back_login,this,[=](int flg,QString info){
//        out<<"=====fa_back_login=====";
//        out<<flg<<"|"<<info;
//        QThread::sleep(1);
////        ts->send_swap_txt(1934865572,"0003qweasdhabwh吴建豪的dasdasdgbdsfg0000");
//        for(int i=0;i<5;i++)
//        {
//            ts->send_swap_txt(1934865572,"0003qweasdhabwh吴建豪的dasdasdgbdsfg0000");
//            ts->flush();
//            QThread::sleep(1);
//        }
//        out<<"=====fa_back_login=====";
//    });

//    connect(ts,&tcp_socket::fa_swap_txt,
//            this,[=](long long account_from,QString txt){
//        out<<"=====ts:fa_swap_txt=====";
//        out<<account_from<<"|"<<txt;
////        QThread::sleep(1);
////        ts->send_swap_txt(account_from,"bababababbbabababababab");
//        out<<"=====ts:fa_swap_txt=====";
//    });

//    tcp_socket *ts1 = new tcp_socket(this);
//    ts1->open_socket("192.168.188.2",5005);

//    connect(ts1,&tcp_socket::connected,this,[=](){
//        out<<"=====ok_socket=====";
//        ts1->send_login(1934865572,"123qwe");
//        QThread::sleep(1);
//        out<<"=====end=====";
//    });

//    connect(ts1,&tcp_socket::fa_back_login,this,[=](int flg,QString info){
//        out<<"=====fa_back_login=====";
//        out<<flg<<"|"<<info;
//        out<<"=====fa_back_login=====";
//    });

//    connect(ts1,&tcp_socket::fa_swap_txt,
//            this,[=](long long account_from,QString txt){
//        out<<"=====ts1:fa_swap_txt=====";
//        out<<account_from<<"|"<<txt;
////        QThread::sleep(1);
//        ts1->send_swap_txt(account_from,"fafafafafafafafafafafa");
//        out<<"=====ts1:fa_swap_txt=====";
//    });














//    QThread::sleep(1);
//    out<<"init2";
//    QThread::sleep(1);

//    tcp_socket *ts2 = new tcp_socket(this);
//    ts2->open_socket("192.168.188.2",5005);

//    connect(ts2,&tcp_socket::connected,this,[=](){
//        out<<"=====ok_socket=====";
//        ts2->send_login(1934865572,"123qwe");
//        QThread::sleep(1);
//        out<<"=====end=====";
//    });

//    QThread::sleep(1);
//    QThread::sleep(1);

//    connect(ts2,&tcp_socket::fa_back_login,this,[=](){
//QThread::sleep(1);
//        ts2->send_swap_txt(6334967572,"1111111");
//        ts2->send_swap_txt(6334967572,"12874ajshd782haudg72gayfsdg7asdu");
//        out<<"=====fa_back_login end=====";
//    });
//    QThread::sleep(1);

//    connect(ts,&tcp_socket::fa_swap_txt,this,[=](long long account_from,QString txt){
//        out<<"txt:"<<account_from<<"|"<<txt;
//    });









//    connect(ts,&tcp_socket::fa_back_login,this,[=](int flg,QString info){
//        out<<flg<<"|"<<info;
//    });

//    connect(ts,&tcp_socket::fa_back_register,
//            this,[=](long long account,QString passwd){
//        out<<account<<"|"<<passwd;
//    });

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

