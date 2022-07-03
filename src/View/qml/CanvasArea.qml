import QtQuick 2.0

Canvas {
  property var originalWidth: mainWindow.minWidth - leftPanel.width
  property var originalHeight: mainWindow.minHeight - navMenu.height - commandArea.height + mainRect.border.width
  width: mainRect.width - leftPanel.width
  height: mainRect.height - navMenu.height - commandArea.height + mainRect.border.width
  anchors.leftMargin: - leftPanel.border.width
  anchors.left: leftPanel.right
  anchors.topMargin: -navMenu.border.width
  anchors.top: navMenu.bottom
  z: 1

  Binding {
    target: cppTurtle
    property: "canvasSize"
    value: Qt.size(width, height)
  }
}
