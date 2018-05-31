#include "pageprincipal.h"
#include "ui_pageprincipal.h"

PagePrincipal::PagePrincipal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PagePrincipal)
{
    ui->setupUi(this);
}

PagePrincipal::~PagePrincipal()
{
    delete ui;
}
