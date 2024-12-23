#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chatinterface.h"
#include"ui_chatinterface.h"

#include <QMessageBox>
#include <QDebug>
#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , tcpSocket(new QTcpSocket(this))
    , chatWindow(nullptr) // 初始化聊天室窗口
{
    ui->setupUi(this);

    // 绑定套接字信号和槽
    //connect(tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::readServerData);
    connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error),
            this, &MainWindow::displayError);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 登录按钮点击事件
void MainWindow::on_pushButton_clicked()
{
    QString serverIP = ui->lineEdit->text();  // 获取服务器IP地址
    QString nickname = ui->lineEdit_2->text(); // 获取用户昵称

    if (serverIP.isEmpty() || nickname.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "服务器IP地址或昵称不能为空！");
        return;
    }

    // 连接服务器
    tcpSocket->connectToHost(QHostAddress(serverIP), 1234); // 端口号为1234
    if (tcpSocket->waitForConnected(3000)) { // 等待3秒连接
        QMessageBox::information(this, "成功", "连接服务器成功！");

        // 向服务器发送用户昵称
        QString loginMessage = QString("LOGIN:%1").arg(nickname);
        tcpSocket->write(loginMessage.toUtf8());

        // 显示聊天室窗口
        chatWindow = new ChatInterface(tcpSocket,nickname); // 传入 tcpSocket
        chatWindow->show();                        // 显示 ChatInterface 窗口

        this->close(); // 隐藏登录窗口
        disconnect(tcpSocket, &QTcpSocket::readyRead, this, &MainWindow::readServerData);
    } else {
        QMessageBox::warning(this, "连接失败", "无法连接到服务器，请检查IP地址和端口！");
    }
}

// 读取服务器发送的数据
void MainWindow::readServerData()
{
    QByteArray data = tcpSocket->readAll();
    QString message = QString::fromUtf8(data);

    qDebug() << "收到服务器消息：" << message;
}

// 处理套接字错误
void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
    Q_UNUSED(socketError);
    QMessageBox::warning(this, "网络错误", tcpSocket->errorString());
    qDebug() << "网络错误：" << tcpSocket->errorString();
}



