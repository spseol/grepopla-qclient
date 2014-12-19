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
    }

    Components.Game {
        id: game

        Component.onCompleted: {
            var component = Qt.createComponent("components/qml/game_components/Player.qml")
            game.playerContainer.push(component.createObject(root))
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

            if(command.command == "init") {
                var component = Qt.createComponent("components/qml/game_components/" + command.entity + ".qml")
                var object = component.createObject(root);
                var len = game.playerContainer[command.values.owner_id].objectContainer[command.entity].length;

                object.ID = command.id; //ID
                object.owner = game.playerContainer[command.values.owner_id];
                object.x = command.values.x;
                object.y = command.values.y;

                if(command.entity == "Planet")
                    ;//object.size = command.values.size;    //not ready

                else if(command.entity == "Ship") {
                    var types = ["SmallShip", "ColonisingShip"];
                    object.type = types(command.values.type);
                }

                game.playerContainer[command.values.owner_id].objectContainer[command.entity].push(object);

            }
        }
    }
    //------------------------------------

    MouseArea {
        anchors.fill: parent
    acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
          /*  for(var key in player.shipContainer)
                if(player.shipContainer[key].focus)
                    player.shipContainer[key].destination = Qt.point(mouse.x, mouse.y)*/
            socket.textMessageReceived('{"values": {"y": 60, "x": 160, "size": 4, "owner_id": 0}, "command": "init", "id": 3, "entity": "Planet"}')
        }
    }
}
