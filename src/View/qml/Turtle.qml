import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
  id: turtle
  property var aspectRatio: 3/4
  height: 40
  width: height * aspectRatio
  x: cppTurtle.position.x - width / 2 + canvas.x + canvas.width / 2
  y: -cppTurtle.position.y - height / 2 + canvas.y + canvas.height / 2
  z: 2

  Image {
    id: turtleImage
    anchors.centerIn: parent
    source: "pics/turtle.svg"
    sourceSize: Qt.size(parent.width, parent.height)
    visible: false
    transform: Rotation {
      id: rotation
      angle: -(cppTurtle.heading - 90)
      origin.x: turtle.width / 2
      origin.y: turtle.height / 2
    }
  }

  ColorOverlay {
    anchors.fill: turtleImage
    source: turtleImage
    color: cppCanvas.cppPenColor
    transform: rotation
    antialiasing: true
    visible: cppTurtle.visible
  }

}