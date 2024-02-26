import QtQuick
import QtQuick.Controls
import GameLogic 1.0
import QtQuick.Layouts

Window {
    minimumWidth:900
    minimumHeight: 500
    visible: true
    title: qsTr("Обмани соседа")


    GameLogic {
        id: gameLogic


    }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: page1
    }

    Page {
        id: page1

        Column {
            id:column1
            y: parent.height/2 - column1.height/2
            x: parent.width/2 - column1.width/2

            spacing: 3

            ComboBox {
                id: cb_players
                anchors.margins: 10
                model: ["2", "3", "4"]
            }

            ComboBox {
                id: cb_cards
                anchors.margins: 10
                model: ["36", "52"]
            }

            ComboBox {
                id: cb_amountOfCards
                anchors.margins: 10
                model: ["1", "2", "3", "4","5", "6", "7", "8", "9", "10", "11", "12", "13", "14",
                    "15", "16", "17", "20", "24", "25", "26", "27", "29", "30", "31", "32", "33", "34",
                    "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47",
                    "48", "49", "51", "52"]
            }

            Button {
                id: btn1
                text: "Играть"
                anchors.margins: 10

                onClicked: {
                    stackView.push(page2);

                    gameLogic.startGame(cb_players.valueAt(cb_players.currentIndex), cb_cards.valueAt(cb_cards.currentIndex));
                }
            }
        }

        background:  Rectangle {
            Image {
                id: image1
                source: "qrc:/new/pictures/CardsTable.jpg"
                anchors.fill: parent
            }
        }
    }

    Page {
        id: page2
        visible: false
        Button {
            id: btn2
            text: "Назад"
            y: parent.height/2 - btn1.height/2
            x: parent.width/2 - btn1.width/2
            anchors.margins: 10

            onClicked: {
                stackView.pop();
            }
        }

        RowLayout {
            id: bottomRowlayout
            height: parent.height/2
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.margins: 10
            spacing: 1

            //Rectangle { Layout.fillHeight: true; Layout.fillWidth: true; color: "blue" }

            Repeater {
                id:repeater
                model: listModel
                property int amountOfCards: cb_cards.valueAt(cb_cards.currentIndex)/cb_players.valueAt(cb_players.currentIndex)
                Image {
                    Layout.maximumWidth: bottomRowlayout.width/repeater.amountOfCards - 5
                    Layout.maximumHeight: bottomRowlayout.height/4
                    Layout.bottomMargin: 2
                    source: model.source
                }
            }

            ListModel {
                id: listModel
//                ListElement { source: "qrc:/1/CardGame/cards/ACE_clubs.png" }
//                ListElement { source: "qrc:/1/CardGame/cards/ACE_diamonds.png" }
//                ListElement { source: "qrc:/1/CardGame/cards/ACE_hearts.png" }
//                ListElement { source: "qrc:/1/CardGame/cards/ACE_spades.png" }
//                ListElement { source: "qrc:/1/CardGame/cards/King_clubs.png" }
//                ListElement { source: "qrc:/1/CardGame/cards/King_diamonds.png" }
//                ListElement { source: "qrc:/1/CardGame/cards/King_hearts.png" }
//                ListElement { source: "qrc:/1/CardGame/cards/King_spades.png" }
//                ListElement { source: "qrc:/1/CardGame/cards/ACE_spades.png" }
                ListElement { source: "qrc:/1/CardGame/cards/King_hearts.png" }
                ListElement { source: "qrc:/1/CardGame/cards/ACE_clubs.png" }
                ListElement { source: "qrc:/1/CardGame/cards/King_hearts.png" }
                ListElement { source: "qrc:/1/CardGame/cards/ACE_diamonds.png" }
                ListElement { source: "qrc:/1/CardGame/cards/ACE_diamonds.png" }
                ListElement { source: "qrc:/1/CardGame/cards/King_hearts.png" }
                ListElement { source: "qrc:/1/CardGame/cards/King_hearts.png" }
                ListElement { source: "qrc:/1/CardGame/cards/King_hearts.png" }
                ListElement { source: "qrc:/1/CardGame/cards/ACE_spades.png" }
//                ListElement { source: "qrc:/1/CardGame/cards/ACE_spades.png" }
//                ListElement { source: "qrc:/1/CardGame/cards/ACE_spades.png" }
//                ListElement { source: "qrc:/1/CardGame/cards/ACE_spades.png" }
//                ListElement { source: "qrc:/1/CardGame/cards/King_hearts.png" }
//                ListElement { source: "qrc:/1/CardGame/cards/King_hearts.png" }
//                ListElement { source: "qrc:/1/CardGame/cards/King_spades.png" }
//                ListElement { source: "qrc:/1/CardGame/cards/King_spades.png" }
//                ListElement { source: "qrc:/1/CardGame/cards/King_spades.png" }
            }
        }

        background: Rectangle {
            Image {
                id: image2
                source: "qrc:/new/pictures/background.jpg"
                anchors.fill: parent
            }
        }
    }
}
