import QtQuick 2.0
import Ship 1.0

import "../effects"

Ship {
    id: ship

    imageSource: ":/resources/images/modifiedShip.svg"
    rotationSpeed: 5
Component.onCompleted: console.log("ship init")
    onDestinationChanged: ParallelAnimation {
        objectName: "moveAnimation"

        NumberAnimation { target: ship; property: "x"; to: destination.x; duration: ship.voyageDuration }
        NumberAnimation { target: ship; property: "y"; to: destination.y; duration: ship.voyageDuration }
    }

    onXChanged: ship.checkCollision()
    onYChanged: ship.checkCollision()
    onBoom: boom.boom()
    onFocusChanged: console.log(ship.ID + "/" + ship.focus)

    Behavior on rotation {
        NumberAnimation { duration: ship.rotationDuration() }
    }

    Rectangle {
        width:  parent.width
        height: width
        radius: width

        color: "transparent"
        visible: ship.focus

        border.width: 3
        border.color: "orange"

        anchors.centerIn: parent
    }

    BoomAnimation {
        id: boom
        width: ship.width * 3
        height: width
        anchors.centerIn: ship
    }

    Text {
        text: ship.owner.nick
        color: "red"
        font.pixelSize: 15
    }

    /*Text {
        id: text
        text:   ship.ID
        color: "white"
        anchors.centerIn: parent
        font.pixelSize: 20
    }*/

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            var shipContainer = game.playerContainer[owner.ID].objectContainer["Ship"];

            if(game.myID == owner.ID) {
                for(var key in shipContainer)
                    game.playerContainer[owner.ID].objectContainer["Ship"][key].focus = false

                ship.focus = true
                //console.log("focus")
            }

            else {
                //which my ship has focus?
                var focusedShip = -1;

                for(var key in shipContainer = game.playerContainer[game.myID].objectContainer["Ship"])
                    if(shipContainer[key].focus) {
                        focusedShip = key;
                        break;
                    }

                if( focusedShip != -1) {   //check if I have focus on any my ship
                    var datas = {};

                    datas.id = ship.ID;
                    //datas.command = "action";
                    datas.command = "follow";
                    datas.owner_id = ship.owner.ID

                    datas.values = {};
                    datas.values.follower_id = game.myID;
                    datas.values.following_ship_id = focusedShip;

                    socket.sendTextMessage(JSON.stringify(datas));
                    //ship.startEmitDestination(game.playerContainer[game.myID].objectContainer["Ship"][focusedShip])
                }

            }
        }
    }
}
