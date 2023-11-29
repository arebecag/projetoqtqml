import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1

Page {
    id: page

    padding: 10

    header: ToolBar {
        ToolButton {
            text: "←"

            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.verticalCenter: parent.verticalCenter

            onClicked: {
                limparDados()

                page.StackView.view.pop()
            }
        }

        Label {
            text: qsTr("Enviar comando")

            anchors.centerIn: parent

            font.pixelSize: 20
        }
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 5

        spacing: 5

        Label {
            text: qsTr("Tópico")

            Layout.fillWidth: true
        }

        TextField {
            id: topico

            Layout.fillWidth: true

            focus: true
        }

        Label {
            text: qsTr("Conteúdo");

            Layout.fillWidth: true
        }

        ScrollView {
            Layout.fillWidth: true
            Layout.fillHeight: true

            TextArea {
                id: conteudo

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
                text: "Enviar"

                enabled: topico.text.trim() != "" && conteudo.text.trim() != ""
                flat: true
                highlighted: true

                onClicked: {
                    servidor.topico = topico.text
                    servidor.conteudo = conteudo.text
                }
            }
        }
    }

    function limparDados()
    {
        topico.text = ""
        conteudo.text = ""
    }
}

