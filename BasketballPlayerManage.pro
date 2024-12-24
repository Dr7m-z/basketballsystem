QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddPlayer.cpp \
    ManageWidget.cpp \
    Player.cpp \
    PlayerSummary.cpp \
    ShowPersonWidget.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    AddPlayer.h \
    ManageWidget.h \
    Player.h \
    PlayerSummary.h \
    ShowPersonWidget.h \
    widget.h

FORMS += \
    AddPlayer.ui \
    ManageWidget.ui \
    ShowPersonWidget.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
