/********************************************************************************
** Form generated from reading UI file 'questionsmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONSMENU_H
#define UI_QUESTIONSMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QuestionsMenu
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget_Question;
    QLineEdit *lineEdit_question;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_answer1;
    QLineEdit *lineEdit_answer2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_add;
    QPushButton *pushButton_look;
    QPushButton *pushButton_set;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_disable;
    QPushButton *pushButton_return;

    void setupUi(QDialog *QuestionsMenu)
    {
        if (QuestionsMenu->objectName().isEmpty())
            QuestionsMenu->setObjectName(QStringLiteral("QuestionsMenu"));
        QuestionsMenu->resize(800, 600);
        verticalLayout = new QVBoxLayout(QuestionsMenu);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget_Question = new QTableWidget(QuestionsMenu);
        if (tableWidget_Question->columnCount() < 5)
            tableWidget_Question->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Question->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Question->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Question->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Question->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Question->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget_Question->setObjectName(QStringLiteral("tableWidget_Question"));
        tableWidget_Question->setAlternatingRowColors(true);
        tableWidget_Question->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_Question->setCornerButtonEnabled(true);
        tableWidget_Question->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_Question->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_Question->horizontalHeader()->setStretchLastSection(true);
        tableWidget_Question->verticalHeader()->setVisible(false);
        tableWidget_Question->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget_Question->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_Question->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(tableWidget_Question);

        lineEdit_question = new QLineEdit(QuestionsMenu);
        lineEdit_question->setObjectName(QStringLiteral("lineEdit_question"));

        verticalLayout->addWidget(lineEdit_question);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit_answer1 = new QLineEdit(QuestionsMenu);
        lineEdit_answer1->setObjectName(QStringLiteral("lineEdit_answer1"));

        horizontalLayout_2->addWidget(lineEdit_answer1);

        lineEdit_answer2 = new QLineEdit(QuestionsMenu);
        lineEdit_answer2->setObjectName(QStringLiteral("lineEdit_answer2"));

        horizontalLayout_2->addWidget(lineEdit_answer2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_add = new QPushButton(QuestionsMenu);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        horizontalLayout->addWidget(pushButton_add);

        pushButton_look = new QPushButton(QuestionsMenu);
        pushButton_look->setObjectName(QStringLiteral("pushButton_look"));

        horizontalLayout->addWidget(pushButton_look);

        pushButton_set = new QPushButton(QuestionsMenu);
        pushButton_set->setObjectName(QStringLiteral("pushButton_set"));

        horizontalLayout->addWidget(pushButton_set);

        pushButton_delete = new QPushButton(QuestionsMenu);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));

        horizontalLayout->addWidget(pushButton_delete);

        pushButton_disable = new QPushButton(QuestionsMenu);
        pushButton_disable->setObjectName(QStringLiteral("pushButton_disable"));

        horizontalLayout->addWidget(pushButton_disable);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_return = new QPushButton(QuestionsMenu);
        pushButton_return->setObjectName(QStringLiteral("pushButton_return"));

        verticalLayout->addWidget(pushButton_return);


        retranslateUi(QuestionsMenu);

        QMetaObject::connectSlotsByName(QuestionsMenu);
    } // setupUi

    void retranslateUi(QDialog *QuestionsMenu)
    {
        QuestionsMenu->setWindowTitle(QApplication::translate("QuestionsMenu", "Dialog", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Question->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("QuestionsMenu", "ID_Question", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Question->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("QuestionsMenu", "State", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Question->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("QuestionsMenu", "Answer 1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Question->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("QuestionsMenu", "Answer 2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Question->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("QuestionsMenu", "Question", Q_NULLPTR));
        lineEdit_question->setPlaceholderText(QApplication::translate("QuestionsMenu", "Question", Q_NULLPTR));
        lineEdit_answer1->setText(QString());
        lineEdit_answer1->setPlaceholderText(QApplication::translate("QuestionsMenu", "Answer 1", Q_NULLPTR));
        lineEdit_answer2->setPlaceholderText(QApplication::translate("QuestionsMenu", "Answer 2", Q_NULLPTR));
        pushButton_add->setText(QApplication::translate("QuestionsMenu", "Add", Q_NULLPTR));
        pushButton_look->setText(QApplication::translate("QuestionsMenu", "Look", Q_NULLPTR));
        pushButton_set->setText(QApplication::translate("QuestionsMenu", "Set", Q_NULLPTR));
        pushButton_delete->setText(QApplication::translate("QuestionsMenu", "Delete", Q_NULLPTR));
        pushButton_disable->setText(QApplication::translate("QuestionsMenu", "Change Status", Q_NULLPTR));
        pushButton_return->setText(QApplication::translate("QuestionsMenu", "Return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QuestionsMenu: public Ui_QuestionsMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONSMENU_H
