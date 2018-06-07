#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "questionsmenu.hpp"

#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

#include <iostream>
#include <QLabel>
#include <QMessageBox>

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
    /*---------- method USER ----------*/
    void on_tableWidget_User_cellClicked(int row, int column);
    void on_pushButton_set_user_clicked();
    void on_pushButton_delete_user_clicked();

    /*---------- method TOPIC ----------*/
    void on_tableWidget_Topic_cellClicked(int row, int column);
    void on_pushButton_set_topic_clicked();
    void on_pushButton_delete_topic_clicked();
    void on_pushButton_add_topic_clicked();
    void on_pushButton_look_topic_clicked();

    /*---------- other method ----------*/
    void on_pushButton_disconnect_clicked();

private:
    Ui::MainMenu *ui;
    QuestionsMenu *questionsMenu;
    QWidget * menuConnexion;

    /*--------- DRIVER ----------*/
    Driver * driver_first_window;

    /*--------- CONNECTION ----------*/
    Connection * con_first_window;

    /*--------- STATEMENT ----------*/
    Statement * stmt_show_user;
    Statement * stmt_show_topic;

    /*--------- PREPARED_STATEMENT ----------*/
    PreparedStatement * prepared_stmt_delete_user;
    PreparedStatement * prepared_stmt_set_user;

    PreparedStatement * prepared_stmt_delete_topic;
    PreparedStatement * prepared_stmt_set_topic;
    PreparedStatement * prepared_stmt_add_topic;

    /*--------- RESULTEST ----------*/
    ResultSet * res_show_user;
    ResultSet * res_show_topic;

    QVector <QVector <QLabel*> > TableFirstThumbnail;
    QVector <QVector <QLabel*> > TableSecondThumbnail;


    int row_table_user,column_table_user,row_table_topic,column_table_topic,selected_row_user,selected_row_topic,selected_id_topic,clicked_button,delete_selected_item;
};

#endif // MAINMENU_HPP
