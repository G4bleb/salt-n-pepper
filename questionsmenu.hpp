#ifndef QUESTIONSMENU_HPP
#define QUESTIONSMENU_HPP

#include "propositionsmenu.hpp"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include <QDialog>
#include <iostream>

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
    void on_pushButton_return_clicked();
    void on_pushButton_select_clicked();

private:
    Ui::QuestionsMenu *ui;
    PropositionsMenu * propositionsMenu;
    QWidget *lastWindow;

    /*--------- DRIVER ----------*/
    Driver * driver_second_window;

    /*--------- DRIVER ----------*/
    Connection * con_second_window;

    int id_topic;
};

#endif // QUESTIONSMENU_HPP
