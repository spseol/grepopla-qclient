TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    components/objects/abstractitem.cpp \
    components/objects/ship/ship.cpp \
    components/objects/planet/planet.cpp \
    components/game/game.cpp \
    components/game/player/player.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    components/objects/abstractitem.h \
    components/objects/ship/ship.h \
    components/objects/planet/planet.h \
    components/game/game.h \
    components/game/player/player.h
