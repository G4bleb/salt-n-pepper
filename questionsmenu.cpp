#include "questionsmenu.hpp"
#include "ui_questionsmenu.h"

QuestionsMenu::QuestionsMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestionsMenu)
{
    ui->setupUi(this);
    lastWindow = parent;
}

QuestionsMenu::~QuestionsMenu()
{
    delete ui;
}

void QuestionsMenu::on_pushButton_return_clicked()
{
    this->hide();
    lastWindow->show();
    this->deleteLater();
}

void QuestionsMenu::on_pushButton_select_clicked()
{
    this->hide();
    propositionsMenu = new PropositionsMenu(this);
    propositionsMenu->show();
}
