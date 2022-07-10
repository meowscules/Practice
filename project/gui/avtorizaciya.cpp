#include "avtorizaciya.h"

avtorizaciya::avtorizaciya()
{

}
QString avtorizaciya::getPass()
{
    return m_userpass;
}

QString avtorizaciya::getLogin()
{
    return m_username;
}

void avtorizaciya::setLogin(const QString& username)
{
  m_username = username;
}

void avtorizaciya::setPass(const QString& userpass)
{
  m_userpass = userpass;
}
