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

    TextField {
        id: input
        width: 100
        height: 30
        onAccepted: {
            var text = input.text

            mainMouseArea.enabled = true
            input.visible = false
            game.myNick = text
            console.log(text)

            var datas = {}
            datas.nick = text
            socket.sendTextMessage(JSON.stringify(datas))
        }
    }

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
                    WSCommands.initPlayer(command.id, command.entity, command.nick)
                else
                    WSCommands.initObject(command.id, command.entity, command.owner_id, command.values.x, command.values.y, command.values.size)
            }
            //---------------INIT---------------

            //---------------ACTION---------------
            else if(command.command == "action") {
                if(command.action == "capture")  //capturing planet
                    WSCommands.capturePlanet(command.id, command.entity, command.values.capturer_id, command.values.previous_owner_id)

                else if(command.action == "follow")
                    WSCommands.followShip(command.id, command.owner_id, command.values.following_ship_id, command.values.follower_id)
            }
            //---------------ACTION----------------

        }
    }
    //------------------------------------


}
