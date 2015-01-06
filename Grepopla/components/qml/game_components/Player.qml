import QtQuick 2.0
import Player 1.0
import Ship 1.0
import Planet 1.0

Player {
    id: player
    property var objectContainer: new Array

    Component.onCompleted: {
        objectContainer["Ship"] = new Array
        objectContainer["Planet"] = new Array

        console.log("player init")

    }
}
