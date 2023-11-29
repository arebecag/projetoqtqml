import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Page {
    id: page

    Row {
        anchors.centerIn: parent

        spacing: 35

        Button {
            id: buttonReceber

            text: qsTr("Receber")

            onClicked: receberClicked()
        }

        Button {
            id: buttonSair

            text: qsTr("Sair/Encerrar")

            onClicked: Qt.quit()
        }

    }

    signal receberClicked()
}
