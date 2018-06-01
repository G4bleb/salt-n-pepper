#include "menuquestion.hpp"
#include "ui_menuquestion.h"

MenuQuestion::MenuQuestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuQuestion)
{
    ui->setupUi(this);
}

MenuQuestion::~MenuQuestion()
{
    delete ui;
}


void MenuQuestion::on_pushButton_returnMainMenu_clicked()
{
    hide();
}


void MenuQuestion::on_pushButton_consult_clicked()
{
    hide();
    menuProposition = new MenuProposition(this);
    menuProposition->show();
}
