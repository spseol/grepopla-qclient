TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    components/objects/abstractitem.cpp \
    components/game/player/player.cpp \
    components/objects/ship/ship.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    components/objects/abstractitem.h \
    components/game/player/player.h \
    components/objects/ship/ship.h
