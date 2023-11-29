import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    title: qsTr("Envia")

    width: 640
    height: 480

    visible: true

    StackView {
        id: stackMain

        initialItem: viewEnvia

        anchors.fill: parent

        ViewEnvia {
            id: viewEnvia

            onArquivoClicked: stackMain.push(viewArquivo)
            onComandoClicked: stackMain.push(viewComando)

            visible: false
        }

        ViewArquivo {
            id: viewArquivo

            visible: false
        }

        ViewComando {
            id: viewComando

            visible: false
        }

        onCurrentItemChanged: currentItem.forceActiveFocus()
    }
}

