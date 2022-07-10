#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "auth_window.h"
#include <QtDebug>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_Main(new Ui::MainWindow)
{
    user_counter = 0;
    m_loginSuccesfull = false;
    connect(&ui_Auth, SIGNAL(login_button_clicked()),
            this, SLOT(authorizeUser()));
    connect(&ui_Auth,SIGNAL(destroyed()),
            this, SLOT(show()));
    connect(&ui_Auth,SIGNAL(register_button_clicked()),
            this,SLOT(registerWindowShow()));
    if(!connectDB())
    {
        qDebug() << "Failed to connect DB";
    }
    QSqlQuery query;
    db_input = "CREATE TABLE userlist ( "
               "number INTEGER PRIMARY KEY NOT NULL,"
               "name VARCHAR(20), "
               "pass VARCHAR(12)); ";
    if(!query.exec(db_input))
    {
            qDebug() << "Unable to create a table"
                        << query.lastError()/* << " : " << query.lastQuery()*/;
    }
    ui_Main->setupUi(this);
}

void MainWindow::authorizeUser()
{
    wipeDB();
    m_username = ui_Auth.getLogin();
    m_userpass = ui_Auth.getPass();
    //testDB("qwe","zxc");
    testDB("qwe","qwe");
    QString str_t = " SELECT * "" FROM userlist "" WHERE name = '%1'";
    QString username = "";
    QString userpass = "";
    db_input = str_t.arg(m_username);
    QSqlQuery query;
    QSqlRecord rec;
    if(!query.exec(db_input))
    {
        qDebug() << "Unable to execute query - exiting"
                << query.lastError() << " : " << query.lastQuery();
    }
    rec=query.record();
    query.next();
    user_counter = query.value(rec.indexOf("number")).toInt();
    username     = query.value(rec.indexOf("name")).toString();
    userpass     = query.value(rec.indexOf("pass")).toString();
    if(m_username != username || m_userpass != userpass)
    {
        qDebug() << "Password missmatch" << username << " " << userpass;
        m_loginSuccesfull = false;
    }
    else
    {
        m_loginSuccesfull = true;
        ui_Auth.close();
        this->show();
    }
}
void MainWindow::registerWindowShow()
{
    ui_Auth.hide();
}
void MainWindow::display()                                                              //реализация пользотвальского метода отображения главного окна
{
    ui_Auth.show();                                                                      //отобразить окно авторизации(НЕ главное окно)
}
MainWindow::~MainWindow()                                                               //реализация деструктора
{
    if(m_loginSuccesfull)
    {
        /* QString str_t =   "UPDATE userlist "
                                "SET xpos = %2, ypos = %3, width = %4, length = %5 "
                                "WHERE name = '%1';";*/
        QString str_t;
        db_input = str_t.arg(m_username);
                                    /*.arg(this->x())
                                    .arg(this->y())
                                    .arg(this->width())
                                    .arg(this->height());*/
     /* QSqlQuery query;
       if(!query.exec(db_input))
        {
            qDebug() << "Unable to insert data"  << query.lastError() << " : " << query.lastQuery() ;
        }*/
    }
    mw_db.removeDatabase("./q.db");
    qDebug() << "MainWindow Destroyed";
    delete ui_Main;                                                                     //удалить указатель на экземпляр главного окна
    exit(0);                                                                            //завершить приложение
}
bool MainWindow::connectDB()
{
    mw_db = QSqlDatabase::addDatabase("QSQLITE");
    mw_db.setDatabaseName("./q.db");
    if(!mw_db.open())
    {
        qDebug() << "Cannot open database: " << mw_db.lastError();
        return false;
    }
    return true;
}
void MainWindow::wipeDB()
{
    mw_db.removeDatabase("./q.db");
}

void MainWindow::testDB(QString name, QString pass)
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO userlist("
                            "name,"
                            "pass)"
                            "VALUES(?,?);");
    qry.addBindValue(name);
    qry.addBindValue(pass);
    if(!qry.exec())
    {
        qDebug()<<"error adding values to db";
    }
}
