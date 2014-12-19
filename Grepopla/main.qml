import QtQuick 2.3
import QtQuick.Controls 1.2
import Qt.WebSockets 1.0
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

    Components.Game {

    }

    //------------DATA TRANSFER-----------
    WebSocket {
        id: socket

        active: true
        url: "ws://192.168.2.111:8888/ws/control"

        onStatusChanged: {
            var actualStatus = socket.status

            switch(actualStatus) {
                case WebSocket.Connecting:
                    console.log("Connecting");
                    break;

                case WebSocket.Open:
                    console.log("Open");
                    break;

                case WebSocket.Closing:
                    console.log("Closing");
                    break;

                case WebSocket.Closed:
                    console.log("Closed");
                    break;

                case WebSocket.Error:
                    console.log("Error (" + socket.errorString + ")")
                    break;
            }
        }
    }
    //------------------------------------

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
