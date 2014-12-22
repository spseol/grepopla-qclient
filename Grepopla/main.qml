import QtQuick 2.3
import QtQuick.Controls 1.2
import Qt.WebSockets 1.0
import "components/qml/game_components" as Components
import "ws_commands/wscommands.js" as WSCommands

ApplicationWindow {
    id: root

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Components.Game {
        id: game

        Component.onCompleted: {
            //var component = Qt.createComponent("components/qml/game_components/Player.qml")
            //game.playerContainer.push(component.createObject(root))
        }
    }

    //------------DATA TRANSFER-----------
    WebSocket {
        id: socket

        active: true
        url: "ws://hroch.spseol.cz:8888"

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

        onTextMessageReceived: {
            var command = JSON.parse(message)

            //---------------INIT---------------
            if(command.command == "init") {
                if(command.entity == "Player")
                    WSCommands.initPlayer(command.id, command.entity)
                else
                    WSCommands.initObject(command.id, command.entity, command.values.owner_id, command.values.x, command.values.y, command.values.size)
            }
            //---------------INIT---------------

            //---------------CAPTURE---------------
            else if(command.command == "action")
                if(command.values.action == "capture")  //capturing planet
                    WSCommands.capturePlanet(command.id, command.entity, command.values.capturer_id, command.values.previous_owner_id)
            //---------------CAPTURE---------------
        }
    }
    //------------------------------------

    MouseArea {
        anchors.fill: parent
    acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            console.log("click")
                socket.textMessageReceived('{"command":"init","id": 1, "entity": "Player"}')
                socket.textMessageReceived('{"values": {"y": 60, "x": 160, "size": 4, "owner_id": 1}, "command": "init", "id": 3, "entity": "Planet"}')
                socket.textMessageReceived('{"command":"init","id": 1, "entity": "Player"}')
                socket.textMessageReceived('{"values": {"y": 60, "x": 160, "size": 4, "owner_id": 1}, "command": "init", "id": 3, "entity": "Planet"}')

        }
    }
}
