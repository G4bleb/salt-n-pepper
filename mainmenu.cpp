#include "mainmenu.hpp"
#include "ui_mainmenu.h"

MainMenu::MainMenu(Driver *driver,Connection *con,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    menuConnexion=parent;

    this->driver_first_window=driver;
    this->con_first_window = con;

    ui->pushButton_set_user->setEnabled(false);
    ui->pushButton_delete_user->setEnabled(false);
    ui->lineEdit_high_score->setEnabled(false);
    ui->lineEdit_login->setEnabled(false);
    ui->lineEdit_pwd->setEnabled(false);

    ui->pushButton_delete_topic->setEnabled(false);
    ui->pushButton_set_topic->setEnabled(false);
    ui->pushButton_look_topic->setEnabled(false);

    stmt_show_user=con_first_window->createStatement();
    res_show_user=stmt_show_user->executeQuery("SELECT id_user,login,best_score FROM user");

    stmt_show_topic=con_first_window->createStatement();
    res_show_topic=stmt_show_topic->executeQuery("SELECT id_topic,topic_name FROM topic");

    row_table_user=0;
    column_table_user=ui->tableWidget_User->columnCount();

    while(res_show_user->next()){
        QVector <QLabel*> vecteurLabel;
        vecteurLabel.append(new QLabel(res_show_user->getString(1).c_str()));
        vecteurLabel.append(new QLabel(res_show_user->getString(2).c_str()));
        vecteurLabel.append(new QLabel(res_show_user->getString(3).c_str()));
        TableFirstThumbnail.append(vecteurLabel);
        row_table_user++;
    }

    ui->tableWidget_User->setRowCount(row_table_user); //create lines

    for(int i=0;i<row_table_user;i++){
        for(int j=0;j<column_table_user;j++){
        ui->tableWidget_User->setCellWidget(i,j,TableFirstThumbnail[i][j]);
       // qDebug()<<TableFirstThumbnail[i][j]->text();
       }
    }




    row_table_topic=0;
    column_table_topic=ui->tableWidget_Topic->columnCount();

    while(res_show_topic->next()){
        QVector <QLabel*> vecteurLabel;
        vecteurLabel.append(new QLabel(res_show_topic->getString(1).c_str()));
        vecteurLabel.append(new QLabel(res_show_topic->getString(2).c_str()));
        TableSecondThumbnail.append(vecteurLabel);
        row_table_topic++;
    }

    ui->tableWidget_Topic->setRowCount(row_table_topic); //create lines

    for(int i=0;i<row_table_topic;i++){
        for(int j=0;j<column_table_topic;j++){
        ui->tableWidget_Topic->setCellWidget(i,j,TableSecondThumbnail[i][j]);
        //qDebug()<<TableSecondThumbnail[i][j]->text();
       }
    }

    delete stmt_show_user;
    delete res_show_user;

    delete stmt_show_topic;
    delete res_show_topic;

}

MainMenu::~MainMenu()
{
    delete ui;
}

/*void MainMenu::on_pushButton_select_clicked()
{
    this->hide();
    questionsMenu = new QuestionsMenu(this);
    questionsMenu->show();
}*/


void MainMenu::on_pushButton_disconnect_clicked()
{
    this->hide();
    menuConnexion->show();
    this->deleteLater();
}

void MainMenu::on_tableWidget_User_cellClicked(int row, int column)
{
    selected_row_user=row;
    ui->lineEdit_login->setText(TableFirstThumbnail[row][1]->text());
    ui->lineEdit_high_score->setText(TableFirstThumbnail[row][2]->text());

    ui->pushButton_set_user->setEnabled(true);
    ui->pushButton_delete_user->setEnabled(true);
    ui->lineEdit_high_score->setEnabled(true);
    ui->lineEdit_login->setEnabled(true);
    ui->lineEdit_pwd->setEnabled(true);
}


void MainMenu::on_pushButton_set_user_clicked()
{
    stmt_modify_user=con_first_window->createStatement();

    if((ui->lineEdit_pwd->text())!=NULL)stmt_modify_user->executeUpdate("UPDATE user set login='"+ui->lineEdit_login->text().toStdString()+"', best_score="+ui->lineEdit_high_score->text().toStdString()+", password=sha2('"+ui->lineEdit_pwd->text().toStdString()+"',256) where id_user="+TableFirstThumbnail[selected_row_user][0]->text().toStdString()+";");

    else stmt_modify_user->executeUpdate("UPDATE user set login='"+ui->lineEdit_login->text().toStdString()+"', best_score="+ui->lineEdit_high_score->text().toStdString()+" where id_user="+TableFirstThumbnail[selected_row_user][0]->text().toStdString()+";");

    delete stmt_modify_user;

    this->hide();
    MainMenu* pageuser=new MainMenu(this->driver_first_window,this->con_first_window,menuConnexion);
    pageuser->show();
}

void MainMenu::on_pushButton_delete_user_clicked()
{
    stmt_delete_user=con_first_window->createStatement();
    stmt_delete_user->executeUpdate("DELETE from user where id_user="+TableFirstThumbnail[selected_row_user][0]->text().toStdString()+";");
    delete stmt_delete_user;

    this->hide();
    MainMenu* pageuser=new MainMenu(this->driver_first_window,this->con_first_window,menuConnexion);
    pageuser->show();
}

void MainMenu::on_tableWidget_Topic_cellClicked(int row, int column)
{
    selected_row_topic=row;
    ui->lineEdit_topic->setText(TableSecondThumbnail[row][1]->text());

    ui->pushButton_delete_topic->setEnabled(true);
    ui->pushButton_set_topic->setEnabled(true);
    ui->pushButton_look_topic->setEnabled(true);

}

void MainMenu::on_pushButton_set_topic_clicked()
{
    stmt_modify_topic=con_first_window->createStatement();
    stmt_modify_topic->executeUpdate("UPDATE topic set topic_name='"+ui->lineEdit_topic->text().toStdString()+"' where id_topic="+TableSecondThumbnail[selected_row_topic][0]->text().toStdString()+";");
    delete stmt_modify_topic;

    this->hide();
    MainMenu* pageuser=new MainMenu(this->driver_first_window,this->con_first_window,menuConnexion);
    pageuser->show();
}

void MainMenu::on_pushButton_delete_topic_clicked()
{
    stmt_delete_topic=con_first_window->createStatement();
    stmt_delete_topic->executeUpdate("DELETE from topic where id_topic="+TableSecondThumbnail[selected_row_topic][0]->text().toStdString()+";");
    delete stmt_delete_topic;

    this->hide();
    MainMenu* pageuser=new MainMenu(this->driver_first_window,this->con_first_window,menuConnexion);
    pageuser->show();
}

void MainMenu::on_pushButton_add_topic_clicked()
{
    stmt_add_topic=con_first_window->createStatement();
    stmt_add_topic->executeUpdate("INSERT INTO topic (id_topic,topic_name) values (NULL,'"+ui->lineEdit_topic->text().toStdString()+"');");
    delete stmt_add_topic;

    this->hide();
    MainMenu* pageuser=new MainMenu(this->driver_first_window,this->con_first_window,menuConnexion);
    pageuser->show();
}
