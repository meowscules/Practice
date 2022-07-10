#ifndef EXECUTION_H
#define EXECUTION_H

#include <QString>


class reguest
{
public:
    reguest();

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



#endif // EXECUTION_H
