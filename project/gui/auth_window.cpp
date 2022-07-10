#include "auth_window.h"
#include "ui_auth_window.h"
#include "avtorizaciya.h"
#include "capcha.h"
#include "registr.h"


auth_window::auth_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::auth_window)
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

auth_window::~auth_window()
{
    delete ui;
}

void auth_window::on_registerPushButton_clicked()
{
    registr *q = new registr;
    q->show();
    this ->hide();

}


void auth_window::on_pushButton_clicked()
{
    QString db_input;
    QString q_username;
    QString q_userpass;
    avtorizaciya avt;
    avt.setLogin(ui->loginLineEdit->text());
    avt.setPass(ui->passwordLineEdit->text());
    q_username = avt.getLogin();
    q_userpass =avt.getPass();
    QString str_t = " SELECT *  FROM userlist  WHERE name = '%1'";
    QString username = "";
    QString userpass = "";
    db_input = str_t.arg(q_username);
    QSqlQuery query;
    QSqlRecord rec;
    if(!query.exec(db_input))
    {
        qDebug() << "Unable to execute query - exiting"
                << query.lastError() << " : " << query.lastQuery();
    }
    rec=query.record();
    query.next();
    username = query.value(rec.indexOf("name")).toString();
    userpass = query.value(rec.indexOf("pass")).toString();
    qDebug("rrr");
    if(q_username != username || q_userpass != userpass)
    {
        qDebug() << "Password missmatch" << username << " " << userpass;
    }
    else
    {
        capcha *q = new capcha;
        q->show();
        this ->hide();
    }
}

