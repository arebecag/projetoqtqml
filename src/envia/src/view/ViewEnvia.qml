import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15

Page {
    id: page

    Row {
        anchors.centerIn: parent

        spacing: 35

        Button {
            id: buttonAbrir

            text: qsTr("Abrir Arquivo")
            highlighted: true

            onClicked: page.arquivoClicked()
        }

        Button {
            id: buttonEnviar

            text: qsTr("Enviar Comando")
            highlighted: true

            Material.accent: Material.Green

            onClicked: page.comandoClicked()
        }

        Button {
            id: buttonSair

            text: qsTr("Sair/Encerrar")
            highlighted: true

            Material.accent: Material.Red

            onClicked: Qt.quit()
        }

    }

    signal arquivoClicked()
    signal comandoClicked()
}
