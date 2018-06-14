/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget_User;
    QFormLayout *formLayout;
    QLabel *label_9;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_high_score;
    QLabel *label_13;
    QLineEdit *lineEdit_pwd;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_delete_user;
    QPushButton *pushButton_set_user;
    QWidget *tab_5;
    QHBoxLayout *horizontalLayout_18;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *tableWidget_Topic;
    QFormLayout *formLayout_10;
    QLabel *label_19;
    QLineEdit *lineEdit_topic;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *pushButton_add_topic;
    QPushButton *pushButton_look_topic;
    QPushButton *pushButton_set_topic;
    QPushButton *pushButton_delete_topic;
    QVBoxLayout *verticalLayout_8;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_refresh;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_disconnect;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(800, 600);
        horizontalLayout_2 = new QHBoxLayout(MainMenu);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tabWidget = new QTabWidget(MainMenu);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_3 = new QVBoxLayout(tab_4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget_User = new QTableWidget(tab_4);
        if (tableWidget_User->columnCount() < 3)
            tableWidget_User->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_User->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_User->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_User->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_User->setObjectName(QStringLiteral("tableWidget_User"));
        tableWidget_User->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_User->setAlternatingRowColors(true);
        tableWidget_User->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_User->setGridStyle(Qt::SolidLine);
        tableWidget_User->horizontalHeader()->setStretchLastSection(true);
        tableWidget_User->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableWidget_User);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_9);

        lineEdit_login = new QLineEdit(tab_4);
        lineEdit_login->setObjectName(QStringLiteral("lineEdit_login"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_login);

        lineEdit_high_score = new QLineEdit(tab_4);
        lineEdit_high_score->setObjectName(QStringLiteral("lineEdit_high_score"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_high_score);

        label_13 = new QLabel(tab_4);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_13);

        lineEdit_pwd = new QLineEdit(tab_4);
        lineEdit_pwd->setObjectName(QStringLiteral("lineEdit_pwd"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_pwd);

        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_10);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_delete_user = new QPushButton(tab_4);
        pushButton_delete_user->setObjectName(QStringLiteral("pushButton_delete_user"));

        horizontalLayout->addWidget(pushButton_delete_user);

        pushButton_set_user = new QPushButton(tab_4);
        pushButton_set_user->setObjectName(QStringLiteral("pushButton_set_user"));

        horizontalLayout->addWidget(pushButton_set_user);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tab_5->setContextMenuPolicy(Qt::DefaultContextMenu);
        horizontalLayout_18 = new QHBoxLayout(tab_5);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        tableWidget_Topic = new QTableWidget(tab_5);
        if (tableWidget_Topic->columnCount() < 2)
            tableWidget_Topic->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Topic->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Topic->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        tableWidget_Topic->setObjectName(QStringLiteral("tableWidget_Topic"));
        tableWidget_Topic->setEnabled(true);
        tableWidget_Topic->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_Topic->setAlternatingRowColors(true);
        tableWidget_Topic->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_Topic->setGridStyle(Qt::SolidLine);
        tableWidget_Topic->horizontalHeader()->setStretchLastSection(true);
        tableWidget_Topic->verticalHeader()->setVisible(false);

        verticalLayout_7->addWidget(tableWidget_Topic);

        formLayout_10 = new QFormLayout();
        formLayout_10->setObjectName(QStringLiteral("formLayout_10"));
        label_19 = new QLabel(tab_5);
        label_19->setObjectName(QStringLiteral("label_19"));

        formLayout_10->setWidget(0, QFormLayout::LabelRole, label_19);

        lineEdit_topic = new QLineEdit(tab_5);
        lineEdit_topic->setObjectName(QStringLiteral("lineEdit_topic"));

        formLayout_10->setWidget(0, QFormLayout::FieldRole, lineEdit_topic);


        verticalLayout_7->addLayout(formLayout_10);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        pushButton_add_topic = new QPushButton(tab_5);
        pushButton_add_topic->setObjectName(QStringLiteral("pushButton_add_topic"));

        horizontalLayout_20->addWidget(pushButton_add_topic);

        pushButton_look_topic = new QPushButton(tab_5);
        pushButton_look_topic->setObjectName(QStringLiteral("pushButton_look_topic"));

        horizontalLayout_20->addWidget(pushButton_look_topic);

        pushButton_set_topic = new QPushButton(tab_5);
        pushButton_set_topic->setObjectName(QStringLiteral("pushButton_set_topic"));

        horizontalLayout_20->addWidget(pushButton_set_topic);

        pushButton_delete_topic = new QPushButton(tab_5);
        pushButton_delete_topic->setObjectName(QStringLiteral("pushButton_delete_topic"));

        horizontalLayout_20->addWidget(pushButton_delete_topic);


        verticalLayout_7->addLayout(horizontalLayout_20);


        horizontalLayout_19->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));

        horizontalLayout_19->addLayout(verticalLayout_8);


        horizontalLayout_18->addLayout(horizontalLayout_19);

        tabWidget->addTab(tab_5, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton_refresh = new QPushButton(tab);
        pushButton_refresh->setObjectName(QStringLiteral("pushButton_refresh"));

        verticalLayout_2->addWidget(pushButton_refresh);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        pushButton_disconnect = new QPushButton(tab);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));

        verticalLayout_2->addWidget(pushButton_disconnect);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        tabWidget->addTab(tab, QString());

        horizontalLayout_2->addWidget(tabWidget);


        retranslateUi(MainMenu);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QDialog *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "Dialog", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_User->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainMenu", "ID_User", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_User->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainMenu", "Login", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_User->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainMenu", "Best Score", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainMenu", "Login :", Q_NULLPTR));
        lineEdit_login->setPlaceholderText(QApplication::translate("MainMenu", "Enter Login", Q_NULLPTR));
        lineEdit_high_score->setPlaceholderText(QApplication::translate("MainMenu", "Enter High Score", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainMenu", "New Password :", Q_NULLPTR));
        lineEdit_pwd->setPlaceholderText(QApplication::translate("MainMenu", "Enter Password", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainMenu", "High Score :", Q_NULLPTR));
        pushButton_delete_user->setText(QApplication::translate("MainMenu", "Delete", Q_NULLPTR));
        pushButton_set_user->setText(QApplication::translate("MainMenu", "Set", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainMenu", "User", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Topic->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainMenu", "ID_Topic", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Topic->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainMenu", "Topic", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainMenu", "Topic :", Q_NULLPTR));
        lineEdit_topic->setText(QString());
        lineEdit_topic->setPlaceholderText(QApplication::translate("MainMenu", "Enter Topic", Q_NULLPTR));
        pushButton_add_topic->setText(QApplication::translate("MainMenu", "Add", Q_NULLPTR));
        pushButton_look_topic->setText(QApplication::translate("MainMenu", "Look", Q_NULLPTR));
        pushButton_set_topic->setText(QApplication::translate("MainMenu", "Set", Q_NULLPTR));
        pushButton_delete_topic->setText(QApplication::translate("MainMenu", "Delete", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainMenu", "Topic", Q_NULLPTR));
        pushButton_refresh->setText(QApplication::translate("MainMenu", "Refresh", Q_NULLPTR));
        pushButton_disconnect->setText(QApplication::translate("MainMenu", "Disconnection", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainMenu", "Other", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
