#include "database.h"

DataBase::DataBase()
{
}
void DataBase::setname(const QString& name)
{
  m_name = name;
}

void DataBase::setlast_name(const QString& last_name)
{
  m_last_name = last_name;
}

void DataBase:: setmiddle_name(const QString& middle_name)
{
  m_middle_name = middle_name;
}

void DataBase:: setcity(const QString& city)
{
  m_city = city;
}

void DataBase:: settelephone(const QString& telephone)
{
  m_telephone = telephone;
}


QString DataBase:: getname()
{
  return m_name;
}

QString DataBase:: getlast_name()
{
  return m_last_name;
}

QString DataBase:: getmiddle_name()
{
  return m_middle_name;
}

QString DataBase:: getcity()
{
  return m_city;
}

QString DataBase:: gettelephone()
{
  return m_telephone;
}
