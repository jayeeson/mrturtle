import QtQuick 2.0
import QtQuick.Controls 2.11



Item {
  width: canvas.width + commandAreaBackground.border.width
  height: 224
  anchors.leftMargin: -leftPanel.border.width
  anchors.left: leftPanel.right
  anchors.top: canvas.bottom
  z: 3


  Rectangle {
    id: commandAreaBackground
    width: parent.width
    height: parent.height
    color: '#aaaa88'
    border.color: mainRect.border.color
    border.width: mainRect.border.width
  }

  CommandHistory {
    id: commandHistoryScroller
  }

  Connections {
    target: cppCanvas
    onAddLineToCommandHistoryPanel: commandHistoryScroller.model.addCommandFeedbackLine(line, color)
  }

  InputArea {
    id: inputArea
  }
}
