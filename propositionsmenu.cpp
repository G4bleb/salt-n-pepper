#include "propositionsmenu.hpp"
#include "ui_propositionsmenu.h"

PropositionsMenu::PropositionsMenu(Driver * driver_second_window,Connection * con_second_window,int id_topic,int question_selected,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PropositionsMenu)
{
    lastWindow = parent;
    ui->setupUi(this);

    this->id_topic_parent=id_topic;
    this->num_question_parent=question_selected;
    this->driver_third_window=driver_second_window;
    this->con_third_window=con_second_window;

    ui->pushButton_delete->setEnabled(false);
    ui->pushButton_set->setEnabled(false);
    ui->pushButton_disable->setEnabled(false);

    cout << "ID TOPIC :" << id_topic_parent << endl;
    cout << "NUM QUESTION :" << num_question_parent << endl;

    prepared_stmt_show_proposition=con_third_window->prepareStatement("SELECT num_proposition,enabled,answer_nb,main_proposition from proposition where id_topic=? and num_question=? ORDER BY main_proposition");
    prepared_stmt_show_proposition->setInt(1,id_topic_parent);
    prepared_stmt_show_proposition->setInt(2,num_question_parent);
    res_show_proposition=prepared_stmt_show_proposition->executeQuery();

    row_table=0;
    column_table=ui->tableWidget_Proposition->columnCount();

    while(res_show_proposition->next()){
        QVector <QLabel*> vecteurLabel;
        vecteurLabel.append(new QLabel(res_show_proposition->getString(1).c_str()));

        status=res_show_proposition->getInt(2);
        if(status) vecteurLabel.append(new QLabel("ENABLED"));
        else vecteurLabel.append(new QLabel("DISABLED"));

        answer=res_show_proposition->getInt(3);
        vecteurLabel.append(new QLabel(res_show_proposition->getString(3).c_str()));

        if(answer==1){
            prepared_stmt_get_answer1=con_third_window->prepareStatement("SELECT question.answer1 from question,proposition where question.id_topic=? and question.num_question=? and proposition.answer_nb=? GROUP BY question.answer1");
            prepared_stmt_get_answer1->setInt(1,id_topic_parent);
            prepared_stmt_get_answer1->setInt(2,num_question_parent);
            prepared_stmt_get_answer1->setInt(3,answer);
            res_get_answer1=prepared_stmt_get_answer1->executeQuery();
            while(res_get_answer1->next()){
                vecteurLabel.append(new QLabel(res_get_answer1->getString(1).c_str()));
            }
            delete prepared_stmt_get_answer1;
            delete res_get_answer1;
        }
        if(answer==2){
            prepared_stmt_get_answer2=con_third_window->prepareStatement("SELECT question.answer2 from question,proposition where question.id_topic=? and question.num_question=? and proposition.answer_nb=? GROUP BY question.answer2");
            prepared_stmt_get_answer2->setInt(1,id_topic_parent);
            prepared_stmt_get_answer2->setInt(2,num_question_parent);
            prepared_stmt_get_answer2->setInt(3,answer);
            res_get_answer2=prepared_stmt_get_answer2->executeQuery();
            while(res_get_answer2->next()){
                vecteurLabel.append(new QLabel(res_get_answer2->getString(1).c_str()));
            }
            delete prepared_stmt_get_answer2;
            delete res_get_answer2;
        }
        if(answer==3) vecteurLabel.append(new QLabel("Les deux"));

        vecteurLabel.append(new QLabel(res_show_proposition->getString(4).c_str()));
        tableProposition.append(vecteurLabel);
        row_table++;
    }

    ui->tableWidget_Proposition->setRowCount(row_table); //create lines

    cout << row_table << " & " << column_table <<endl;

    for(int i=0;i<row_table;i++){
        for(int j=0;j<column_table;j++){
            ui->tableWidget_Proposition->setCellWidget(i,j,tableProposition[i][j]);
        }
    }

    prepared_stmt_get_num_proposition=con_third_window->prepareStatement("SELECT MAX(num_proposition) FROM proposition where id_topic=? and num_question=?;");
    prepared_stmt_get_num_proposition->setInt(1,id_topic_parent);
    prepared_stmt_get_num_proposition->setInt(2,num_question_parent);
    res_get_num_proposition=prepared_stmt_get_num_proposition->executeQuery();

    while(res_get_num_proposition->next()){
        num_proposition=res_get_num_proposition->getInt(1);
        cout << "Number Question :" << num_proposition<<endl;
    }

    delete prepared_stmt_show_proposition;
    delete prepared_stmt_get_num_proposition;

    delete res_show_proposition;
    delete res_get_num_proposition;
}

