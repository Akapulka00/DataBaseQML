import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Таблицы из БД")

    Button {
        text: "Open File Dialog"
        onClicked: {
            myDatabase.fileDialog()
        }
    }

    TableView {
        y:50
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 80
        TableViewColumn {
            role: "date"
            title: "Время"
        }

        TableViewColumn {
            role: "purchase"
            title: "Покупка"
            delegate: Rectangle {
                width: 100
                height: 40
                color: {
                    var buff = (parseFloat(model.purchase) > myModel.prevPurchase) ? "#ABEE53" : "#F66086"
                    myModel.prevPurchase = parseFloat(model.purchase)
                    return buff
                }
                Text {
                    anchors.centerIn: parent
                    text: {
                        if (parseFloat(model.purchase) > myModel.prevPurchase) {
                            var strel = " ↑ "
                        } else {
                            var strel = " ↓ "
                        }
                        return model.purchase + strel
                    }
                    color: "white"
                }
            }
        }

        TableViewColumn {
            role: "sell"
            title: "Продажа"
            delegate: Rectangle {
                width: 100
                height: 40
                color: {
                    var buf = (parseFloat(model.sell) > myModel.prevSell) ? "#ABEE53" : "#F66086"
                    myModel.prevSell = parseFloat(model.sell)
                    return buf
                }
                Text {
                    anchors.centerIn: parent
                    text: {
                        if (parseFloat(model.sell) > myModel.prevSell) {
                            var strel = " ↑ "
                        } else {
                            var strel = " ↓ "
                        }
                        return model.sell + strel
                    }
                    color: "white"
                }
            }
        }

        model: myModel
    }
}
