#include "registr.h"
#include "ui_registr.h"
#include "auth_window.h"

#include "../reg/reg.h"

#include <QString>
#include <QMessageBox>


registr::registr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registr)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./praktika.db");
    if(db.open())
    {
        qDebug("open");
    }
    else
    {
         qDebug("no open");
    }
}

registr::~registr()
{
    delete ui;
}

void registr::on_pushButton_clicked()
{
    Reg reg;
    QString pass2;
    QSqlQuery query;
    reg.setname(ui->lineEdit_5->text());
    reg.setlast_name(ui->lineEdit->text());
    reg.setpochta(ui->lineEdit_6->text());
    reg.setlogin(ui->lineEdit_2->text());
    reg.setparol(ui->lineEdit_3->text());
    pass2 = ui->lineEdit_4->text();
    if (reg.getlast_name() =="" or reg.getlogin() == "" or  reg.getname() == "" or reg.getparol() =="" or reg.getpochta() == "")
    {
            QMessageBox::warning(this, "Внимание","Заполните все поля!");
    }
    else
    {

        query.exec("SELECT name FROM userlist WHERE "
                  "(name = '"+ reg.getname() + "') ");
        QSqlRecord rec = query.record();
        int size = 0 ;
        while (query.next()) size++;
        if (size == 1)
        {
             QMessageBox::warning(this, "Внимание","Логин занят!");
        }
        else
        {
            if (reg.getparol().length()<4)
            {
                 QMessageBox::warning(this, "Внимание","Пароль должен содержать 4 символа");

            }
            else
            {
                if ( reg.getparol()==pass2)
                {
                    query.prepare( QString("INSERT INTO userlist (Имя, Фамилия, Почта, name, pass) "
                                           "VALUES ('%1', '%2', '%3','%4', '%5');")
                                     .arg(reg.getname())
                                     .arg(reg.getlast_name())
                                     .arg(reg.getpochta())
                                     .arg(reg.getlogin())
                                     .arg(reg.getparol())
                              );
                    query.exec();
                     QMessageBox::warning(this, "","Регистрация прошла успешно");
                     auth_window *q = new auth_window ;
                     q->show();
                     this ->hide();

                }
                else
                {
                    QMessageBox::warning(this, "","Подтвердите пароль!");

                }
            }
         }
     }
}

