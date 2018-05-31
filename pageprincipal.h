#ifndef PAGEPRINCIPAL_H
#define PAGEPRINCIPAL_H

#include <QDialog>

namespace Ui {
class PagePrincipal;
}

class PagePrincipal : public QDialog
{
    Q_OBJECT

public:
    explicit PagePrincipal(QWidget *parent = 0);
    ~PagePrincipal();

private:
    Ui::PagePrincipal *ui;
};

#endif // PAGEPRINCIPAL_H
