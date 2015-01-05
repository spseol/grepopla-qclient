import QtQuick 2.0

Item {
    id: sizer

    property int duration: 400
    signal boom()

    Rectangle {
        id: circle

        height: width
        radius: width

        color: "orange"

        anchors.centerIn: sizer
    }

    Rectangle {
        id: innerCircle

        height: width
        radius: width

        color: "red"

        anchors.centerIn: circle
    }

    onBoom: SequentialAnimation {
        ScriptAction { script: (function() { circle.opacity = 1.0; innerCircle.opacity = 1.0 })() }

        ParallelAnimation {
            //outer circle
            NumberAnimation { target: circle; property: "width"; from: 0; to: sizer.width; duration: sizer.duration }
            //inner circle
            NumberAnimation { target: innerCircle; property: "width"; from: 0; to: sizer.width / 1.8; duration: sizer.duration }
        }

        //hiding
        ParallelAnimation {
            //outer
            NumberAnimation { target: circle; property: "opacity"; from: 1.0; to: 0.0; duration: sizer.duration * 1.3 }
            //inner
            SequentialAnimation {
                NumberAnimation { duration: sizer.duration / 3 }
                NumberAnimation { target: innerCircle; property: "opacity"; from: 1.0; to: 0.0; duration: sizer.duration * 1.4 }
            }
        }
    }
}
