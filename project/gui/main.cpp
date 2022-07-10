#include "zapros.h"
#include "capcha.h"
#include "auth_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auth_window w;
    w.show();
    return a.exec();
}
