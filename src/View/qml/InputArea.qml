import QtQuick 2.0
import QtQuick.Controls 2.11

Rectangle {
  id: root
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
    property var ignoreInput: false
    property var maxHeight: commandAreaBackground.height - 16 - commandAreaBackground.border.width * 2
    property var startingText: "Enter some commands here..."
    width: root.width - 24
    height: contentHeight > maxHeight ? maxHeight: contentHeight
    text: startingText
    color: "#444444"
    x: 10
    wrapMode: TextInput.Wrap
    y: 5
    focus: true
    clip: true

    onTextChanged: {
      if (ignoreInput)
      {
        ignoreInput = false;
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
        if (root.commandHistory[root.commandHistory.length - 1] != text)
        {
          root.commandHistory.push(text)
        }
        commandHistoryScroller.model.append({line: text, textColor: "black"});
        commandHistoryScroller.contentX = 0
        commandHistoryScroller.positionViewAtEnd()
        ignoreInput = true;

        cppCommand.Enqueue(text);

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
            historyModeActiveIndex = root.commandHistory.length;
          }
          historyModeActiveIndex -= historyModeActiveIndex > 0 ? 1: 0;
          ignoreInput = true;
          if (root.commandHistory.length > 0)
          {
            text = root.commandHistory[historyModeActiveIndex];
            inHistoryMode = true;
          }
        }
      }
      else if (event.key == Qt.Key_Down && inHistoryMode)
      {
        ignoreInput = true;
        if (historyModeActiveIndex < root.commandHistory.length - 1)
        {
          historyModeActiveIndex += 1;
          text = root.commandHistory[historyModeActiveIndex];
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