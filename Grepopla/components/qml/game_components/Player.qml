import QtQuick 2.0
import Player 1.0
import Ship 1.0
import Planet 1.0

Player {
    id: player
    //property var shipContainer: new Array
    property var objectContainer: new Array

    Component.onCompleted: {
        objectContainer["Ship"] = new Array
        objectContainer["Planet"] = new Array
        /*var component = Qt.createComponent("Ship.qml");

        player.shipContainer.push(component.createObject(root))
    var v = player.shipContainer
        player.shipContainer[v.length-1].width = 50
        player.shipContainer[0].height = 50
        //player.shipContainer[0].speed = 0.5
        player.shipContainer[0].type = Ship.SmallShip


        player.shipContainer.push(component.createObject(root))
        player.shipContainer[v.length-1].x = 100
        player.shipContainer[1].width = 50
        player.shipContainer[1].height = 50
        //player.shipContainer[1].speed = 9

        player.shipContainer.push(component.createObject(root))
        player.shipContainer[v.length-1].x = 450
        player.shipContainer[2].width = 50
        player.shipContainer[2].height = 50
        //player.shipContainer[2].speed = 9
        player.shipContainer[2].type = Ship.SmallShip*/
    }
}
