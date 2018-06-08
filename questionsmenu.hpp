#ifndef QUESTIONSMENU_HPP
#define QUESTIONSMENU_HPP

#include "propositionsmenu.hpp"

#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

#include <iostream>
#include <QDialog>
#include <QLabel>
#include <QMessageBox>

using namespace std;
using namespace sql;

namespace Ui {
class QuestionsMenu;
}

class QuestionsMenu : public QDialog
{
    Q_OBJECT
public:
    explicit QuestionsMenu(Driver * driver_first_window,Connection * con_first_window,int selected_id_topic,QWidget *parent = 0);
    ~QuestionsMenu();

private slots:
    /*--------- method QUESTION ----------*/
    void on_tableWidget_Question_cellClicked(int row, int column);
    void on_pushButton_delete_clicked();
    void on_pushButton_set_clicked();
    void on_pushButton_add_clicked();
    void on_pushButton_look_clicked();

    /*--------- other method ----------*/
    void on_pushButton_return_clicked();

private:
    Ui::QuestionsMenu *ui;
    PropositionsMenu * propositionsMenu;
    QWidget *lastWindow;

    /*--------- DRIVER ----------*/
    Driver * driver_second_window;

    /*--------- CONNECTION ----------*/
    Connection * con_second_window;

    /*--------- PREPARED_STATEMENT ----------*/
    PreparedStatement * prepared_stmt_show_question;
    PreparedStatement * prepared_stmt_delete_question;
    PreparedStatement * prepared_stmt_set_question;
    PreparedStatement * prepared_stmt_add_question;
    PreparedStatement * prepared_stmt_get_num_question;

    /*--------- RESULTSET ----------*/
    ResultSet * res_show_question;
    ResultSet * res_get_num_question;

    QVector < QVector <QLabel*> > tableQuestion;

    int id_topic,row_table,column_table,selected_row,num_question,question_selected;
};

#endif // QUESTIONSMENU_HPP
