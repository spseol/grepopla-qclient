#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "components/game/player/player.h"
#include "components/objects/ship/ship.h"
#include "components/game/game.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<Player>("Player", 1, 0, "Player");
    qmlRegisterType<Ship>("Ship", 1, 0, "Ship");
    qmlRegisterType<Game>("Game", 1, 0, "Game");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
