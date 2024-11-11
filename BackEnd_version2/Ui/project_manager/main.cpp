#include "mainwindow.h"
#include <QApplication>
#include <Client.h>

#define POST 8080
#define localhost "127.0.0.1"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Khởi tạo client
    Client client(localhost, POST);

    // Tạo và hiển thị giao diện người dùng, truyền client vào MainWindow
    MainWindow w(nullptr, client);
    w.show();

    // Chạy ứng dụng Qt
    return a.exec();
}
