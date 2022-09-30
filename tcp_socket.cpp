#include "tcp_socket.h"

tcp_socket::tcp_socket(QObject *parent)
    : QTcpSocket{parent}
{

}

void tcp_socket::open_socket(QString IP, int port)
{
    this->connectToHost(IP,port);//寻找连接对象

    //创建连接并获取socket
    connect(this,&tcp_socket::connected,[=](){
        emit fa_connect_socket();

//        //传送内容信号
//        connect(this,&tcp_socket::readyRead,[=](){

//        });
    });
}

void tcp_socket::write_word(QString ip, int port, QString word)
{
    //发送格式：#####[IP]#####[port]#####[wordsize]#####word
    QString temp=v_flg+ip+v_flg+
                QString::number(port)+v_flg+
                QString::number(word.size())+v_flg;
    temp+=word;
    this->write(temp.toUtf8());
}


#include <QDebug>
#define out qDebug()

QString tcp_socket::get_host_ip()
{
    //获取自身IP地址 （本机IP）
    for(auto address : QNetworkInterface::allAddresses())
    {
        //只要IPv4
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
            return address.toString();//地址转文本
    }
    return "";
}
