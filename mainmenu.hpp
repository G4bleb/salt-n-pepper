#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <QDialog>
#include "questionsmenu.hpp"

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private slots:
    void on_pushButton_select_clicked();

private:
    Ui::MainMenu *ui;
    QuestionsMenu *questionsMenu;
};

#endif // MAINMENU_HPP
