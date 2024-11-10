/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *loginButton;
    QLabel *signUp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(458, 322);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #F2F2F2;  /* M\303\240u n\341\273\201n s\303\241ng (light grey) */\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 30, 301, 41));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 20px;           /* K\303\255ch th\306\260\341\273\233c font */\n"
"    font-weight: bold;         /* L\303\240m \304\221\341\272\255m ch\341\273\257 */\n"
"    color: #4CAF50;      /* M\303\240u n\341\273\201n xanh */\n"
"    text-align: center;        /* C\304\203n gi\341\273\257a ti\303\252u \304\221\341\273\201 */\n"
"    text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.5); /* Hi\341\273\207u \341\273\251ng b\303\263ng \304\221\341\273\225 */\n"
"}\n"
""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 100, 81, 17));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #4CAF50;\n"
"}"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 170, 81, 17));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #4CAF50;\n"
"}"));
        username = new QLineEdit(centralwidget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(100, 100, 311, 31));
        username->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #fff;\n"
"    border: 2px solid #D1D1D4;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: 700;\n"
"    color: #4C489D;\n"
"    transition: 0.3s;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #6A679E; /* \304\220\341\273\225i m\303\240u \304\221\306\260\341\273\235ng vi\341\273\201n khi tr\306\260\341\273\235ng nh\341\272\255p \304\221\306\260\341\273\243c focus */\n"
"    background-color: #f0f0f0; /* Thay \304\221\341\273\225i m\303\240u n\341\273\201n khi focus */\n"
"    box-shadow: 0 0 5px rgba(106, 103, 158, 0.5); /* Th\303\252m hi\341\273\207u \341\273\251ng b\303\263ng khi focus */\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #7875B5; /* M\303\240u s\341\272\257c cho placeholder (v\303\255 d\341\273\245: \"Enter username\") */\n"
"    font-style: italic;\n"
"}\n"
""));
        password = new QLineEdit(centralwidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(100, 160, 311, 31));
        password->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #fff;\n"
"    border: 2px solid #D1D1D4;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: 700;\n"
"    color: #4C489D;\n"
"    transition: 0.3s;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #6A679E; /* \304\220\341\273\225i m\303\240u \304\221\306\260\341\273\235ng vi\341\273\201n khi tr\306\260\341\273\235ng nh\341\272\255p \304\221\306\260\341\273\243c focus */\n"
"    background-color: #f0f0f0; /* Thay \304\221\341\273\225i m\303\240u n\341\273\201n khi focus */\n"
"    box-shadow: 0 0 5px rgba(106, 103, 158, 0.5); /* Th\303\252m hi\341\273\207u \341\273\251ng b\303\263ng khi focus */\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #7875B5; /* M\303\240u s\341\272\257c cho placeholder (v\303\255 d\341\273\245: \"Enter username\") */\n"
"    font-style: italic;\n"
"}\n"
""));
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(180, 220, 111, 41));
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;      /* M\303\240u n\341\273\201n xanh */\n"
"    color: white;                    /* M\303\240u ch\341\273\257 tr\341\272\257ng */\n"
"    border: 2px solid #4CAF50;      /* Vi\341\273\201n n\303\272t v\341\273\233i m\303\240u xanh */\n"
"    border-radius: 10px;             /* Bo tr\303\262n c\303\241c g\303\263c */\n"
"    padding: 10px 20px;              /* Kho\341\272\243ng c\303\241ch gi\341\273\257a ch\341\273\257 v\303\240 vi\341\273\201n */\n"
"    font-size: 16px;                 /* K\303\255ch th\306\260\341\273\233c ch\341\273\257 */\n"
"    font-weight: bold;               /* L\303\240m ch\341\273\257 \304\221\341\272\255m */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;      /* M\303\240u n\341\273\201n khi hover (di chu\341\273\231t v\303\240o) */\n"
"    border: 2px solid #45a049;      /* M\303\240u vi\341\273\201n khi hover */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #388E3C;      /* M\303\240u n\341\273\201n "
                        "khi nh\341\272\245n */\n"
"    border: 2px solid #388E3C;      /* M\303\240u vi\341\273\201n khi nh\341\272\245n */\n"
"}\n"
""));
        signUp = new QLabel(centralwidget);
        signUp->setObjectName(QString::fromUtf8("signUp"));
        signUp->setGeometry(QRect(110, 270, 281, 17));
        signUp->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #4CAF50;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Project Manager Appalication", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Username: ", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Password: ", nullptr));
        loginButton->setText(QApplication::translate("MainWindow", "Login", nullptr));
        signUp->setText(QApplication::translate("MainWindow", "Sign up for project manager appalication", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
