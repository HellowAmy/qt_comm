#ifndef TCP_SOCKET_H
#define TCP_SOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QHostAddress>
#include <QMap>

#include <string>


#include "protocol/ux_protocol.h"



class tcp_socket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit tcp_socket(QObject *parent = nullptr);
    void open_socket(QString IP,int port);//开启连接

    //===== 连接服务器请求接口函数 =====
    bool send_login(long long account, const char *passwd);//账号登录
    bool send_register(const char *passwd);//注册账号
    bool send_logout();//账号退出
    bool send_swap_txt(long long to_account,QString data);//数据转发
    //===== 连接服务器请求接口函数 =====



signals:
    emit void fa_back_register(long long account,QString passwd);
    emit void fa_back_login(int flg,QString info);
    emit void fa_swap_txt(long long account_from,QString txt);

protected:
    long long v_account = 0;//登录账号
    bool is_login = false;//登录状态

    //接收函数的函数指针容器
    QMap <enum_transmit,bool (tcp_socket::*)()> map_func;

    void recv_news();//接收反馈信息

    //发送反馈函数
    template<class Tcmd,class Tct>
    bool send_back(Tcmd cmd,Tct ct);

    //===== back接收函数特点 =====
    //必须带有返回值bool，返回值标记是否完成传输
    //如果返回true表示本次接收完成，下次读取数据将重新进入包头解析
    bool back_register();//账号注册反馈
    bool back_login();//账号登录反馈
    bool back_swap_txt();//数据转发接收
    //===== back接收函数特点 =====
};

#endif // TCP_SOCKET_H
