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

  ListView {
    id: commandHistoryScroller
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
      color: textColor != undefined ? textColor: 'black'
    }
  }

  Connections {
    target: cppCanvas
    onAddLineToCommandHistoryPanel: previousCommandText.addCommandFeedbackLine(line, color)
  }


  Rectangle {
    id: inputArea
    property var commandHistory: []
    width: parent.width - commandAreaBackground.border.width * 2 - 6
    height: textInput.height + 10
    anchors.left: commandAreaBackground.left
    anchors.leftMargin: commandAreaBackground.border.width + 3

    anchors.bottom: commandAreaBackground.bottom
    anchors.bottomMargin: commandAreaBackground.border.width + 3
    color: '#999966'

    border.width: 2
    border.color: '#666644'

    TextInput {
      id: textInput
      property var inHistoryMode: false
      property var historyModeActiveIndex: 0
      property var ignoreTextChange: false
      width: inputArea.width - 24
      text: "Enter some commands here..."
      color: '#444444'
      x: 10
      y: 5
      wrapMode: TextInput.Wrap
      focus: true

      onTextChanged: {
        if (ignoreTextChange)
        {
          ignoreTextChange = false;
        }
        else
        {
          inHistoryMode = false;
        }
        width = inputArea.width - 24
        commandHistoryScroller.contentItem.contentY = commandHistoryScroller.contentItem.contentHeight - commandHistoryScroller.height;
      }

      onActiveFocusChanged: {
        if (focus && text === "Enter some commands here...")
        {
          text = "";
          color= 'black';
        }
        else if (!focus && text === "")
        {
          text = "Enter some commands here...";
          color = '#444444';
        }
      }

      onAccepted: {
        if ( text !== "")
        {
          if (inputArea.commandHistory[inputArea.commandHistory.length - 1] != text)
          {
            inputArea.commandHistory.push(text)
          }
          previousCommandText.append({line: text});
          commandHistoryScroller.contentItem.contentX = 0
          ignoreTextChange = true;

          // todo: hook to command handler
          cppCommand.Parse(text);
          cppCommand.Execute();

          text = "";
        }
      }

      Keys.onPressed: {
        if (event.key == Qt.Key_Up)
        {
          if (text === "" || inHistoryMode)
          {
            if (text === "")
            {
              historyModeActiveIndex = inputArea.commandHistory.length;
            }
            historyModeActiveIndex -= historyModeActiveIndex > 0 ? 1: 0;
            ignoreTextChange = true;
            text = inputArea.commandHistory[historyModeActiveIndex];
            inHistoryMode = true;
          }
        }
        else if (event.key == Qt.Key_Down && inHistoryMode)
        {
          ignoreTextChange = true;
          if (historyModeActiveIndex < inputArea.commandHistory.length - 1)
          {
            historyModeActiveIndex += 1;
            text = inputArea.commandHistory[historyModeActiveIndex];
          }
          else
          {
            text = "";
            inHistoryMode = false;
          }
        }
      }
    }
  }
}
