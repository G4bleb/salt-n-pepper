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
    res_show_user=stmt_show_user->executeQuery("SELECT id_user,login,best_score FROM user ORDER BY (best_score) DESC");

    stmt_show_topic=con_first_window->createStatement();
    res_show_topic=stmt_show_topic->executeQuery("SELECT id_topic,topic_name FROM topic ORDER BY topic_name");

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

void MainMenu::on_pushButton_disconnect_clicked()
{
    this->hide();
    menuConnexion->show();
    this->deleteLater();
}

void MainMenu::on_tableWidget_User_cellClicked(int row)
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
    bool high_score;
    ui->lineEdit_high_score->text().toInt(&high_score);
    if(high_score && (ui->lineEdit_login->text())!=NULL && ui->lineEdit_login->text().toStdString().size()<=64 ){
        if((ui->lineEdit_pwd->text())!=NULL){
            prepared_stmt_set_user=con_first_window->prepareStatement("UPDATE user set login=?, best_score=?, password=sha2(?,256) where id_user=?;");
            prepared_stmt_set_user->setString(1,ui->lineEdit_login->text().toStdString());
            prepared_stmt_set_user->setString(2,ui->lineEdit_high_score->text().toStdString());
            prepared_stmt_set_user->setString(3,ui->lineEdit_pwd->text().toStdString());
            prepared_stmt_set_user->setString(4,TableFirstThumbnail[selected_row_user][0]->text().toStdString());
        }

        else{
            prepared_stmt_set_user=con_first_window->prepareStatement("UPDATE user set login=?, best_score=? where id_user=?;");
            prepared_stmt_set_user->setString(1,ui->lineEdit_login->text().toStdString());
            prepared_stmt_set_user->setString(2,ui->lineEdit_high_score->text().toStdString());
            prepared_stmt_set_user->setString(3,TableFirstThumbnail[selected_row_user][0]->text().toStdString());
        }

        prepared_stmt_set_user->executeUpdate();
        delete prepared_stmt_set_user;

        QMessageBox::information(this, tr("Set User"),tr("User modified."));
    }

    else{
        if(high_score==false)        QMessageBox::warning(this, tr("Set User"),tr("High Score too high ! Please insert a new one."));
        if(ui->lineEdit_login->text().toStdString().size()>64)        QMessageBox::warning(this, tr("Set User"),tr("Username too long ! Please insert a new one. (MAX 64)"));
        if((ui->lineEdit_login->text())==NULL)        QMessageBox::warning(this, tr("Set User"),tr("No Username add ! Please insert one."));     
    }

    MainMenu* pageuser=new MainMenu(this->driver_first_window,this->con_first_window,menuConnexion);
    this->deleteLater();
    pageuser->show();

}

void MainMenu::on_pushButton_delete_user_clicked()
{
    bool delete_selected_item=false;
    int clicked_button=QMessageBox::question(this, tr("Delete User"),tr("Are you sure you want to delete your selection ?"),QMessageBox::No|QMessageBox::Yes,QMessageBox::No);

    switch(clicked_button){
        case QMessageBox::Yes:
            delete_selected_item=true;
            break;
       case QMessageBox::No:
            break;
       default:
            break;
    }

    if(delete_selected_item){
        prepared_stmt_delete_user=con_first_window->prepareStatement("DELETE from user where id_user=?");
        prepared_stmt_delete_user->setString(1,TableFirstThumbnail[selected_row_user][0]->text().toStdString());
        prepared_stmt_delete_user->executeUpdate();
        delete prepared_stmt_delete_user;
        QMessageBox::information(this, tr("Delete User"),tr("User deleted."));

    }

    MainMenu* pageuser=new MainMenu(this->driver_first_window,this->con_first_window,menuConnexion);
    this->deleteLater();
    pageuser->show();
}

void MainMenu::on_tableWidget_Topic_cellClicked(int row)
{
    selected_row_topic=row;
    ui->lineEdit_topic->setText(TableSecondThumbnail[row][1]->text());

    ui->pushButton_delete_topic->setEnabled(true);
    ui->pushButton_set_topic->setEnabled(true);
    ui->pushButton_look_topic->setEnabled(true);
}

