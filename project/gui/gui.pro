QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -L../DataBase/debug -lDataBase\
        -L../reg/debug -lreg\
        -L../caph/debug -lcaph


SOURCES += \
    auth_window.cpp \
    avtorizaciya.cpp \
    capcha.cpp \
    main.cpp \
    registr.cpp \
    settings.cpp \
    zapros.cpp

HEADERS += \
    auth_window.h \
    avtorizaciya.h \
    capcha.h \
    registr.h \
    settings.h \
    zapros.h

FORMS += \
    auth_window.ui \
    capcha.ui \
    registr.ui \
    settings.ui \
    zapros.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
