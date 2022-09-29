#ifndef TCP_SOCKET_H
#define TCP_SOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QNetworkInterface>

class tcp_socket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit tcp_socket(QObject *parent = nullptr);
    void open_socket(QString IP,int port);//连接服务器
    void write_word(QString ip, int port, QString word);//参数:文字
    void write_word(QString account, QString word);//参数:文字

    QString get_host_ip();//获取本机IP
    QString read_word();

signals:
    emit void fa_connect_socket();
    emit void fa_read();

protected:
    QString v_flg="#####";
};

#endif // TCP_SOCKET_H
