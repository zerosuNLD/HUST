#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <QStackedWidget>
#include "mainwindow.h"
#include "dialog.h"
#include "../../Client/Client.h"

#define POST 8080
#define localhost "127.0.0.1"

class ViewManager
{
public:
    ViewManager(QStackedWidget *stackedWidget, const Client& client);
    void showMainView();
    void showDialogView();
    QStackedWidget* getView();  // Trả về view hiện tại
    Client getClient();  // Trả về client

private:
    QStackedWidget *stackedWidget;
    MainWindow *mainWindow;
    Dialog *dialog;
    Client client;
};

#endif // VIEWMANAGER_H
