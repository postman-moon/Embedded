QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    labelx.cpp \
    main.cpp \
    mainwidget.cpp \
    pagecontext.cpp \
    pagedragevent.cpp \
    pageenterleave.cpp \
    pagekeyevent.cpp \
    pagepaint.cpp \
    pagepress.cpp \
    pagetimerevent.cpp \
    texteditx.cpp

HEADERS += \
    labelx.h \
    mainwidget.h \
    pagecontext.h \
    pagedragevent.h \
    pageenterleave.h \
    pagekeyevent.h \
    pagepaint.h \
    pagepress.h \
    pagetimerevent.h \
    texteditx.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
