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
    this->con_second_window=con_first_window;

    cout << "Numéro de l'id:" << id_topic << endl;

    ui->pushButton_delete->setEnabled(false);
    ui->pushButton_set->setEnabled(false);
    ui->pushButton_look->setEnabled(false);
    ui->pushButton_disable->setEnabled(false);

    prepared_stmt_show_question=con_second_window->prepareStatement("SELECT num_question,enabled,answer1,answer2,main_question from question where id_topic=? ORDER BY main_question");
    prepared_stmt_show_question->setInt(1,id_topic);
    res_show_question=prepared_stmt_show_question->executeQuery();

    row_table=0;
    column_table=ui->tableWidget_Question->columnCount();

    while(res_show_question->next()){
        QVector <QLabel*> vecteurLabel;
        vecteurLabel.append(new QLabel(res_show_question->getString(1).c_str()));

        status=res_show_question->getInt(2);
        if(status==1) vecteurLabel.append(new QLabel("ENABLE"));
        else vecteurLabel.append(new QLabel("DISABLE"));

        vecteurLabel.append(new QLabel(res_show_question->getString(3).c_str()));
        vecteurLabel.append(new QLabel(res_show_question->getString(4).c_str()));
        vecteurLabel.append(new QLabel(res_show_question->getString(5).c_str()));
        tableQuestion.append(vecteurLabel);
        row_table++;
    }

    ui->tableWidget_Question->setRowCount(row_table); //create lines

    cout << row_table << " & " << column_table <<endl;

    for(int i=0;i<row_table;i++){
        for(int j=0;j<column_table;j++){
            ui->tableWidget_Question->setCellWidget(i,j,tableQuestion[i][j]);
        }
    }

    prepared_stmt_get_num_question=con_second_window->prepareStatement("SELECT MAX(num_question) FROM question where id_topic=?;");
    prepared_stmt_get_num_question->setInt(1,id_topic);
    res_get_num_question=prepared_stmt_get_num_question->executeQuery();

    while(res_get_num_question->next()){
        num_question=res_get_num_question->getInt(1);
        cout << "Number Question :" << num_question<<endl;
    }

    delete prepared_stmt_get_num_question;
    delete prepared_stmt_show_question;

    delete res_show_question;
    delete res_get_num_question;
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

void QuestionsMenu::on_tableWidget_Question_cellClicked(int row, int column)
{
    ui->pushButton_delete->setEnabled(true);
    ui->pushButton_set->setEnabled(true);
    ui->pushButton_look->setEnabled(true);
    ui->pushButton_disable->setEnabled(true);

    selected_row=row;
    ui->lineEdit_answer1->setText(tableQuestion[row][2]->text());
    ui->lineEdit_answer2->setText(tableQuestion[row][3]->text());
    ui->lineEdit_question->setText(tableQuestion[row][4]->text());
}

void QuestionsMenu::on_pushButton_delete_clicked()
{
    bool delete_selected_item=false;
    int clicked_button=QMessageBox::question(this, tr("Delete Question"),tr("Are you sure you want to delete your selection ?"),QMessageBox::No|QMessageBox::Yes,QMessageBox::No);

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
        prepared_stmt_delete_question=con_second_window->prepareStatement("DELETE from question where num_question=? and id_topic=?");
        prepared_stmt_delete_question->setString(1,tableQuestion[selected_row][0]->text().toStdString());
        prepared_stmt_delete_question->setInt(2,id_topic);
        prepared_stmt_delete_question->executeUpdate();
        delete prepared_stmt_delete_question;

        QMessageBox::information(this, tr("Delete Question"),tr("Question deleted."));

    }

    QuestionsMenu* pagequestion=new QuestionsMenu(this->driver_second_window,this->con_second_window,this->id_topic,lastWindow);
    this->deleteLater();
    pagequestion->show();
}

