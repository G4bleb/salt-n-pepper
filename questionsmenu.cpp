#include "questionsmenu.hpp"
#include "ui_questionsmenu.h"

QuestionsMenu::QuestionsMenu(Driver * driver_first_window,Connection * con_first_window,int selected_id_topic,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QuestionsMenu)
{
    ui->setupUi(this);
    lastWindow = parent;

    this->id_topic=selected_id_topic;
    this->driver_second_window=driver_first_window;

    cout << "Numéro de l'id:" << id_topic << endl;

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
