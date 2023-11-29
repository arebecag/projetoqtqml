import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.1

import br.com.jacto 1.0

Page {
    id: page

    header: ToolBar {
        ToolButton {
            text: "←"

            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.verticalCenter: parent.verticalCenter

            onClicked: page.StackView.view.pop()
        }

        Label {
            text: qsTr("Abrir arquivo")

            anchors.centerIn: parent

            font.pixelSize: 20
        }
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 5

        spacing: 5

        ScrollView {
            Layout.fillWidth: true
            Layout.fillHeight: true

            TextArea {
                id: conteudo

                readOnly: true
                focus: true

                wrapMode: TextArea.Wrap
            }

            ScrollBar.vertical.interactive: true
        }

        Row {
            id: controles

            layoutDirection: Qt.RightToLeft

            spacing: 5

            height: 50

            Layout.fillWidth: true

            Button {
                text: "Abrir"

                flat: true
                highlighted: true

                onClicked: dialog.open()
            }
        }
    }

    FileDialog {
        id: dialog

        title: "Escolha o arquivo a ser aberto"

        folder: shortcuts.documents

        nameFilters: ["Arquivos de texto (*.txt)", "Todos os arquivos (*.*)"]

        onAccepted: {
            if (dialog.fileUrl.toString() != "") {
                conteudo.text = leitor.ler(dialog.fileUrl)
            }
        }
    }

    Leitor {
        id: leitor
    }
}

