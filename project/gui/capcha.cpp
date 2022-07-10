#include "capcha.h"
#include "ui_capcha.h"
#include <string.h>
#include <zapros.h>

#include "../caph/caph.h"

capcha::capcha(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::capcha)
{
    Caph caph;
    ui->setupUi(this);
    ui->label_4->setText(caph.gen_captcha(5));
}

capcha::~capcha()
{
    delete ui;
}


void capcha::on_pushButton_2_clicked()
{
    Caph caph;
    caph.settext(ui->lineEdit_2->text());
    QString captcha=ui->label_4->text();
    int result=captcha.compare(caph.gettext());
    if (result)
    {
        ui->label_4->setText(caph.gen_captcha(5));
    }
    else
    {
        zapros *q = new zapros;
        q->show();
        this ->hide();
    }
}

