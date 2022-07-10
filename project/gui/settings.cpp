#include "settings.h"
#include "zapros.h"
#include "ui_settings.h"
#include "ui_zapros.h"

settings::settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settings)
{

    ui->setupUi(this);
    ui->checkBox->setChecked(true);
    ui->checkBox_2->setChecked(true);
    ui->checkBox_3->setChecked(true);
    ui->checkBox_4->setChecked(true);
    ui->checkBox_5->setChecked(true);

}

settings::~settings()
{
    delete ui;
}

void settings::on_pushButton_clicked()
{
    zapros *w = new zapros;
    if(ui->checkBox->isChecked() == false)
    {
        w->ui->lineEdit->setEnabled(false);
    }
    else
    {
        w->ui->lineEdit->setEnabled(true);
    }
    if(ui->checkBox_2->isChecked() == false)
    {
        w->ui->lineEdit_2->setEnabled(false);
    }
    else
    {
        w->ui->lineEdit_2->setEnabled(true);
    }
    if(ui->checkBox_3->isChecked() == false)
    {
        w->ui->lineEdit_3->setEnabled(false);
    }
    else
    {
        w->ui->lineEdit_3->setEnabled(true);
    }
    if(ui->checkBox_4->isChecked() == false)
    {
        w->ui->lineEdit_4->setEnabled(false);
    }
    else
    {
        w->ui->lineEdit_4->setEnabled(true);
    }
    if(ui->checkBox_5->isChecked() == false)
    {
        w->ui->lineEdit_5->setEnabled(false);
    }
    else
    {
        w->ui->lineEdit_5->setEnabled(true);
    }
    w->show();
    this->close();
}


