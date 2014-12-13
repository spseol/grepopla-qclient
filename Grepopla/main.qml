import QtQuick 2.3
import QtQuick.Controls 1.2
import "components/qml/game_components" as Components

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Components.Ship {
        id: ship
        x: 100
        y: 100
        width: 20
        height: 20
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            ship.destination = Qt.point(mouse.x, mouse.y)
            ship.rotation = ship.calculateRotation()
        }
    }
}
