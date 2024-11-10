#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <string>

MainWindow::MainWindow(QWidget *parent, ViewManager* viewManager)  // Nhận ViewManager từ ngoài
    : QMainWindow(parent), ui(new Ui::MainWindow), viewManager(viewManager)  // Khởi tạo viewManager
{
    ui->setupUi(this);

    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::Login);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Login()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    std::string resquest_send = "LOGIN " + username.toStdString() + " " + password.toStdString();
    std::string reponse = viewManager->getClient().send_request(resquest_send);  // Sử dụng viewManager
    std::cout << "Response from server: " << reponse << std::endl;

    // Kiểm tra đăng nhập thông qua phản hồi từ server
    if (reponse.find("SUCCESS") != std::string::npos)
    {
        // Đăng nhập thành công, chuyển sang Dialog view
        QMessageBox::information(this, "Login Success", "You have successfully logged in.");
        viewManager->showDialogView();  // Dùng viewManager để chuyển view
    }
    else
    {
        // Hiển thị lỗi từ server
        QMessageBox::warning(this, "Login Failed", "Error: " + QString::fromStdString(reponse));
    }
}
