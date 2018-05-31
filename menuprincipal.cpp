#include "menuprincipal.hpp"
#include "ui_menuprincipal.h"

MenuPrincipal::MenuPrincipal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuPrincipal)
{
    ui->setupUi(this);
}

MenuPrincipal::~MenuPrincipal()
{
    delete ui;
}


void MenuPrincipal::on_pushButton_consulter_theme_clicked()
{
    hide();
    menuQuestion = new MenuQuestion(this);
    menuQuestion->show();
}
