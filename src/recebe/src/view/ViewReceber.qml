import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1

Page {
    id: page

    header: ToolBar {
        ToolButton {
            text: "Voltar"

            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.verticalCenter: parent.verticalCenter

            onClicked: {
                limparDados()

                page.StackView.view.pop()
            }
        }

        Label {
            text: qsTr("Receber")

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

        Rectangle {
            border.color: "grey"
            border.width: 2

            height: 30

            Layout.fillWidth: true

            TextEdit {
                id: topico

                anchors.fill: parent
                anchors.margins: 5

                focus: true
            }
        }

        Label {
            text: qsTr("Conteúdo");

            Layout.fillWidth: true
        }

        Rectangle {
            border.color: "grey"
            border.width: 2

            Layout.fillWidth: true
            Layout.fillHeight: true

            ScrollView {
                anchors.fill: parent

                TextArea {
                    id: conteudo

                    readOnly: true

                    wrapMode: TextArea.Wrap
                }

                ScrollBar.vertical.interactive: true
            }
        }

        Row {
            id: controles

            layoutDirection: Qt.RightToLeft

            spacing: 5

            height: 50

            Layout.fillWidth: true

            Button {
                text: "Receber"

                enabled: topico.text.trim() != ""

                onClicked: {
                    if (topico.text == "") {
                        erroCampoNaoPreenchido("Tópico")

                        topico.focus = true

                        return
                    }

                    var resposta = cliente.consulta(topico.text)

                    conteudo.text = resposta
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

