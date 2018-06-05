#include "mainmenu.hpp"
#include "ui_mainmenu.h"

MainMenu::MainMenu(Driver *driver,Connection *con,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    menuConnexion=parent;

    stmt=con->createStatement();
    res=stmt->executeQuery("SELECT id_user,login FROM user");

    while(res->next()){
        vecteurLabel.push_back(new QLabel(res->getString(1).c_str()));
        vecteurLabel.push_back(new QLabel(res->getString(2).c_str()));
        cout << res->getString(1).c_str() << endl;
        cout << res->getString(2).c_str() << endl;
    }

    /*for(int i=0;i<vecteurLabel->size();i++){
        cout << vecteurLabel->at(i) << endl;
    }*/

    /*for(int i=0;i<vecteurLabel.size();i++){
        for(int j=0;j<vecteurLabel.size();j++){
            cout << "Je suis rentré dans la boucle for" << endl;
            cout << vecteurLabel[i] << endl;
            //ui->tableWidget_Login->setCellWidget(i,j,vecteurLabel[i]);
        }
    }*/

    /*while(res->next()){
      ui->tableWidget_Login->setRowCount(row+1);
      ui->tableWidget_Login->setCellWidget(0,row,new QLabel(res->getString(1).c_str()));
      row++;
      cout << "Login "<<k<<":"<< res->getString(1) << endl;
      k++;
    }*/


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
