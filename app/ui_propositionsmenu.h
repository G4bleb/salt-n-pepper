/********************************************************************************
** Form generated from reading UI file 'propositionsmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPOSITIONSMENU_H
#define UI_PROPOSITIONSMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PropositionsMenu
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableWidget_Proposition;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_proposition;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_first;
    QRadioButton *radioButton_second;
    QRadioButton *radioButton_third;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_add;
    QPushButton *pushButton_set;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_disable;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_return;

    void setupUi(QDialog *PropositionsMenu)
    {
        if (PropositionsMenu->objectName().isEmpty())
            PropositionsMenu->setObjectName(QStringLiteral("PropositionsMenu"));
        PropositionsMenu->resize(800, 600);
        verticalLayout_3 = new QVBoxLayout(PropositionsMenu);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        tableWidget_Proposition = new QTableWidget(PropositionsMenu);
        if (tableWidget_Proposition->columnCount() < 5)
            tableWidget_Proposition->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Proposition->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Proposition->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Proposition->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Proposition->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Proposition->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget_Proposition->setObjectName(QStringLiteral("tableWidget_Proposition"));
        tableWidget_Proposition->setAlternatingRowColors(true);
        tableWidget_Proposition->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_Proposition->horizontalHeader()->setStretchLastSection(true);
        tableWidget_Proposition->verticalHeader()->setVisible(false);

        verticalLayout_6->addWidget(tableWidget_Proposition);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_proposition = new QLineEdit(PropositionsMenu);
        lineEdit_proposition->setObjectName(QStringLiteral("lineEdit_proposition"));

        horizontalLayout->addWidget(lineEdit_proposition);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton_first = new QRadioButton(PropositionsMenu);
        radioButton_first->setObjectName(QStringLiteral("radioButton_first"));

        verticalLayout->addWidget(radioButton_first);

        radioButton_second = new QRadioButton(PropositionsMenu);
        radioButton_second->setObjectName(QStringLiteral("radioButton_second"));

        verticalLayout->addWidget(radioButton_second);

        radioButton_third = new QRadioButton(PropositionsMenu);
        radioButton_third->setObjectName(QStringLiteral("radioButton_third"));

        verticalLayout->addWidget(radioButton_third);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_add = new QPushButton(PropositionsMenu);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        horizontalLayout_2->addWidget(pushButton_add);

        pushButton_set = new QPushButton(PropositionsMenu);
        pushButton_set->setObjectName(QStringLiteral("pushButton_set"));

        horizontalLayout_2->addWidget(pushButton_set);

        pushButton_delete = new QPushButton(PropositionsMenu);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));

        horizontalLayout_2->addWidget(pushButton_delete);

        pushButton_disable = new QPushButton(PropositionsMenu);
        pushButton_disable->setObjectName(QStringLiteral("pushButton_disable"));

        horizontalLayout_2->addWidget(pushButton_disable);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButton_return = new QPushButton(PropositionsMenu);
        pushButton_return->setObjectName(QStringLiteral("pushButton_return"));

        verticalLayout_5->addWidget(pushButton_return);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_3->addLayout(verticalLayout_6);


        retranslateUi(PropositionsMenu);

        QMetaObject::connectSlotsByName(PropositionsMenu);
    } // setupUi

    void retranslateUi(QDialog *PropositionsMenu)
    {
        PropositionsMenu->setWindowTitle(QApplication::translate("PropositionsMenu", "Dialog", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Proposition->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PropositionsMenu", "ID_Prop", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Proposition->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PropositionsMenu", "State", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Proposition->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("PropositionsMenu", "Nb Answer", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Proposition->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("PropositionsMenu", "Answer", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Proposition->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("PropositionsMenu", "Proposition", Q_NULLPTR));
        lineEdit_proposition->setText(QString());
        lineEdit_proposition->setPlaceholderText(QApplication::translate("PropositionsMenu", "Proposition", Q_NULLPTR));
        radioButton_first->setText(QApplication::translate("PropositionsMenu", "Answer 1", Q_NULLPTR));
        radioButton_second->setText(QApplication::translate("PropositionsMenu", "Answer 2", Q_NULLPTR));
        radioButton_third->setText(QApplication::translate("PropositionsMenu", "Anwser 3", Q_NULLPTR));
        pushButton_add->setText(QApplication::translate("PropositionsMenu", "Add", Q_NULLPTR));
        pushButton_set->setText(QApplication::translate("PropositionsMenu", "Set", Q_NULLPTR));
        pushButton_delete->setText(QApplication::translate("PropositionsMenu", "Delete", Q_NULLPTR));
        pushButton_disable->setText(QApplication::translate("PropositionsMenu", "Change Status", Q_NULLPTR));
        pushButton_return->setText(QApplication::translate("PropositionsMenu", "Return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PropositionsMenu: public Ui_PropositionsMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPOSITIONSMENU_H
