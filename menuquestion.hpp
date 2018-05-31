#ifndef MENUQUESTION_HPP
#define MENUQUESTION_HPP

#include <QDialog>

namespace Ui {
class MenuQuestion;
}

class MenuQuestion : public QDialog
{
    Q_OBJECT

public:
    explicit MenuQuestion(QWidget *parent = 0);
    ~MenuQuestion();

private slots:

    void on_pushButton_returnMainMenu_clicked();

private:
    Ui::MenuQuestion *ui;
};

#endif // MENUQUESTION_HPP
