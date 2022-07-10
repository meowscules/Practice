#ifndef AVTORIZACIYA_H
#define AVTORIZACIYA_H

#include <QDialog>
#include <QWidget>
#include <QString>

class avtorizaciya
{
public:
    avtorizaciya();
    QString getLogin();
    QString getPass();
    void setLogin(const QString& username);
    void setPass(const QString& userpass);

private:
    QString m_username;
    QString m_userpass;

};

#endif // AVTORIZACIYA_H
