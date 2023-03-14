QT       += core gui
QT       +=multimedia
RC_ICONS=bubble.ico
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bubble.cpp \
    game_1.cpp \
    info.cpp \
    main.cpp \
    login.cpp \
    mouse_1.cpp \
    music.cpp \
    select.cpp \
    select1.cpp

HEADERS += \
    bubble.h \
    game_1.h \
    info.h \
    login.h \
    mouse_1.h \
    music.h \
    select.h \
    select1.h

FORMS += \
    bubble.ui \
    game_1.ui \
    info.ui \
    login.ui \
    mouse_1.ui \
    music.ui \
    select.ui \
    select1.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
