#include "mainmenu.hpp"
#include "ui_mainmenu.h"

MainMenu::MainMenu(Driver *driver,Connection *con,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    menuConnexion=parent;
    this->con_user = con;
    this->driver_user=driver;


     ui->pushButton_modify_user->setEnabled(false);
     ui->lineEdit_high_score->setEnabled(false);
     ui->lineEdit_login->setEnabled(false);

    stmt_show_user=con_user->createStatement();
    res_show_user=stmt_show_user->executeQuery("SELECT id_user,login,best_score FROM user");

    row_table=0;
    column_table=ui->tableWidget_User->columnCount();

    while(res_show_user->next()){
        QVector <QLabel*> vecteurLabel;
        vecteurLabel.append(new QLabel(res_show_user->getString(1).c_str()));
        vecteurLabel.append(new QLabel(res_show_user->getString(2).c_str()));
        vecteurLabel.append(new QLabel(res_show_user->getString(3).c_str()));
        vecteurLabels.append(vecteurLabel);
        row_table++;
    }

    ui->tableWidget_User->setRowCount(row_table); //create lines

    for(int i=0;i<row_table;i++){
        for(int j=0;j<column_table;j++){
        ui->tableWidget_User->setCellWidget(i,j,vecteurLabels[i][j]);
        qDebug()<<vecteurLabels[i][j]->text();
       }
    }

    delete stmt_show_user;
    delete res_show_user;

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
    selected_row=row;
    ui->lineEdit_login->setText(vecteurLabels[row][1]->text());
    ui->lineEdit_high_score->setText(vecteurLabels[row][2]->text());

    ui->pushButton_modify_user->setEnabled(true);
    ui->lineEdit_high_score->setEnabled(true);
    ui->lineEdit_login->setEnabled(true);
}


void MainMenu::on_pushButton_modify_user_clicked()
{
    stmt_modify_user=con_user->createStatement();
    cout << "coucou" << endl;

    if((ui->lineEdit_pwd->text())!=NULL){
        cout << "coucou2" << endl;
        stmt_modify_user->executeUpdate("UPDATE user set login='"+ui->lineEdit_login->text().toStdString()+"', best_score="+ui->lineEdit_high_score->text().toStdString()+", password=sha2('"+ui->lineEdit_pwd->text().toStdString()+"',256) where id_user="+vecteurLabels[selected_row][0]->text().toStdString()+";");
    }
    else{
        cout << "coucou3" << endl;
        stmt_modify_user->executeUpdate("UPDATE user set login='"+ui->lineEdit_login->text().toStdString()+"', best_score="+ui->lineEdit_high_score->text().toStdString()+" where id_user="+vecteurLabels[selected_row][0]->text().toStdString()+";");
    }

    delete stmt_modify_user;

    this->hide();
    MainMenu* pageuser=new MainMenu(this->driver_user,this->con_user,menuConnexion);
    pageuser->show();
}

void MainMenu::on_pushButton_delete_user_clicked()
{
    stmt_delete_user=con_user->createStatement();
    stmt_delete_user->executeUpdate("DELETE from user where id_user="+vecteurLabels[selected_row][0]->text().toStdString()+";");

    delete stmt_delete_user;

    this->hide();
    MainMenu* pageuser=new MainMenu(this->driver_user,this->con_user,menuConnexion);
    pageuser->show();
}
