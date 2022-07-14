import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
  height: 120
  width: 120
  x: cppTurtle.position.x - width / 2 + canvas.x + canvas.width / 2
  y: -cppTurtle.position.y - height / 2 + canvas.y + canvas.height / 2
  z: 2

  Image {
    id: turtleImage
    anchors.centerIn: parent
    source: "pics/turtle.svg"
    sourceSize: Qt.size(parent.width, parent.height)
    transform: Rotation {
      id: rotation
      angle: -(cppTurtle.heading - 90)
    }
    visible: false
  }

  ColorOverlay {
    anchors.fill: turtleImage
    source: turtleImage
    color: cppCanvas.cppPenColor
    transform: rotation
    antialiasing: true
  }

}