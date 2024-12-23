/********************************************************************************
** Form generated from reading UI file 'chatinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATINTERFACE_H
#define UI_CHATINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatInterface
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QTextEdit *textEdit;
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChatInterface)
    {
        if (ChatInterface->objectName().isEmpty())
            ChatInterface->setObjectName(QString::fromUtf8("ChatInterface"));
        ChatInterface->resize(800, 600);
        centralwidget = new QWidget(ChatInterface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 801, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(13, 76, 641, 411));
        textEdit->setReadOnly(true);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(670, 80, 111, 411));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(12, 510, 541, 41));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(580, 520, 93, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(690, 520, 93, 28));
        ChatInterface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChatInterface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        ChatInterface->setMenuBar(menubar);
        statusbar = new QStatusBar(ChatInterface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChatInterface->setStatusBar(statusbar);

        retranslateUi(ChatInterface);

        QMetaObject::connectSlotsByName(ChatInterface);
    } // setupUi

    void retranslateUi(QMainWindow *ChatInterface)
    {
        ChatInterface->setWindowTitle(QCoreApplication::translate("ChatInterface", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("ChatInterface", "\346\236\227\346\242\223\351\233\204\347\232\204\350\201\212\345\244\251\345\256\244", nullptr));
        pushButton->setText(QCoreApplication::translate("ChatInterface", "\345\217\221\351\200\201", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ChatInterface", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatInterface: public Ui_ChatInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATINTERFACE_H
