#ifndef REGISTR_H
#define REGISTR_H

#include <QWidget>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

namespace Ui {
class registr;
}

class registr : public QWidget
{
    Q_OBJECT

public:
    explicit registr(QWidget *parent = nullptr);
    ~registr();

private slots:
    void on_pushButton_clicked();

private:
    Ui::registr *ui;
    QSqlDatabase db;
    QSqlQuery *query;
};

#endif // REGISTR_H
