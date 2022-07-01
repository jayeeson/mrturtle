import QtQuick 2.0
import QtQuick.Controls 2.0

ApplicationWindow {
  id: mainWindow
  property var minHeight: 768
  property var minWidth: 768
  minimumHeight: minHeight
  minimumWidth: minWidth
  visible: true

  Rectangle {
    id: mainRect
    color: 'white'
    width: parent.width
    height: parent.height
    border.color: 'black'
    border.width: 4

    NavMenu {
      id: navMenu
    }

    Rectangle {
      id: leftPanel
      width: 224
      height: parent.height - navMenu.height + border.width
      anchors.topMargin: -parent.border.width
      anchors.bottomMargin: -parent.border.width
      anchors.top: navMenu.bottom
      border.color: parent.border.color
      border.width: parent.border.width
      color: '#999999'
    }

    CanvasArea {
      id: canvas
    }

    Turtle {
      id: turtle
    }

    CommandArea {
      id: commandArea
    }
  }
}