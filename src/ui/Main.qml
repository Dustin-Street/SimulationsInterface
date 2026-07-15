import QtQuick
import QtQuick.Controls


ApplicationWindow {
    id: root
    visible: true
    width: 800
    height: 600


    background: Rectangle {
        color: '#393b3a'
        radius: 10;
        border.width: 4
        border.color: '#4bbace'

        Button {
            id: addSimulation
            text: "Load Simulation"
            onClicked: loadSimulation()
        }
        

    }

}

