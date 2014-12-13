import QtQuick 2.0
import Ship 1.0

Ship {
    id: ship
    x: 100
    y: 100
    width: 20
    height: 20

    imageSource: "C:/Users/Sony/Documents/grepopla-qclient/Grepopla/resources/images/black_arrow.svg"

    Rectangle {
        width: 200
        height: 20
        color: "red"
        anchors.left: parent.left
        anchors.bottom: parent.top
    }
}
