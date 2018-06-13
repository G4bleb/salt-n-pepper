#include "headers/mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(QCoreApplication::applicationDirPath()+"/../salt-n-pepper/app/resource/burger.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    try{
        driver = get_driver_instance();
        con = driver->connect("tcp://"+ui->lineEdit_address->text().toStdString()+":3306",ui->lineEdit_username->text().toStdString(),ui->lineEdit_password->text().toStdString());
        con->setSchema(ui->lineEdit_dbname->text().toStdString());
        status=1;
    }

    catch (sql::SQLException &e) {
        status=0;
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
        QMessageBox::warning(this,"WARNING !","Cannot connect to the database ! Wrong informations !");
    }

    if(status==1){
        hide();
        mainMenu = new MainMenu(driver,con,this);
        mainMenu->show();
    }
}

void MainWindow::on_pushButton_quit_clicked()
{
    QMessageBox::information(this, tr("Quit"),tr("Goodbye !"));
    QApplication::quit();
}
