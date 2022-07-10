#ifndef DATABASE_H
#define DATABASE_H

#include "DataBase_global.h"
#include "QString"


class DATABASE_EXPORT DataBase
{
public:
    DataBase();
    QString getname();
    QString getlast_name();
    QString getmiddle_name();
    QString getcity();
    QString gettelephone();

    void setname(const QString& name);
    void setlast_name(const QString& last_name);
    void setmiddle_name(const QString& middle_name);
    void setcity(const QString& city);
    void settelephone(const QString& telephone);

private:
    QString m_name ;
    QString m_last_name ;
    QString m_middle_name ;
    QString m_city ;
    QString m_telephone ;
};

#endif // DATABASE_H
