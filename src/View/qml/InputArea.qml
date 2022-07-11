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
  color: "#999966"

  border.width: 2
  border.color: "#666644"

  TextInput {
    id: textInput
    property var inHistoryMode: false
    property var historyModeActiveIndex: 0
    property var ignoreTextChange: false
    property var maxHeight: commandAreaBackground.height - 16 - commandAreaBackground.border.width * 2
    property var startingText: "Enter some commands here..."
    width: inputAreaRect.width - 24
    height: contentHeight > maxHeight ? maxHeight: contentHeight
    text: startingText
    color: "#444444"
    x: 10
    wrapMode: TextInput.Wrap
    y: 5
    focus: true
    clip: true

    onTextChanged: {
      if (ignoreTextChange)
      {
        ignoreTextChange = false;
      }
      else if (inHistoryMode)
      {
        inHistoryMode = false;
      }
    }

    onActiveFocusChanged: {
      if (focus && text === startingText)
      {
        text = "";
        color = "black";
      }
      else if (!focus && text === "")
      {
        text = startingText;
        color = "#444444";
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
        commandHistoryScroller.contentX = 0
        commandHistoryScroller.positionViewAtEnd()
        ignoreTextChange = true;

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