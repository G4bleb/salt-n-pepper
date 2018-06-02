#ifndef PROPOSITIONSMENU_HPP
#define PROPOSITIONSMENU_HPP

#include <QDialog>

namespace Ui {
class PropositionsMenu;
}

class PropositionsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit PropositionsMenu(QWidget *parent = 0);
    ~PropositionsMenu();

private slots:
    void on_pushButton_return_clicked();

private:
    Ui::PropositionsMenu *ui;
    QWidget *lastWindow;
};

#endif // PROPOSITIONSMENU_HPP
