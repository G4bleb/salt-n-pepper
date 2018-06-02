#include "propositionsmenu.hpp"
#include "ui_propositionsmenu.h"

PropositionsMenu::PropositionsMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PropositionsMenu)
{
    lastWindow = parent;
    ui->setupUi(this);
}

PropositionsMenu::~PropositionsMenu()
{
    delete ui;
}

void PropositionsMenu::on_pushButton_return_clicked()
{
    this->hide();
    lastWindow->show();
}
