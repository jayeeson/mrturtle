import QtQuick 2.0
import QtQuick.Controls 2.11

Rectangle {
  id: inputAreaRect
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
    width: inputAreaRect.width - 24
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
      width = inputAreaRect.width - 24
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
        if (inputAreaRect.commandHistory[inputAreaRect.commandHistory.length - 1] != text)
        {
          inputAreaRect.commandHistory.push(text)
        }
        commandHistoryScroller.model.append({line: text, textColor: "black"});
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
            historyModeActiveIndex = inputAreaRect.commandHistory.length;
          }
          historyModeActiveIndex -= historyModeActiveIndex > 0 ? 1: 0;
          ignoreTextChange = true;
          text = inputAreaRect.commandHistory[historyModeActiveIndex];
          inHistoryMode = true;
        }
      }
      else if (event.key == Qt.Key_Down && inHistoryMode)
      {
        ignoreTextChange = true;
        if (historyModeActiveIndex < inputAreaRect.commandHistory.length - 1)
        {
          historyModeActiveIndex += 1;
          text = inputAreaRect.commandHistory[historyModeActiveIndex];
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