#ifndef PROPOSITIONSMENU_HPP
#define PROPOSITIONSMENU_HPP

#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/exception.h>

#include <iostream>
#include <QDialog>
#include <QLabel>
#include <QMessageBox>
#include <QRadioButton>
#include <QCheckBox>

using namespace std;
using namespace sql;

namespace Ui {
class PropositionsMenu;
}

class PropositionsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit PropositionsMenu(Driver* driver_second_window,Connection* con_second_window,int id_topic,int question_selected,QWidget *parent = 0);
    ~PropositionsMenu();

private slots:
    /*--------- other PROPOSITIONS ----------*/
    void on_tableWidget_Proposition_cellClicked(int row, int column);
    void on_pushButton_delete_clicked();
    void on_pushButton_set_clicked();
    void on_pushButton_add_clicked();
    void on_pushButton_disable_clicked();

    /*--------- other method ----------*/
    void on_pushButton_return_clicked();

private:
    Ui::PropositionsMenu *ui;
    QWidget *lastWindow;

    /*--------- DRIVER ----------*/
    Driver * driver_third_window;

    /*--------- CONNECTION ----------*/
    Connection * con_third_window;

    /*--------- PREPARED_STATEMENT ----------*/
    PreparedStatement * prepared_stmt_show_proposition;
    PreparedStatement * prepared_stmt_get_answer1;
    PreparedStatement * prepared_stmt_get_answer2;
    PreparedStatement * prepared_stmt_get_num_proposition;
    PreparedStatement * prepared_stmt_delete_proposition;
    PreparedStatement * prepared_stmt_set_proposition;
    PreparedStatement * prepared_stmt_add_proposition;
    PreparedStatement * prepared_stmt_status_proposition;

    /*--------- RESULTSET ----------*/
    ResultSet * res_show_proposition;
    ResultSet * res_get_answer1;
    ResultSet * res_get_answer2;
    ResultSet * res_get_num_proposition;

    QVector <QVector <QLabel*> > tableProposition;

    int id_topic_parent,num_question_parent,row_table,column_table,selected_row,answer,num_proposition,status;

};

#endif // PROPOSITIONSMENU_HPP
