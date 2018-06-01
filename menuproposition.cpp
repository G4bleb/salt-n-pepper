#include "menuproposition.hpp"
#include "ui_menuproposition.h"

MenuProposition::MenuProposition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuProposition)
{
    lastWindow = parent;
    ui->setupUi(this);
}

MenuProposition::~MenuProposition()
{
    delete ui;
}

void MenuProposition::on_pushButton_return_clicked()
{
    this->hide();
    lastWindow->show();
}
