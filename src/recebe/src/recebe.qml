import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    title: qsTr("Recebe")

    width: 640
    height: 480

    visible: true

    StackView {
        id: stackMain

        initialItem: viewRecebe

        anchors.fill: parent

        ViewRecebe {
            id: viewRecebe

            visible: false

            onReceberClicked: stackMain.push(viewReceber)
        }

        ViewReceber {
            id: viewReceber

            visible: false
        }

        onCurrentItemChanged: currentItem.forceActiveFocus()
    }
}

