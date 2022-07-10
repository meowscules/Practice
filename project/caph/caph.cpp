#include "caph.h"
#include "time.h"

Caph::Caph()
{
}

void Caph:: settext(const QString& text)
{
  m_text = text;
}


QString Caph:: gettext()
{
  return m_text;
}

QString Caph::gen_captcha(int n){
   time_t t;
   srand((unsigned)time(&t));
   char chrs[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
   QString captcha = "";
   while (n--)
      captcha.push_back(chrs[rand()%62]);
   return QString(captcha);
}
