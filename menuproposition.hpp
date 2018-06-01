#ifndef MENUPROPOSITION_HPP
#define MENUPROPOSITION_HPP

#include <QDialog>

namespace Ui {
class MenuProposition;
}

class MenuProposition : public QDialog
{
    Q_OBJECT

public:
    explicit MenuProposition(QWidget *parent = 0);
    ~MenuProposition();

private slots:
    void on_pushButton_return_clicked();

private:
    Ui::MenuProposition *ui;
    QWidget *lastWindow;
};

#endif // MENUPROPOSITION_HPP
