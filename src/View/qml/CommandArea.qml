import QtQuick 2.0

Rectangle {
  width: canvas.width + border.width
  height: 224
  anchors.leftMargin: -leftPanel.border.width
  anchors.left: leftPanel.right
  anchors.top: canvas.bottom
  border.color: parent.border.color
  border.width: parent.border.width
  color: '#aaaa88'
  z: 3
}