#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, ViewManager* viewManager) :
    QDialog(parent),
    ui(new Ui::Dialog),
    viewManager(viewManager)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
