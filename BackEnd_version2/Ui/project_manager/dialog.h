#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "ViewManager.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr,  ViewManager* viewManager = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    ViewManager* viewManager;
};

#endif // DIALOG_H
