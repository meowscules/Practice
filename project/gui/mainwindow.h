#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QString>
#include "auth_window.h"
#include <QtSql/QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void display();
        bool connectDB();
        void wipeDB();
        void testDB(QString name,QString pass);
private:
        Ui::MainWindow *ui_Main;
            auth_window ui_Auth;
            QString m_username;
            QString m_userpass;
            QString db_input;
            QSqlDatabase mw_db;
            int user_counter;
            bool m_loginSuccesfull;
private slots:
    void authorizeUser(); // пользовательские слоты
    void registerWindowShow();
};
#endif // MAINWINDOW_H
