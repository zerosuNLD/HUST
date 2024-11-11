#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <string>

MainWindow::MainWindow(QWidget *parent, Client &client)  // Sử dụng tham chiếu
    : QMainWindow(parent), ui(new Ui::MainWindow), client(client)
{
    ui->setupUi(this);
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::Login);

    ui->signUp->setTextFormat(Qt::RichText);
    ui->signUp->setText("<a href=\"#\">Sign up for project manager application</a>");
    ui->signUp->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->signUp->setOpenExternalLinks(false);

    // Kết nối linkActivated của signUp với slot onSignup
    connect(ui->signUp, &QLabel::linkActivated, this, &MainWindow::onSignup);

    connect(ui->Signup, &QPushButton::clicked, this, &MainWindow::Signup);  // Fixed missing semicolon

    ui->onLogin->setTextFormat(Qt::RichText);
    ui->onLogin->setText("<a href=\"#\">Already have an account?</a>");
    ui->onLogin->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->onLogin->setOpenExternalLinks(false);

    connect(ui->onLogin, &QLabel::linkActivated, this, &MainWindow::onLogin);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Login()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    std::string request_mes = "LOGIN " + username.toStdString() + " " + password.toStdString();
    std::string response = client.send_request(request_mes);

    // Kiểm tra đăng nhập thông qua phản hồi từ server
    if (response.find("SUCCESS") != std::string::npos)
    {
        // Đăng nhập thành công, chuyển sang trang tiếp theo trong QStackedWidget
        QMessageBox::information(this, "Login Success", "You have successfully logged in.");
    }
    else
    {
        // Hiển thị lỗi từ server
        QMessageBox::warning(this, "Login Failed", "Error: " + QString::fromStdString(response));
    }
}

void MainWindow::onSignup()
{
    // Chuyển sang trang đăng ký trong QStackedWidget
    ui->stackedWidget->setCurrentIndex(1);  // Chỉ mục của trang đăng ký
}

void MainWindow::Signup()
{
    QString username = ui->username_signup->text();
    QString password = ui->password_signup->text();
    QString re_password = ui->password_re_signup->text();
    QString name = ui->name->text();
    QString age = ui->age->text();
    QString email = ui->email->text();

    if (re_password != password) {
        QMessageBox::warning(this, "Signup Failed", "Error: password and re_password do not match.");
    } else {
        std::string request_mes = "SIGNUP CHECK_USER_CREDENTIALS " + username.toStdString() + " " + password.toStdString();
        std::string response = client.send_request(request_mes);

        if (response == "ERROR: Username hoặc password không đúng!") {
            ui->stackedWidget->setCurrentIndex(2);
            std::string request_mes = "SIGNUP ADD_NEW_USER " + username.toStdString() + " " + password.toStdString() + " " + name.toStdString() + " " +
                    age.toStdString() + " " + email.toStdString();
            response = client.send_request(request_mes);  // Fixed variable name typo
            if (response.find("SUCCESS") != std::string::npos) {
                 QMessageBox::information(this, "Signup Success", QString::fromStdString(response));
                 ui->stackedWidget->setCurrentIndex(0);
            } else {
                // Display error from server
                QMessageBox::warning(this, "Signup Failed", QString::fromStdString(response));
            }
        } else {
            QMessageBox::warning(this, "Signup Failed", "Error: Account already exists.");
        }
    }
}


void MainWindow::onLogin()
{
     ui->stackedWidget->setCurrentIndex(0);
}
