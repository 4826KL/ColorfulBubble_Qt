#include "return.h"
#include "ui_return.h"

return::return(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::return)
{
    ui->setupUi(this);
}

return::~return()
{
delete ui;
}
