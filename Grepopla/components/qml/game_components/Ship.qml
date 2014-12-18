import QtQuick 2.0
import Ship 1.0

Ship {
    id: ship

    imageSource: ":/resources/images/Symbol_Up_Arrow.svg"
    rotationSpeed: 5

    onDestinationChanged: ParallelAnimation {
        objectName: "moveAnimation"

        NumberAnimation { target: ship; property: "x"; to: destination.x; duration: ship.voyageDuration }
        NumberAnimation { target: ship; property: "y"; to: destination.y; duration: ship.voyageDuration }
    }

    Behavior on rotation {
        NumberAnimation { duration: ship.rotationDuration() }
    }

    Text {
        id: text
        text:   ship.ID
        color: "white"
        anchors.centerIn: parent
        font.pixelSize: 20
    }

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            if(mouse.button == Qt.LeftButton) {
                text.color = "blue"
                ship.focus = true
                //ship.following = false
                for(var key in ship.targetsID)
                    player.shipContainer[ship.targetsID[key]].stopEmitDestination(ship)

                ship.targetsID = new Array
            }

            else if(mouse.button == Qt.RightButton) {
                ship.focus = false
                text.color = "red"
                //ship.following = true
                //player.shipContainer[O].startEmitDestination(ship)
                player.shipContainer[0].startEmitDestination(ship)
                ship.targetsID.push(0)

            }
        }
        onDoubleClicked: {
            ship.setInactive()
        }
    }
}
