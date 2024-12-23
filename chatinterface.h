#ifndef CHATINTERFACE_H
#define CHATINTERFACE_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class ChatInterface; }
QT_END_NAMESPACE

class ChatInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatInterface(QTcpSocket *socket, const QString &nickname, QWidget *parent = nullptr);
    ~ChatInterface();

private slots:
    void on_pushButton_clicked(); // 发送按钮点击事件
    void on_pushButton_2_clicked(); // 退出按钮点击事件
    void readServerData(); // 读取服务器数据
    void updateUserList(const QStringList &users); // 更新在线用户列表

private:
    Ui::ChatInterface *ui;
    QTcpSocket *tcpSocket;
    QString nickname; // 用户昵称
};

#endif // CHATINTERFACE_H

