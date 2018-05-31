#ifndef MENUPRINCIPAL_HPP
#define MENUPRINCIPAL_HPP

#include <QDialog>
#include "menuquestion.hpp"

namespace Ui {
class MenuPrincipal;
}

class MenuPrincipal : public QDialog
{
    Q_OBJECT

public:
    explicit MenuPrincipal(QWidget *parent = 0);
    ~MenuPrincipal();

private slots:

    void on_pushButton_consulter_theme_clicked();

private:
    Ui::MenuPrincipal *ui;
    MenuQuestion *menuQuestion;
};

#endif // MENUPRINCIPAL_HPP
