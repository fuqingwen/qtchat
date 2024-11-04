#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>

class Server:public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();

    void Connect(int port);
    void sendData(QString text);
    QString getConnect();

signals:
    void playerConnected();
    void getMessage();

private slots:
    void receiveData();
    void getMessage();

private:
    QTcpServer *tcpServer;
    QTcpSocket socket;
    QString str;

}

#endi