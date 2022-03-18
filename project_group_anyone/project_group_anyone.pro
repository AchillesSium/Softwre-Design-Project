QT       += core gui charts network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    jsonparser.cpp \
    main.cpp \
    chartwindow.cpp \
    networkcalls.cpp \
    timewindow.cpp \
    userselections.cpp \
    userselectionssmear.cpp \
    userselectionsstatfi.cpp \
    date.cpp \
    controller.cpp \

HEADERS += \
    chartwindow.h \
    jsonparser.h \
    networkcalls.h \
    timewindow.h \
    userselections.h \
    userselectionssmear.h \
    userselectionsstatfi.h \
    date.h \
    controller.h \

FORMS += \
    chartwindow.ui \
    timewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
