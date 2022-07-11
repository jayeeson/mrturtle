import QtQuick 2.0

Image {
  source: "pics/turtle.png"
  height: 60
  width: 60
  x: cppTurtle.position.x - width / 2 + canvas.x + canvas.originalWidth / 2 + canvas.widthDiff / 2;
  y: -cppTurtle.position.y - height / 2 + canvas.y + canvas.originalHeight / 2 + canvas.heightDiff / 2;
  z: 2
  rotation: -(cppTurtle.heading - 90)
}