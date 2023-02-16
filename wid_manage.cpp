#include "wid_manage.h"

#include <QTimer>

wid_manage::wid_manage(QWidget *parent)
    : QObject{parent}
{
    v_net = new net_connect;
    if(v_net->open_connect() < 0) { vloge("open_connect err"); };

    v_login = new wid_login;//登录窗口
    v_login->show();

    v_friends_list = new wid_friends_list;//好友列表
    v_friends_list->close();

//    QVector<ct_friends_info> vec;
//    vec.push_back(ct_friends_info{1256757890,"ty1256757890"});
//    vec.push_back(ct_friends_info{1251251890,"t212y1251251890"});
//    vec.push_back(ct_friends_info{1212471890,"1212471890"});
//    vec.push_back(ct_friends_info{3456757890,"阿uh"});
//    vec.push_back(ct_friends_info{6786757890,"阿角色大赛的"});
//    vec.push_back(ct_friends_info{1256757890,"4574"});
//    vec.push_back(ct_friends_info{8568464564,"3498斯蒂芬"});

    QMap<long long,string> map;
    map.insert(1045809651,"1045809651");
    map.insert(1707618208,"1707618208");

    v_friends_list->into_friends(map);

//    1045809651123qwe
//    1707618208123456
//    1746135720123456
//    1934865572123qwe
//    2510663968123456
//    2529453605123456
//    2990771611123456
//    3359116136123qwe
//    3467939625123456
//    4093996320123qwe
//    4287066047123456
//    5429832273123456
//    5511780295123qwe
//    5512053180123456


    //发送--发送到网络//========================
    connect(v_friends_list,&wid_friends_list::fa_send_news,this,
            [=](en_info en,long long account,string info){

        if(en == en_info::e_send_txt)
        {
            vlogf("e_send_txt" vv(account) vv(info));
            v_net->ask_swap_txt(account,info);
        }
        else if(en == en_info::e_send_pic)
        {
            vlogf("e_send_pic" vv(account) vv(info));
            QFileInfo info_file(QString::fromStdString(info));
            v_net->ask_swap_file(account,info_file.fileName().toStdString(),info,en_build_file::e_spic);
        }
        else if(en == en_info::e_send_file)
        {
            vlogf("e_send_file" vv(account) vv(info));
            QFileInfo info_file(QString::fromStdString(info));
            v_net->ask_swap_file(account,info_file.fileName().toStdString(),info,en_build_file::e_file);
        }
    });

    //发送--发送到网络//========================
    connect(v_login,&wid_login::fa_login,this,
            [=](long long account,string passwd){

        vlogf("fa_login" vv(account) vv(passwd));
        v_net->ask_login(account,passwd);
    });

    //网络返回--注册//========================
    connect(v_login,&wid_login::fa_register,this,
            [=](string name,string passwd){

        vlogf("fa_register" vv(passwd) vv(name));
        v_net->ask_register(passwd);
    });

    //===== 网络反馈 =====
    //==服务器响应
    connect(v_net,&net_connect::fa_open,this,[=](){
        vlogf("fa_open");//
    });

    connect(v_net,&net_connect::fa_close,this,[=](){
        vlogf("fa_close");//
    });

    connect(v_net,&net_connect::fa_register_back,this,
            [=](long long account,string passwd,bool ok){

        vlogf("fa_register" vv(account) vv(passwd) vv(ok));//
    });

    connect(v_net,&net_connect::fa_login_back,this,
            [=](long long account,bool ok){

        vlogf("fa_login_back" vv(account) vv(ok));
        if(ok) v_friends_list->show();
    });

    connect(v_net,&net_connect::fa_logout_back,this,
            [=](long long account,bool ok){

        vlogf("fa_logout_back" vv(account) vv(ok));
        if(ok) v_net->close_connect();
    });

    connect(v_net,&net_connect::fa_recover_passwd_back,this,
            [=](long long account,string passwd,bool ok){

        vlogf("fa_recover_passwd_back" vv(account) vv(passwd) vv(ok));//
        if(ok) v_net->close_connect();
    });

    emit void fa_swap_txt(long long account_from,string txt);
    emit void fa_swap_file_finish(long long account_from,string filename,en_build_file type,bool is_ok);
    emit void fa_swap_file_ret(long long account_from,string filename,bool is_ok);
    emit void fa_swap_error(long long account_from,en_swap_error err);

    connect(v_net,&net_connect::fa_swap_txt,this,
            [=](long long account_from,string txt){

        vlogf("fa_prog_send" vv(account_from) vv(txt));//
        v_friends_list->into_news(en_info::e_send_txt,account_from,QString::fromStdString(txt));
    });

    connect(v_net,&net_connect::fa_swap_file_finish,this,
            [=](long long account_from,string filename,en_build_file type,bool is_ok){

        if(type == en_build_file::e_file)
        {
            int now = 99;
            if(is_ok) now = 100;
            //文件进度(需要三个字段:文件名,进度值,是否完成(prog/finish))(分割符:##)
            QString info = QString::fromStdString(filename)+"##"+QString::number(now)+"finish";
            v_friends_list->into_news(en_info::e_send_file_prog,account_from,info);
        }
        else if(type == en_build_file::e_spic)
        { v_friends_list->into_news(en_info::e_send_pic,account_from,QString::fromStdString(filename)); }

        vlogf("fa_swap_file_finish" vv(account_from) vv(filename) vv(type) vv(is_ok));//
    });

    connect(v_net,&net_connect::fa_swap_file_ret,this,
            [=](long long account_from,string filename,en_build_file type,bool is_ok){

        if(type == en_build_file::e_file)
        {
            int now = 99;
            if(is_ok) now = 100;
            //文件进度(需要三个字段:文件名,进度值,是否完成(prog/finish))(分割符:##)
            QString info = QString::fromStdString(filename)+"##"+QString::number(now)+"finish";
            v_friends_list->into_news(en_info::e_send_file_prog,account_from,info);
        }
        else if(type == en_build_file::e_spic)
        { v_friends_list->into_news(en_info::e_send_pic,account_from,QString::fromStdString(filename)); }

        vlogf("fa_swap_file_ret" vv(account_from) vv(filename) vv(type) vv(is_ok));//
    });


    //==数据交换
    connect(v_net,&net_connect::fa_prog_send,this,
            [=](string filename,long long account_from,int now){

        //文件进度(需要三个字段:文件名,进度值,是否完成(prog/finish))(分割符:##)
        QString info = QString::fromStdString(filename)+"##"+QString::number(now)+"prog";
        v_friends_list->into_news(en_info::e_send_file_prog,account_from,info);
        vlogf("fa_prog_send" vv(filename) vv(now) vv(info.toStdString()));//
    });

    connect(v_net,&net_connect::fa_prog_recv,this,
            [=](string filename,long long account_from,int now){

        QString info = QString::fromStdString(filename)+"##"+QString::number(now)+"prog";
        v_friends_list->into_news(en_info::e_send_file_prog,account_from,info);
        vlogf("fa_prog_recv" vv(filename) vv(now) vv(info.toStdString()));//
    });


    //===== 网络反馈 =====
}

wid_manage::~wid_manage()
{
    delete v_login;
    delete v_friends_list;
    delete v_net;
}

bool wid_manage::init_net()
{
    return true;
}