void MainMenu::on_pushButton_set_topic_clicked()
{
    if(ui->lineEdit_topic->text().toStdString().size()<=100 && (ui->lineEdit_topic->text())!=NULL){
        prepared_stmt_set_topic=con_first_window->prepareStatement("UPDATE topic set topic_name=? where id_topic=?;");
        prepared_stmt_set_topic->setString(1,ui->lineEdit_topic->text().toStdString());
        prepared_stmt_set_topic->setString(2,TableSecondThumbnail[selected_row_topic][0]->text().toStdString());
        prepared_stmt_set_topic->executeUpdate();
        delete prepared_stmt_set_topic;
        QMessageBox::information(this, tr("Set Topic"),tr("Topic modified."));
    }

    else{
        if(ui->lineEdit_topic->text().toStdString().size()>100)        QMessageBox::warning(this, tr("Set Topic"),tr("Topic too long ! Please insert a new one. (MAX 100)"));
        if((ui->lineEdit_topic->text())==NULL)        QMessageBox::warning(this, tr("Set Topic"),tr("No Topic add ! Please insert one."));
    }

    MainMenu* pageuser=new MainMenu(this->driver_first_window,this->con_first_window,menuConnexion);
    this->deleteLater();
    pageuser->show();
}

void MainMenu::on_pushButton_delete_topic_clicked()
{
    bool delete_selected_item=false;
    int clicked_button=QMessageBox::question(this, tr("Delete Topic"),tr("Are you sure you want to delete your selection ?"),QMessageBox::No | QMessageBox::Yes,QMessageBox::No);

    switch(clicked_button){
        case QMessageBox::Yes:
            delete_selected_item=true;
            break;
       case QMessageBox::No:
            break;
       default:
            break;
    }

    if(delete_selected_item){
        prepared_stmt_delete_topic=con_first_window->prepareStatement("DELETE from topic where id_topic=?;");
        prepared_stmt_delete_topic->setString(1,TableSecondThumbnail[selected_row_topic][0]->text().toStdString());
        prepared_stmt_delete_topic->executeUpdate();
        delete prepared_stmt_delete_topic;

        QMessageBox::information(this, tr("Delete Topic"),tr("Topic deleted."));

    }

    MainMenu* pageuser=new MainMenu(this->driver_first_window,this->con_first_window,menuConnexion);
    this->deleteLater();
    pageuser->show();
}

void MainMenu::on_pushButton_add_topic_clicked()
{
    int verification=0;

    for(int i=0;i<row_table_topic;i++){
        if(TableSecondThumbnail[i][1]->text().toStdString()!=ui->lineEdit_topic->text().toStdString()) verification++;
    }

    if(ui->lineEdit_topic->text().toStdString().size()<=100 &&
            (ui->lineEdit_topic->text())!=NULL &&
                verification==row_table_topic){
        prepared_stmt_add_topic=con_first_window->prepareStatement("INSERT INTO topic (id_topic,topic_name) values (NULL,?);");
        prepared_stmt_add_topic->setString(1,ui->lineEdit_topic->text().toStdString());
        prepared_stmt_add_topic->executeUpdate();
        delete prepared_stmt_add_topic;

        QMessageBox::information(this, tr("Add Topic"),tr("Topic added."));

    }

    else{
        if(ui->lineEdit_topic->text().toStdString().size()>100) QMessageBox::warning(this, tr("Add Topic"),tr("Topic is too long ! Insert a new one. ( MAX 100)"));
        if((ui->lineEdit_topic->text())==NULL) QMessageBox::warning(this, tr("Add Topic"),tr("No Topic add ! Please insert one."));
        if(verification!=row_table_topic) QMessageBox::warning(this, tr("Add Topic"),tr("This topic already exist. Please insert a new one."));
    }

    MainMenu* pageuser=new MainMenu(this->driver_first_window,this->con_first_window,menuConnexion);
    this->deleteLater();
    pageuser->show();
}

void MainMenu::on_pushButton_look_topic_clicked()
{
    selected_id_topic=TableSecondThumbnail[selected_row_topic][0]->text().toInt();

    hide();
    questionsMenu = new QuestionsMenu(driver_first_window,con_first_window,selected_id_topic,this);
    questionsMenu->show();
}

void MainMenu::on_tabWidget_tabBarClicked(int index)
{
    if(!index){
        MainMenu* pageuser=new MainMenu(this->driver_first_window,this->con_first_window,menuConnexion);
        this->deleteLater();
        pageuser->show();
    }

}
