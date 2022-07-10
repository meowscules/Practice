#include "reguest.h"

reguest::reguest()
{

}

void reguest::setname(const QString& name)
{
  m_name = name;
}

void reguest::setlast_name(const QString& last_name)
{
  m_last_name = last_name;
}

void reguest:: setmiddle_name(const QString& middle_name)
{
  m_middle_name = middle_name;
}

void reguest:: setcity(const QString& city)
{
  m_city = city;
}

void reguest:: settelephone(const QString& telephone)
{
  m_telephone = telephone;
}


QString reguest:: getname()
{
  return m_name;
}

QString reguest:: getlast_name()
{
  return m_last_name;
}

QString reguest:: getmiddle_name()
{
  return m_middle_name;
}

QString reguest:: getcity()
{
  return m_city;
}

QString reguest:: gettelephone()
{
  return m_telephone;
}
