import QtQuick 2.0

Image {
  source: "pics/turtle.png"
  height: 60
  width: 60
  x: cppTurtle.position.x - width / 2 + canvas.x + canvas.width / 2
  y: -cppTurtle.position.y - height / 2 + canvas.y + canvas.height / 2
  z: 2
  rotation: -(cppTurtle.heading - 90)
}