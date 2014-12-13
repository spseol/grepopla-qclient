import QtQuick 2.3
import QtQuick.Controls 1.2
import Ship 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Ship {
        id: ship
        x: 100
        y: 100
        width: 200
        height: 200

        imageSource: ""

        Rectangle {
            width: 200
            height: 20
            color: "red"
            anchors.left: parent.left
            anchors.bottom: parent.top
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            ship.destination = Qt.point(mouse.x, mouse.y)
            ship.rotation = ship.calculateRotation()
        }
    }
}
