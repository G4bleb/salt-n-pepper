#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "mainmenu.hpp"

#include <cppconn/driver.h>

#include <QMainWindow>
#include <iostream>

using namespace std;
using namespace sql;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_quit_clicked();

private:
    Ui::MainWindow *ui;
    MainMenu *mainMenu;
    Driver *driver;
    Connection *con;
    int status;

};

#endif // MAINWINDOW_HPP
