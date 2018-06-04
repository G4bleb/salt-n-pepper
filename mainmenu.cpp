#include "mainmenu.hpp"
#include "ui_mainmenu.h"

MainMenu::MainMenu(Driver *driver,Connection *con,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    menuConnexion=parent;

    stmt=con->createStatement();
    res=stmt->executeQuery("SELECT login FROM user");

   while(res->next()){
       //ui->tableWidget_Login->setTabKeyNavigation(res->getString(1).c_str());
       cout << res->getString(1);
    }

}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_pushButton_select_clicked()
{
    this->hide();
    questionsMenu = new QuestionsMenu(this);
    questionsMenu->show();
}


void MainMenu::on_pushButton_disconnect_clicked()
{
    this->hide();
    menuConnexion->show();
    this->deleteLater();
}
