// MainWindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Client.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent, Client &client);  // Sử dụng tham chiếu
    ~MainWindow();

private slots:
    void Login();

    void onSignup();

    void Signup();

    void onLogin();

private:
    Ui::MainWindow *ui;
    Client &client;  // Giữ client dưới dạng tham chiếu
};
#endif // MAINWINDOW_H
