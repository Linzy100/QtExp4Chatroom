#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include "chatinterface.h" // 引入ChatInterface类
#include"ui_chatinterface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();  // 登录按钮点击事件
    void readServerData();          // 读取服务器数据
    void displayError(QAbstractSocket::SocketError socketError);  // 网络错误处理

private:
    Ui::MainWindow *ui;
    QTcpSocket *tcpSocket;          // 网络套接字
    ChatInterface *chatWindow;      // 聊天室窗口
};

#endif // MAINWINDOW_H

