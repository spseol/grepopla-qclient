import QtQuick 2.3
import QtQuick.Controls 1.2
import "components/qml/game_components" as Components

ApplicationWindow {
    id: root

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")



    Components.Player {
        id: player

        Component.onCompleted: {
            player.shipContainer[1].destination = Qt.point(200, 200)
        }
    }

    MouseArea {
        anchors.fill: parent
    acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            //if(mouse.button == Qt.RightButton)
                //player.shipContainer[1].startEmitDestination(player.shipContainer[0])
            for(var key in player.shipContainer)
                if(player.shipContainer[key].focus)
                    player.shipContainer[key].destination = Qt.point(mouse.x, mouse.y)
        }
    }
}
