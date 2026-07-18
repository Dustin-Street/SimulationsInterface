import QtQuick
import QtQuick.Controls
import SimulationsInterface

ApplicationWindow {
    id: root
    visible: true
    width: 800
    height: 600


    SimulationController {
        id: controller
    }

    background: Rectangle {
        color: '#393b3a'
        radius: 10;
        border.width: 4
        border.color: '#4bbace'

        Button {
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            id: addSimulation
            text: "Load Simulation"
            onClicked: controller.loadSimulation("Demo", 42.0)
            anchors.margins: 25
        }


    }

}

