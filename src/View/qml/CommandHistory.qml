import QtQuick 2.0
import QtQuick.Controls 2.10

ListView {
  id: commandHistoryList
  property var myMaxHeight: commandAreaBackground.height - inputArea.height - commandAreaBackground.border.width * 2 - 8
  width: parent.width - commandAreaBackground.border.width * 2 - 8
  height: contentItem.childrenRect.height > myMaxHeight ? myMaxHeight: contentItem.childrenRect.height
  anchors.bottom: inputArea.top
  anchors.bottomMargin: 2
  anchors.left: parent.left
  anchors.leftMargin: 10
  flickableDirection: Flickable.AutoFlickIfNeeded
  interactive: false
  clip: true

  ScrollBar.vertical: ScrollBar {
    id: vertScroll
    width: 16
    anchors.right: parent.right
  }

  ScrollBar.horizontal: ScrollBar {
    id: horizScroll
    height: 16
  }

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
    width: commandHistoryList.width

    Component.onCompleted: {
      if(contentWidth > commandHistoryList.contentWidth)
      {
        commandHistoryList.contentWidth = contentWidth
      }
      commandHistoryScroller.contentX = 0
      commandHistoryScroller.contentY = commandHistoryScroller.contentHeight
    }
  }
}
