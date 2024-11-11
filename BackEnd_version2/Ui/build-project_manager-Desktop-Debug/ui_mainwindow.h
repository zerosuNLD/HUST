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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *loginButton;
    QLabel *signUp;
    QLineEdit *password;
    QLabel *label_3;
    QLineEdit *username;
    QLabel *label_2;
    QLabel *label;
    QWidget *page_2;
    QLineEdit *username_signup;
    QLineEdit *password_signup;
    QLineEdit *password_re_signup;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *Signup;
    QLabel *onLogin;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *name;
    QLineEdit *age;
    QLineEdit *email;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(601, 420);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #F2F2F2;  /* M\303\240u n\341\273\201n s\303\241ng (light grey) */\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 0, 581, 421));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        loginButton = new QPushButton(page);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(230, 280, 111, 41));
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;      /* M\303\240u n\341\273\201n xanh */\n"
"    color: white;                    /* M\303\240u ch\341\273\257 tr\341\272\257ng */\n"
"    border: 2px solid #4CAF50;      /* Vi\341\273\201n n\303\272t v\341\273\233i m\303\240u xanh */\n"
"    border-radius: 10px;             /* Bo tr\303\262n c\303\241c g\303\263c */\n"
"    padding: 10px 20px;              /* Kho\341\272\243ng c\303\241ch gi\341\273\257a ch\341\273\257 v\303\240 vi\341\273\201n */\n"
"    font-size: 16px;                 /* K\303\255ch th\306\260\341\273\233c ch\341\273\257 */\n"
"    font-weight: bold;               /* L\303\240m ch\341\273\257 \304\221\341\272\255m */\n"
"}"));
        signUp = new QLabel(page);
        signUp->setObjectName(QString::fromUtf8("signUp"));
        signUp->setGeometry(QRect(160, 330, 281, 17));
        signUp->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #4CAF50;\n"
"}"));
        password = new QLineEdit(page);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(150, 200, 311, 41));
        password->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #fff;\n"
"    border: 2px solid #D1D1D4;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: 700;\n"
"    color: #4C489D;\n"
"}"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 210, 81, 17));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #4CAF50;\n"
"}"));
        username = new QLineEdit(page);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(150, 130, 311, 41));
        username->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #fff;\n"
"    border: 2px solid #D1D1D4;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: 700;\n"
"    color: #4C489D;\n"
"}\n"
""));
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 140, 81, 17));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #4CAF50;\n"
"}"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 50, 151, 41));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 20px;           /* K\303\255ch th\306\260\341\273\233c font */\n"
"    font-weight: bold;         /* L\303\240m \304\221\341\272\255m ch\341\273\257 */\n"
"    color: #4CAF50;      /* M\303\240u n\341\273\201n xanh */\n"
"    text-align: center;        /* C\304\203n gi\341\273\257a ti\303\252u \304\221\341\273\201 */\n"
"}\n"
""));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        username_signup = new QLineEdit(page_2);
        username_signup->setObjectName(QString::fromUtf8("username_signup"));
        username_signup->setGeometry(QRect(100, 90, 131, 41));
        username_signup->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #fff;\n"
"    border: 2px solid #D1D1D4;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: 700;\n"
"    color: #4C489D;\n"
"}\n"
""));
        password_signup = new QLineEdit(page_2);
        password_signup->setObjectName(QString::fromUtf8("password_signup"));
        password_signup->setGeometry(QRect(100, 150, 131, 41));
        password_signup->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #fff;\n"
"    border: 2px solid #D1D1D4;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: 700;\n"
"    color: #4C489D;\n"
"}\n"
""));
        password_re_signup = new QLineEdit(page_2);
        password_re_signup->setObjectName(QString::fromUtf8("password_re_signup"));
        password_re_signup->setGeometry(QRect(100, 210, 131, 41));
        password_re_signup->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #fff;\n"
"    border: 2px solid #D1D1D4;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: 700;\n"
"    color: #4C489D;\n"
"}\n"
""));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 100, 81, 17));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #4CAF50;\n"
"}"));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 160, 81, 17));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #4CAF50;\n"
"}"));
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 220, 81, 17));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #4CAF50;\n"
"}"));
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(200, 20, 151, 41));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 20px;           /* K\303\255ch th\306\260\341\273\233c font */\n"
"    font-weight: bold;         /* L\303\240m \304\221\341\272\255m ch\341\273\257 */\n"
"    color: #4CAF50;      /* M\303\240u n\341\273\201n xanh */\n"
"    text-align: center;        /* C\304\203n gi\341\273\257a ti\303\252u \304\221\341\273\201 */\n"
"}\n"
""));
        Signup = new QPushButton(page_2);
        Signup->setObjectName(QString::fromUtf8("Signup"));
        Signup->setGeometry(QRect(200, 290, 111, 41));
        Signup->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;      /* M\303\240u n\341\273\201n xanh */\n"
"    color: white;                    /* M\303\240u ch\341\273\257 tr\341\272\257ng */\n"
"    border: 2px solid #4CAF50;      /* Vi\341\273\201n n\303\272t v\341\273\233i m\303\240u xanh */\n"
"    border-radius: 10px;             /* Bo tr\303\262n c\303\241c g\303\263c */\n"
"    padding: 10px 20px;              /* Kho\341\272\243ng c\303\241ch gi\341\273\257a ch\341\273\257 v\303\240 vi\341\273\201n */\n"
"    font-size: 16px;                 /* K\303\255ch th\306\260\341\273\233c ch\341\273\257 */\n"
"    font-weight: bold;               /* L\303\240m ch\341\273\257 \304\221\341\272\255m */\n"
"}"));
        onLogin = new QLabel(page_2);
        onLogin->setObjectName(QString::fromUtf8("onLogin"));
        onLogin->setGeometry(QRect(180, 360, 181, 17));
        onLogin->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #4CAF50;\n"
"}"));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(300, 100, 81, 17));
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #4CAF50;\n"
"}"));
        label_9 = new QLabel(page_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(300, 160, 81, 17));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #4CAF50;\n"
"}"));
        label_10 = new QLabel(page_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(300, 230, 81, 17));
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px;\n"
"    color: #4CAF50;\n"
"}"));
        name = new QLineEdit(page_2);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(370, 90, 131, 41));
        name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #fff;\n"
"    border: 2px solid #D1D1D4;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: 700;\n"
"    color: #4C489D;\n"
"}\n"
""));
        age = new QLineEdit(page_2);
        age->setObjectName(QString::fromUtf8("age"));
        age->setGeometry(QRect(370, 150, 131, 41));
        age->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #fff;\n"
"    border: 2px solid #D1D1D4;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: 700;\n"
"    color: #4C489D;\n"
"}\n"
""));
        email = new QLineEdit(page_2);
        email->setObjectName(QString::fromUtf8("email"));
        email->setGeometry(QRect(370, 220, 131, 41));
        email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #fff;\n"
"    border: 2px solid #D1D1D4;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: 700;\n"
"    color: #4C489D;\n"
"}\n"
""));
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        loginButton->setText(QApplication::translate("MainWindow", "Login", nullptr));
        signUp->setText(QApplication::translate("MainWindow", "Sign up for project manager appalication", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Password: ", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Username: ", nullptr));
        label->setText(QApplication::translate("MainWindow", "LOGIN HERE", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Username: ", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Password: ", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Re Password:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "SIGNUP HERE", nullptr));
        Signup->setText(QApplication::translate("MainWindow", "SIGNUP", nullptr));
        onLogin->setText(QApplication::translate("MainWindow", "Already have an account?", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Name:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Age:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Email:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
