#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();
    
    void Connect(int port);
    void sendData(QString text);
    QString getContent();

signals:
    void playerConnected();
    void getMessage();

private slots:
    void receiveData();
    void incomingConnection(qintptr handle);

private:
    QTcpServer *tcpServer;
    QTcpSocket socket;
    QString str;
};

#endif // SERVER_H
