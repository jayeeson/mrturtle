import QtQuick 2.0
import QtQuick.Controls 2.0

ApplicationWindow {
  id: mainWindow
  minimumHeight: 768
  minimumWidth: 768
  visible: true

  Rectangle {
    id: mainRect
    color: "white"
    width: parent.width
    height: parent.height
    border.color: "black"
    border.width: 4

    NavMenu {
      id: navMenu
    }

    LeftPanel {
      id: leftPanel
    }

    CanvasArea {
      id: canvas
      onPositionChanged: {
        if ( xPos >= 0 && yPos >= 0)
        {
          turtle.x = xPos + canvas.x - turtle.width / 2
          turtle.y = yPos + canvas.y - turtle.height / 2
        }
      }
    }

    Turtle {
      id: turtle
    }

    CommandArea {
      id: commandArea
    }

  }
}