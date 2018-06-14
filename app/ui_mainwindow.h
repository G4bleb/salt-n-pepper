/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QFormLayout *formLayout_3;
    QLabel *label_adress;
    QLineEdit *lineEdit_address;
    QLabel *label_dbname;
    QLineEdit *lineEdit_dbname;
    QLabel *label_username;
    QLineEdit *lineEdit_username;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_login;
    QPushButton *pushButton_quit;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label_adress = new QLabel(centralwidget);
        label_adress->setObjectName(QStringLiteral("label_adress"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_adress);

        lineEdit_address = new QLineEdit(centralwidget);
        lineEdit_address->setObjectName(QStringLiteral("lineEdit_address"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, lineEdit_address);

        label_dbname = new QLabel(centralwidget);
        label_dbname->setObjectName(QStringLiteral("label_dbname"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_dbname);

        lineEdit_dbname = new QLineEdit(centralwidget);
        lineEdit_dbname->setObjectName(QStringLiteral("lineEdit_dbname"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, lineEdit_dbname);

        label_username = new QLabel(centralwidget);
        label_username->setObjectName(QStringLiteral("label_username"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_username);

        lineEdit_username = new QLineEdit(centralwidget);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, lineEdit_username);

        label_password = new QLabel(centralwidget);
        label_password->setObjectName(QStringLiteral("label_password"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_password);

        lineEdit_password = new QLineEdit(centralwidget);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        formLayout_3->setWidget(4, QFormLayout::FieldRole, lineEdit_password);

        pushButton_login = new QPushButton(centralwidget);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));

        formLayout_3->setWidget(5, QFormLayout::SpanningRole, pushButton_login);

        pushButton_quit = new QPushButton(centralwidget);
        pushButton_quit->setObjectName(QStringLiteral("pushButton_quit"));

        formLayout_3->setWidget(6, QFormLayout::SpanningRole, pushButton_quit);


        verticalLayout->addLayout(formLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Connexion", Q_NULLPTR));
        label_adress->setText(QApplication::translate("MainWindow", "Address of the base :", Q_NULLPTR));
        lineEdit_address->setText(QApplication::translate("MainWindow", "172.31.3.60", Q_NULLPTR));
        lineEdit_address->setPlaceholderText(QApplication::translate("MainWindow", "Adresse", Q_NULLPTR));
        label_dbname->setText(QApplication::translate("MainWindow", "Name of the base :", Q_NULLPTR));
        lineEdit_dbname->setText(QApplication::translate("MainWindow", "etd-cir2-prj-10", Q_NULLPTR));
        lineEdit_dbname->setPlaceholderText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_username->setText(QApplication::translate("MainWindow", "Username :", Q_NULLPTR));
        lineEdit_username->setText(QApplication::translate("MainWindow", "etd-cir2-prj-10", Q_NULLPTR));
        lineEdit_username->setPlaceholderText(QApplication::translate("MainWindow", "Username", Q_NULLPTR));
        label_password->setText(QApplication::translate("MainWindow", "Password :", Q_NULLPTR));
        lineEdit_password->setText(QApplication::translate("MainWindow", "ewWK3oYg", Q_NULLPTR));
        lineEdit_password->setPlaceholderText(QApplication::translate("MainWindow", "Mot de passe", Q_NULLPTR));
        pushButton_login->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        pushButton_quit->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