PropositionsMenu::~PropositionsMenu()
{
    delete ui;
}

void PropositionsMenu::on_pushButton_return_clicked()
{
    this->hide();
    lastWindow->show();
    this->deleteLater();
}

void PropositionsMenu::on_tableWidget_Proposition_cellClicked(int row)
{
    bool check=true;
    selected_row=row;

    ui->pushButton_delete->setEnabled(true);
    ui->pushButton_set->setEnabled(true);
    ui->pushButton_disable->setEnabled(true);

    ui->lineEdit_proposition->setText(tableProposition[row][4]->text());

    if(tableProposition[selected_row][2]->text()=='1') ui->radioButton_first->setChecked(check);
    if(tableProposition[selected_row][2]->text()=='2') ui->radioButton_second->setChecked(check);
    if(tableProposition[selected_row][2]->text()=='3') ui->radioButton_third->setChecked(check);
}

void PropositionsMenu::on_pushButton_delete_clicked()
{
    bool delete_selected_item=false;
    int clicked_button=QMessageBox::question(this, tr("Delete Proposition"),tr("Are you sure you want to delete your selection ?"),QMessageBox::No|QMessageBox::Yes,QMessageBox::No);

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
        prepared_stmt_delete_proposition=con_third_window->prepareStatement("DELETE from proposition where num_proposition=? and num_question=? and id_topic=?");
        prepared_stmt_delete_proposition->setString(1,tableProposition[selected_row][0]->text().toStdString());
        prepared_stmt_delete_proposition->setInt(2,num_question_parent);
        prepared_stmt_delete_proposition->setInt(3,id_topic_parent);
        prepared_stmt_delete_proposition->executeUpdate();
        delete prepared_stmt_delete_proposition;
        QMessageBox::information(this, tr("Delete Proposition"),tr("Proposition deleted."));
    }

    PropositionsMenu* pageproposition=new PropositionsMenu(this->driver_third_window,this->con_third_window,this->id_topic_parent,this->num_question_parent,lastWindow);
    this->deleteLater();
    pageproposition->show();
}

void PropositionsMenu::on_pushButton_set_clicked()
{
    if(ui->lineEdit_proposition->text().toStdString().size()<=100 && (ui->lineEdit_proposition->text())!=NULL){
        if(ui->radioButton_first->isChecked()){
            prepared_stmt_set_proposition=con_third_window->prepareStatement("UPDATE proposition set main_proposition=?, answer_nb=1 where id_topic=? and num_question=? and num_proposition=?;");
        }

        if(ui->radioButton_second->isChecked()){
            prepared_stmt_set_proposition=con_third_window->prepareStatement("UPDATE proposition set main_proposition=?, answer_nb=2 where id_topic=? and num_question=? and num_proposition=?;");
        }

        if(ui->radioButton_third->isChecked()){
            prepared_stmt_set_proposition=con_third_window->prepareStatement("UPDATE proposition set main_proposition=?, answer_nb=3 where id_topic=? and num_question=? and num_proposition=?;");
        }

        prepared_stmt_set_proposition->setString(1,ui->lineEdit_proposition->text().toStdString());
        prepared_stmt_set_proposition->setInt(2,id_topic_parent);
        prepared_stmt_set_proposition->setInt(3,num_question_parent);
        prepared_stmt_set_proposition->setString(4,tableProposition[selected_row][0]->text().toStdString());
        prepared_stmt_set_proposition->executeUpdate();
        delete prepared_stmt_set_proposition;
        QMessageBox::information(this, tr("Set Proposition"),tr("Question modified."));
    }

    else{
        if(ui->lineEdit_proposition->text().toStdString().size()>100)        QMessageBox::warning(this, tr("Set Proposition"),tr("Proposition too long ! Please insert a new one. (MAX 100)"));
        if((ui->lineEdit_proposition->text())==NULL)        QMessageBox::warning(this, tr("Set Proposition"),tr("No Proposition add ! Please insert one."));
    }

    PropositionsMenu* pageproposition=new PropositionsMenu(this->driver_third_window,this->con_third_window,this->id_topic_parent,this->num_question_parent,lastWindow);
    this->deleteLater();
    pageproposition->show();
}

