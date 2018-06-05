#include "mainmenu.hpp"
#include "ui_mainmenu.h"

MainMenu::MainMenu(Driver *driver,Connection *con,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    menuConnexion=parent;

    stmt_show_user=con->createStatement();
    res_show_user=stmt_show_user->executeQuery("SELECT id_user,login,best_score FROM user");
    row_table=k=0;

    column_table=ui->tableWidget_User->columnCount();

     /*while(res_show_user->next()){
        vecteurLabel.append(new QLabel(res_show_user->getString(1).c_str()));
        vecteurLabel.append(new QLabel(res_show_user->getString(2).c_str()));
        vecteurLabel.append(new QLabel(res_show_user->getString(3).c_str()));
        row_table++;
    }

    ui->tableWidget_User->setRowCount(row_table);

    for(int i=0;i<row_table;i++){
        for(int j=0;j<column_table;j++){
        ui->tableWidget_User->setCellWidget(i,j,vecteurLabel[k]);
        k++;
       }
    }*/
    while(res_show_user->next()){
        QVector <QLabel*> vecteurLabel;
        vecteurLabel.append(new QLabel(res_show_user->getString(1).c_str()));
        vecteurLabel.append(new QLabel(res_show_user->getString(2).c_str()));
        vecteurLabel.append(new QLabel(res_show_user->getString(3).c_str()));
        vecteurLabels.append(vecteurLabel);
        row_table++;
    }
    ui->tableWidget_User->setRowCount(row_table);
    for(int i=0;i<row_table;i++){
        for(int j=0;j<column_table;j++){
        ui->tableWidget_User->setCellWidget(i,j,vecteurLabels[i][j]);
        k++;
        qDebug()<<vecteurLabels[i][j]->text();
       }
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

void MainMenu::on_tableWidget_User_cellClicked(int row, int column)
{
    if(column=1) ui->lineEdit_login->setText(vecteurLabels[row][column]->text());
    if(column=2) ui->lineEdit_high_score->setText(vecteurLabels[row][column]->text());
}
