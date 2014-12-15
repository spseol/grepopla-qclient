import QtQuick 2.0
import Ship 1.0

Ship {
    id: ship

    imageSource: "C:/Users/Sony/Documents/grepopla-qclient/Grepopla/resources/images/Symbol_Up_Arrow.svg"
    rotationSpeed: 5

    onDestinationChanged: ParallelAnimation {
        objectName: "moveAnimation"

        NumberAnimation { target: ship; property: "x"; to: destination.x; duration: ship.voyageDuration }
        NumberAnimation { target: ship; property: "y"; to: destination.y; duration: ship.voyageDuration }
    }

    Behavior on rotation {
        NumberAnimation { duration: ship.rotationDuration() }
    }

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            if(mouse.button == Qt.LeftButton)
                ship.focus = true
            else if(mouse.button == Qt.RightButton)
                ship.focus = false
        }
    }
}