void PropositionsMenu::on_pushButton_add_clicked()
{
    bool check=false;
    int verification=0;

    for(int i=0;i<row_table;i++){
        if(tableProposition[i][4]->text().toStdString()!=ui->lineEdit_proposition->text().toStdString()) verification++;
    }

    if(ui->radioButton_first->isChecked() || ui->radioButton_second->isChecked() || ui->radioButton_third->isChecked()) check=true;

    if(ui->lineEdit_proposition->text().toStdString().size()<=100 &&
            (ui->lineEdit_proposition->text())!=NULL &&
                check==true &&
                    verification==row_table){

        if(ui->radioButton_first->isChecked()){
            prepared_stmt_add_proposition=con_third_window->prepareStatement("INSERT INTO `proposition`(`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES (?,?,?,?,1) ");
        }

        if(ui->radioButton_second->isChecked()){
            prepared_stmt_add_proposition=con_third_window->prepareStatement("INSERT INTO `proposition`(`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES (?,?,?,?,2) ");
        }

        if(ui->radioButton_third->isChecked()){
            prepared_stmt_add_proposition=con_third_window->prepareStatement("INSERT INTO `proposition`(`id_topic`, `num_question`, `num_proposition`, `main_proposition`, `answer_nb`) VALUES (?,?,?,?,3) ");
        }

        prepared_stmt_add_proposition->setInt(1,id_topic_parent);
        prepared_stmt_add_proposition->setInt(2,num_question_parent);
        prepared_stmt_add_proposition->setInt(3,num_proposition+1);
        prepared_stmt_add_proposition->setString(4,ui->lineEdit_proposition->text().toStdString());
        prepared_stmt_add_proposition->executeUpdate();
        delete prepared_stmt_add_proposition;
        QMessageBox::information(this, tr("Add Proposition"),tr("Proposition added."));

    }

    else{
        if(ui->lineEdit_proposition->text().toStdString().size()>100)        QMessageBox::warning(this, tr("Add Proposition"),tr("Proposition too long ! Please insert a new one. (MAX 100)"));
        if((ui->lineEdit_proposition->text())==NULL)        QMessageBox::warning(this, tr("Add Proposition"),tr("No Proposition add ! Please insert one."));
        if(check==false)        QMessageBox::warning(this, tr("Add Proposition"),tr("No Button checked."));
        if(verification!=row_table) QMessageBox::warning(this, tr("Add Proposition"),tr("This proposition already exist. Please insert a new one."));
    }

    PropositionsMenu* pageproposition=new PropositionsMenu(this->driver_third_window,this->con_third_window,this->id_topic_parent,this->num_question_parent,lastWindow);
    this->deleteLater();
    pageproposition->show();
}

void PropositionsMenu::on_pushButton_disable_clicked()
{
    if(tableProposition[selected_row][1]->text().toStdString()=="ENABLED"){
        prepared_stmt_status_proposition=con_third_window->prepareStatement("UPDATE proposition set enabled=0 where id_topic=? and num_question=? and num_proposition=? ");
    }

    else{
        prepared_stmt_status_proposition=con_third_window->prepareStatement("UPDATE proposition set enabled=1 where id_topic=? and num_question=? and num_proposition=? ");
    }

    prepared_stmt_status_proposition->setInt(1,id_topic_parent);
    prepared_stmt_status_proposition->setInt(2,num_question_parent);
    prepared_stmt_status_proposition->setString(3,tableProposition[selected_row][0]->text().toStdString());
    prepared_stmt_status_proposition->executeUpdate();
    delete prepared_stmt_status_proposition;
    PropositionsMenu* pageproposition=new PropositionsMenu(this->driver_third_window,this->con_third_window,this->id_topic_parent,this->num_question_parent,lastWindow);
    this->deleteLater();
    pageproposition->show();
}
