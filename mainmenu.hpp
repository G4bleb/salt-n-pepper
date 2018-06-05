#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "questionsmenu.hpp"
#include <QtSql>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <iostream>
#include <QLabel>
#include <QTableWidget>

using namespace std;
using namespace sql;


namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(Driver * driver,Connection * con, QWidget *parent = 0);
    ~MainMenu();

private slots:
    void on_pushButton_select_clicked();

    void on_pushButton_disconnect_clicked();

    void on_tableWidget_User_cellClicked(int row, int column);

private:
    Ui::MainMenu *ui;
    QuestionsMenu *questionsMenu;
    QWidget * menuConnexion;
    Connection * con;
    Statement * stmt_show_user;
    ResultSet * res_show_user;
    QVector <QVector<QLabel*>> vecteurLabel;
    QVector <QLabel*> vecteurLine;
    int row_table,column_table,k;
};

#endif // MAINMENU_HPP
