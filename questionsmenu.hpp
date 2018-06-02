#ifndef QUESTIONSMENU_HPP
#define QUESTIONSMENU_HPP

#include <QDialog>
#include <propositionsmenu.hpp>

namespace Ui {
class QuestionsMenu;
}

class QuestionsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit QuestionsMenu(QWidget *parent = 0);
    ~QuestionsMenu();

private slots:
    void on_pushButton_return_clicked();
    void on_pushButton_select_clicked();

private:
    Ui::QuestionsMenu *ui;
    PropositionsMenu * propositionsMenu;
    QWidget *lastWindow;
};

#endif // QUESTIONSMENU_HPP