void QuestionsMenu::on_pushButton_set_clicked()
{
    if(ui->lineEdit_question->text().toStdString().size()<=100 &&
        (ui->lineEdit_question->text())!=NULL &&
             ui->lineEdit_answer1->text().toStdString().size()<=40 &&
                 ui->lineEdit_answer2->text().toStdString().size()<=40 &&
                    ui->lineEdit_answer1->text()!=NULL &&
                         ui->lineEdit_answer2->text()!=NULL){
        prepared_stmt_set_question=con_second_window->prepareStatement("UPDATE question set main_question=?,answer1=?,answer2=? where id_topic=? and num_question=?;");
        prepared_stmt_set_question->setString(1,ui->lineEdit_question->text().toStdString());
        prepared_stmt_set_question->setString(2,ui->lineEdit_answer1->text().toStdString());
        prepared_stmt_set_question->setString(3,ui->lineEdit_answer2->text().toStdString());
        prepared_stmt_set_question->setInt(4,id_topic);
        prepared_stmt_set_question->setString(5,tableQuestion[selected_row][0]->text().toStdString());
        prepared_stmt_set_question->executeUpdate();
        delete prepared_stmt_set_question;

        QMessageBox::information(this, tr("Set Question"),tr("Question modified."));
    }

    else{
        if(ui->lineEdit_question->text().toStdString().size()>100)        QMessageBox::warning(this, tr("Set Question"),tr("Question too long ! Please insert a new one. (MAX 100)"));
        if((ui->lineEdit_question->text())==NULL)        QMessageBox::warning(this, tr("Set Question"),tr("No Question add ! Please insert one."));
        if(ui->lineEdit_answer1->text().toStdString().size()>40)        QMessageBox::warning(this, tr("Set Question"),tr("First answer too long ! Please insert a new one. (MAX 40)"));
        if((ui->lineEdit_answer1->text())==NULL)        QMessageBox::warning(this, tr("Set Question"),tr("No first answer add ! Please insert one."));
        if(ui->lineEdit_answer2->text().toStdString().size()>40)        QMessageBox::warning(this, tr("Set Question"),tr("Second answer too long ! Please insert a new one. (MAX 40)"));
        if((ui->lineEdit_answer2->text())==NULL)        QMessageBox::warning(this, tr("Set Question"),tr("No second answer add ! Please insert one."));
    }

    QuestionsMenu* pagequestion=new QuestionsMenu(this->driver_second_window,this->con_second_window,this->id_topic,lastWindow);
    this->deleteLater();
    pagequestion->show();
}

void QuestionsMenu::on_pushButton_add_clicked()
{
    if(ui->lineEdit_question->text().toStdString().size()<=100 &&
        (ui->lineEdit_question->text())!=NULL &&
            ui->lineEdit_answer1->text().toStdString().size()<=40 &&
                (ui->lineEdit_answer1->text())!=NULL &&
                    ui->lineEdit_answer2->text().toStdString().size()<=40 &&
                        (ui->lineEdit_answer2->text())!=NULL){
        prepared_stmt_add_question=con_second_window->prepareStatement("INSERT INTO `question` (`id_topic`, `num_question`, `main_question`, `answer1`, `answer2`) VALUES (?,?,?,?,?);");
        prepared_stmt_add_question->setInt(1,id_topic);
        prepared_stmt_add_question->setInt(2,num_question+1);
        prepared_stmt_add_question->setString(3,ui->lineEdit_question->text().toStdString());
        prepared_stmt_add_question->setString(4,ui->lineEdit_answer1->text().toStdString());
        prepared_stmt_add_question->setString(5,ui->lineEdit_answer2->text().toStdString());
        prepared_stmt_add_question->executeUpdate();
        delete prepared_stmt_add_question;

        QMessageBox::information(this, tr("Add Question"),tr("Question added."));
    }

    else{
        if(ui->lineEdit_question->text().toStdString().size()>100)        QMessageBox::warning(this, tr("Add Question"),tr("Question too long ! Please insert a new one. (MAX 100)"));
        if((ui->lineEdit_question->text())==NULL)        QMessageBox::warning(this, tr("Add Question"),tr("No Question add ! Please insert one."));
        if(ui->lineEdit_answer1->text().toStdString().size()>40)        QMessageBox::warning(this, tr("Add Question"),tr("First answer too long ! Please insert a new one. (MAX 40)"));
        if((ui->lineEdit_answer1->text())==NULL)        QMessageBox::warning(this, tr("Add Question"),tr("No first answer add ! Please insert one."));
        if(ui->lineEdit_answer2->text().toStdString().size()>40)        QMessageBox::warning(this, tr("Add Question"),tr("Second answer too long ! Please insert a new one. (MAX 40)"));
        if((ui->lineEdit_answer2->text())==NULL)        QMessageBox::warning(this, tr("Add Question"),tr("No second answer add ! Please insert one."));
    }

    QuestionsMenu* pagequestion=new QuestionsMenu(this->driver_second_window,this->con_second_window,this->id_topic,lastWindow);
    this->deleteLater();
    pagequestion->show();
}


void QuestionsMenu::on_pushButton_look_clicked()
{
    question_selected=tableQuestion[selected_row][0]->text().toInt();

    this->hide();
    propositionsMenu = new PropositionsMenu(this->driver_second_window,this->con_second_window,this->id_topic,this->question_selected,this);
    propositionsMenu->show();
}

void QuestionsMenu::on_pushButton_disable_clicked()
{
    if(tableQuestion[selected_row][1]->text().toStdString()=="ENABLE"){
        prepared_stmt_status_question=con_second_window->prepareStatement("UPDATE question set enabled=0 where id_topic=? and num_question=? ");
    }
    else{
        prepared_stmt_status_question=con_second_window->prepareStatement("UPDATE question set enabled=1 where id_topic=? and num_question=? ");
    }

    prepared_stmt_status_question->setInt(1,id_topic);
    prepared_stmt_status_question->setString(2,tableQuestion[selected_row][0]->text().toStdString());
    prepared_stmt_status_question->executeUpdate();
    delete prepared_stmt_status_question;

    QuestionsMenu* pagequestion=new QuestionsMenu(this->driver_second_window,this->con_second_window,this->id_topic,lastWindow);
    this->deleteLater();
    pagequestion->show();
}
