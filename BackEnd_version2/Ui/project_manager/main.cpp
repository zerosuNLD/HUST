#include "ViewManager.h"
#include <QApplication>
#include <QStackedWidget>
#include "../../Client/Client.h"
#include "mainwindow.h"

#define POST 8080
#define localhost "127.0.0.1"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Tạo đối tượng Client
    Client client(localhost, POST);  // Khởi tạo client

    // Tạo QStackedWidget để quản lý các view
    QStackedWidget stackedWidget;

    // Tạo đối tượng ViewManager để quản lý chuyển đổi view
    ViewManager viewManager(&stackedWidget, client);  // Truyền client vào ViewManager

    // Tạo MainWindow và truyền ViewManager vào
    MainWindow w(nullptr, &viewManager);

    // Hiển thị MainWindow thông qua ViewManager
    viewManager.showMainView();

    w.show();  // Hiển thị MainWindow

    return a.exec();
}
