import QtQuick 2.0

Rectangle {
  width: 224
  height: parent.height - navMenu.height + border.width
  anchors.topMargin: -parent.border.width
  anchors.bottomMargin: -parent.border.width
  anchors.top: navMenu.bottom
  border.color: parent.border.color
  border.width: parent.border.width
  color: "#999999"
  z: 3
}