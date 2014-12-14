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
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            player.shipContainer[0].destination = Qt.point(mouse.x, mouse.y)
        }
    }
}
