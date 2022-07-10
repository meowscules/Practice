#ifndef CAPH_H
#define CAPH_H

#include "caph_global.h"
#include "qstring.h"

class CAPH_EXPORT Caph
{
public:
    Caph();
    QString gen_captcha(int n);

    QString gettext();
    void settext(const QString& text);

private:
    QString m_text;
};

#endif // CAPH_H
