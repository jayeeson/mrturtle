import QtQuick 2.0

ListView {
  id: commandHistoryList
  property var myMaxHeight: commandAreaBackground.height - inputArea.height - commandAreaBackground.border.width * 2 - 20
  width: parent.width
  height: contentItem.childrenRect.height > myMaxHeight ? myMaxHeight: contentItem.childrenRect.height
  anchors.bottom: inputArea.top
  anchors.bottomMargin: 3
  anchors.left: parent.left
  anchors.leftMargin: 10

  model: ListModel {
    id: previousCommandText
    function addCommandFeedbackLine(str, color)
    {
      var textColor = color !== "" ? color: textLine.color;
      append({line: str, textColor: textColor});
    }
  }

  delegate: Text {
    id: textLine
    text: line
    wrapMode: TextEdit.NoWrap
    color: textColor
  }
}
