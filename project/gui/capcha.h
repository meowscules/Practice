#ifndef CAPCHA_H
#define CAPCHA_H

#include <QWidget>

namespace Ui {
class capcha;
}

class capcha : public QWidget
{
    Q_OBJECT

public:
    explicit capcha(QWidget *parent = nullptr);
    ~capcha();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::capcha *ui;
    QString gen_captcha(int n);
};

#endif // CAPCHA_H
