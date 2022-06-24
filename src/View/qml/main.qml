import QtQuick 2.0
import QtQuick.Controls 2.0

ApplicationWindow {
  id: mainWindow
  minimumHeight: 768
  minimumWidth: 768
  visible: true

  Rectangle {
    color: 'white'
    width: parent.width
    height: parent.height
    border.color: 'black'
    border.width: 4

    Rectangle {
      id: topPanel
      width: parent.width
      height: 40
      border.color: parent.border.color
      border.width: parent.border.width
      color: '#666666'
    }
    
    Rectangle {
      id: leftPanel
      width: 224
      height: parent.height - topPanel.height + border.width
      anchors.topMargin: -parent.border.width
      anchors.bottomMargin: -parent.border.width
      anchors.top: topPanel.bottom
      border.color: parent.border.color
      border.width: parent.border.width
      color: '#999999'
    }

    Canvas {
      id: canvas
      width: parent.width - leftPanel.width
      height: parent.height - topPanel.height - commandArea.height + parent.border.width
      anchors.leftMargin: -leftPanel.border.width
      anchors.left: leftPanel.right
      anchors.topMargin: -topPanel.border.width
      anchors.top: topPanel.bottom
    }

    Rectangle {
      id: commandArea
      width: canvas.width + border.width
      height: 224
      anchors.leftMargin: -leftPanel.border.width
      anchors.left: leftPanel.right
      anchors.top: canvas.bottom
      border.color: parent.border.color
      border.width: parent.border.width
      color: '#aaaa88'
    }
  }
}