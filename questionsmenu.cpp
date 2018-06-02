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
    hide();
    lastWindow->show();
}

void QuestionsMenu::on_pushButton_select_clicked()
{
    hide();
    propositionsMenu = new PropositionsMenu(this);
    propositionsMenu->show();
}
