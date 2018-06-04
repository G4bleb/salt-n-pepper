#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{

    try{
        QString username = ui->lineEdit_username->text();
        QString password = ui->lineEdit_password->text();
        QString IPaddress = ui->lineEdit_address->text();
        QString DatabaseName = ui->lineEdit_dbname->text();

        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        driver = get_driver_instance();
        //con = driver->connect("tcp://"+IPaddress+":3306", username,password);
        con = driver->connect("tcp://172.31.3.60:3306","etd-cir2-prj-10","ewWK3oYg");

        con->setSchema("etd-cir2-prj-10");
        //stmt = con->createStatement();
        //res = stmt->executeQuery("SELECT id_topic,num_question,num_proposition,main_proposition,answer_nb FROM proposition");
        hide();
        mainMenu = new MainMenu(this);
        mainMenu->show();
        /*while(res->next()){
            cout << "Id_topic : " << res->getInt(1) << endl;
            cout << "Num_question :" << res->getInt(2) << endl;
            cout << "Num_proposition :" << res->getInt(3) << endl;
            cout << "Main_proposition :" << res->getString(4) << endl;
            cout << "Answer_nb :" << res->getInt(5) << endl;
        }
        delete res;
        delete stmt;
        delete con;*/
    }
    catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    /*if(username== "etd-cir2-prj-10" && password=="ewWK3oYg" && IPaddress="172.31.3.60" && DatabaseName="etd-cir2-prj-10"){
        QMessageBox::information(this,"Login","Username and password is correct");
        hide();
        mainMenu = new MainMenu(this);
        mainMenu->show();
    }
    else QMessageBox::warning(this,"Login","Username and password is incorrect");*/

}
