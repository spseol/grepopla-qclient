import QtQuick 2.0
import Player 1.0
import Ship 1.0

Player {
    id: player
    property var shipContainer: new Array
    //property list<Planet> planetContainer
    Component.onCompleted: {
        var component = Qt.createComponent("Ship.qml");

        player.shipContainer[0] = component.createObject(root)

        player.shipContainer[0].width = 50
        player.shipContainer[0].height = 50
        player.shipContainer[0].speed = 0.5
        player.shipContainer[0].type = Ship.SmallShip


        player.shipContainer[1] = component.createObject(root)
        player.shipContainer[1].x = 100
        player.shipContainer[1].width = 50
        player.shipContainer[1].height = 50
        player.shipContainer[1].speed = 9

        player.shipContainer[2] = component.createObject(root)
        player.shipContainer[2].x = 450
        player.shipContainer[2].width = 50
        player.shipContainer[2].height = 50
        player.shipContainer[2].speed = 9
        player.shipContainer[2].type = Ship.SmallShip
    }
}
