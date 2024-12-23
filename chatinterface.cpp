#include "chatinterface.h"
#include "ui_chatinterface.h"
#include <QMessageBox>
#include <QDebug>

ChatInterface::ChatInterface(QTcpSocket *socket, const QString &nickname, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChatInterface),
    tcpSocket(socket),
    nickname(nickname)
{
    ui->setupUi(this);

    // 设置窗口标题为用户昵称
    this->setWindowTitle(nickname + "的聊天室");

    // 连接信号和槽
    //connect(ui->pushButton, &QPushButton::clicked, this, &ChatInterface::on_pushButton_clicked);
    //connect(ui->pushButton_2, &QPushButton::clicked, this, &ChatInterface::on_pushButton_2_clicked);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &ChatInterface::readServerData);
}

ChatInterface::~ChatInterface()
{
    delete ui;
}

void ChatInterface::on_pushButton_clicked()
{
    QString message = ui->lineEdit->text();
    if (!message.isEmpty()) {
        // 发送的消息格式为 昵称: msg
        QString sendMessage = QString("%1: %2").arg(nickname).arg(message);
        tcpSocket->write(sendMessage.toUtf8());

        // 在本地聊天框中显示自己发送的消息
        ui->textEdit->append(QString("<b>%1</b>: %2").arg(nickname).arg(message));

        ui->lineEdit->clear();
    }
}


void ChatInterface::on_pushButton_2_clicked()
{
    // 发送退出消息给服务器
    QString sendMessage=QString("EXIT:%1").arg(nickname);
    tcpSocket->write(sendMessage.toUtf8());
    // 关闭套接字连接
    tcpSocket->disconnectFromHost();
    // 关闭聊天室窗口

    this->close();
}

void ChatInterface::readServerData()
{
    QByteArray data = tcpSocket->readAll();
    QString message = QString::fromUtf8(data);

    if (message.startsWith("UPDATE_USERS:")) {
        QStringList users = message.mid(13).split(",");
        updateUserList(users);
    }

    // 解析广播消息
    if (message.contains(":")) {
        QStringList parts = message.split(":");
        if (parts.size() == 2) {
            QString senderNickname = parts[0].trimmed();
            QString msg = parts[1].trimmed();
            // 检查是否是自己的消息，如果不是自己的消息则显示
            if (senderNickname != nickname && senderNickname!="UPDATE_USERS")
            {
                ui->textEdit->append(QString("<b>%1</b>: %2").arg(senderNickname).arg(msg));
            }
        } else {
            // 如果不是消息格式，可能是在线用户列表更新
            // 这里只是一个示例，根据实际的服务器协议进行处理
            QStringList users = message.split(",");
            updateUserList(users);
        }
    } else {
        // 直接显示消息（例如系统消息）
        ui->textEdit->append(message);
    }
}

void ChatInterface::updateUserList(const QStringList &users)
{
    ui->listWidget->clear();
    for (const QString &user : users) {
        if (!user.isEmpty()) {
            QListWidgetItem *item = new QListWidgetItem(user.trimmed());
            ui->listWidget->addItem(item);
        }
    }
}


