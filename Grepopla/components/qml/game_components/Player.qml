import QtQuick 2.0
import Player 1.0
import Ship 1.0

Player {
    id: player
    property var shipContainer: new Array
    //property list<Planet> planetContainer
    Component.onCompleted: {
        var component = Qt.createComponent("Ship.qml");

        var object = component.createObject(root)
        object.width = 50
        object.height = 50
        object.speed = 9
        object.type = Ship.SmallShip
        player.shipContainer.push(object)
    }
}
