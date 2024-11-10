#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ViewManager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, ViewManager* viewManager = nullptr);  // Thêm tham số cho ViewManager
    ~MainWindow();

private slots:
    void Login();

private:
    Ui::MainWindow *ui;
    ViewManager* viewManager;  // Thêm thành viên cho ViewManager
};

#endif // MAINWINDOW_H
