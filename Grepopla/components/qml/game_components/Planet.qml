import QtQuick 2.0
import Planet 1.0

Planet {
    width: 100
    height: 100

    Component.onCompleted: console.log("planet init")

    onBuildShip: {
        //var component = Qt.createComponent("Ship.qml")
        //var list = player.objectContainer["Ship"];

        //player.objectContainer["Ship"].push(component.createObject(root));
        //player.objectContainer["Ship"][lest.lenght - 1].type = type;
    }
}
