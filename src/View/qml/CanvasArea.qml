import QtQuick 2.0

Canvas {
  property var originalWidth: mainWindow.minimumWidth - leftPanel.width
  property var originalHeight: mainWindow.minimumHeight - navMenu.height - commandArea.height + mainRect.border.width
  width: mainRect.width - leftPanel.width
  height: mainRect.height - navMenu.height - commandArea.height + mainRect.border.width
  anchors.leftMargin: - leftPanel.border.width
  anchors.left: leftPanel.right
  anchors.topMargin: -navMenu.border.width
  anchors.top: navMenu.bottom
  z: 1

  Binding {
    target: cppCanvas
    property: "cppCanvasSize"
    value: Qt.size(width, height)
  }

  Binding {
    target: cppCanvas
    property: "cppOrigCanvasSize"
    value: Qt.size(originalWidth, originalHeight)
  }

}
