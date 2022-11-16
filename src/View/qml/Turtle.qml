import QtQuick 2.12
import QtGraphicalEffects 1.0

Item {
  id: turtle
  property var aspectRatio: 3/4
  property var precision: 1E-7
  property alias turtleAngle: rotation.angle
  property var startAngle: turtleAngle
  property var endAngle: 0
  property var rotationTime: 0
  height: 40
  width: height * aspectRatio
  x: -width / 2 + canvas.x + canvas.width / 2
  y: -height / 2 + canvas.y + canvas.height / 2
  z: 2

  function onRotateCompleted() {
    cppCommand.NotifyRunStopped()
  }

  function getRotationTime() {
    var diff = Math.abs(endAngle - startAngle)
    return diff * 750 / cppTurtle.speed
  }

  NumberAnimation on turtleAngle { 
    id: anim;
    from: startAngle;
    to: endAngle;
    duration: rotationTime;

    onFinished: turtle.onRotateCompleted()
  }

  Image {
    id: turtleImage
    anchors.centerIn: parent
    source: "pics/turtle.svg"
    sourceSize: Qt.size(parent.width, parent.height)
    visible: false
    transform: Rotation {
      id: rotation
      angle: 0
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

  Connections {
    target: cppTurtle
    onDoRotate: (angle) => {
      startAngle = turtleAngle;
      endAngle = startAngle - angle; // angle is negative ? 
      rotationTime = turtle.getRotationTime()
      anim.start()
    }
  }
}