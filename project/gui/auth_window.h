#ifndef AUTH_WINDOW_H
#define AUTH_WINDOW_H

#include <QMainWindow>
#include <QtSql/QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class auth_window; }
QT_END_NAMESPACE

class auth_window : public QMainWindow
{
    Q_OBJECT

public:
    auth_window(QWidget *parent = nullptr);
    ~auth_window();

private slots:
    void on_registerPushButton_clicked();
    void on_pushButton_clicked();

private:
    Ui::auth_window *ui;
    QSqlDatabase db;
};
#endif // AUTH_WINDOW_H
