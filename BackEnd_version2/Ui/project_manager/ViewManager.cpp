#include "ViewManager.h"

ViewManager::ViewManager(QStackedWidget *stackedWidget, const Client& client)
    : stackedWidget(stackedWidget), client(client)
{
    // Đối tượng MainWindow và Dialog không được tạo ở đây nữa,
    // vì chúng sẽ được khởi tạo trong main.cpp và truyền vào.
}

void ViewManager::showMainView()
{
    stackedWidget->setCurrentWidget(mainWindow);  // Chuyển sang MainWindow
}

void ViewManager::showDialogView()
{
    stackedWidget->setCurrentWidget(dialog);  // Chuyển sang Dialog
}

QStackedWidget* ViewManager::getView()
{
    return stackedWidget;
}

Client ViewManager::getClient()
{
    return client;
}
