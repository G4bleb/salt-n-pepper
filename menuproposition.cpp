#include "menuproposition.hpp"
#include "ui_menuproposition.h"

MenuProposition::MenuProposition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuProposition)
{
    ui->setupUi(this);
}

MenuProposition::~MenuProposition()
{
    delete ui;
}
