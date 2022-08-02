import QtQuick 2.12

Canvas {
  id: mycanvas
  property var originalWidth: mainWindow.minimumWidth - leftPanel.width
  property var originalHeight: mainWindow.minimumHeight - navMenu.height - commandArea.height + mainRect.border.width
  property var widthDiff: width - originalWidth
  property var heightDiff: height - originalHeight

  property var x1List: []
  property var y1List: []
  property var x2List: []
  property var y2List: []
  property var distanceList: []

  property var drawPointX: -1
  property var drawPointY: -1
  property var currentX: canvas.width / 2
  property var currentY: canvas.height / 2
  property var prevDrawPointX: -1
  property var prevDrawPointY: -1

  property bool partialLine: false
  property bool drawState: true
  property bool drawing: false
  property var i: 0

  width: mainRect.width - leftPanel.width
  height: mainRect.height - navMenu.height - commandArea.height + mainRect.border.width
  anchors.leftMargin: - leftPanel.border.width
  anchors.left: leftPanel.right
  anchors.topMargin: -navMenu.border.width
  anchors.top: navMenu.bottom
  z: 1

  signal positionChanged(real xPos, real yPos)

  transitions: Transition {
    NumberAnimation {
      id: animation
      properties: "currentX, currentY"
      duration: distanceList[i] > 0 ? distanceList[i]/(cppTurtle.speed / 100): 1
      }
      onRunningChanged: onDrawLineComplete()
    }

    states: State {
      when: drawState
      PropertyChanges {
        currentX: x2List[i]; currentY: y2List[i]; target: mycanvas
        }
      }

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

      onPaint: {
        var ctx = getContext("2d");
        ctx.lineWidth = cppCanvas.cppPenSize;
        ctx.strokeStyle = cppCanvas.cppPenColor

        ctx.beginPath();
        if(x1List.length > 0)
        {
          if (prevDrawPointX < 0 || prevDrawPointY < 0)
          {
            prevDrawPointX = x1List[i]
            prevDrawPointY = y1List[i]
          }
          ctx.moveTo(prevDrawPointX, prevDrawPointY)
          ctx.lineTo(currentX, currentY)
          prevDrawPointX = currentX
          prevDrawPointY = currentY

          ctx.stroke()
        }
      }

      onCurrentXChanged: {
        requestPaint()
        positionChanged(currentX, currentY)
      }

      onCurrentYChanged: {
        requestPaint()
        positionChanged(currentX, currentY)
      }

      function onDrawLineComplete()
      {
        if (drawing && currentX === x2List[i] && currentY === y2List[i])
        {
          ++i
          if(i >= x1List.length )
          {
            clearLists()
            i = 0;
            drawing = false
          }
          else
          {
            updateDrawPoints()
          }
        }
      }

      function updateDrawPoints()
      {
        currentX = x1List[i]
        currentY = y1List[i]
        prevDrawPointX = -1
        prevDrawPointY = -1
        drawState = !drawState
        drawState = !drawState
      }

      function clearLists()
      {
        x1List = 0
        y1List = 0
        x2List = 0
        y2List = 0
        distanceList = 0
      }



      Connections {
        target: cppCanvas
        onDrawPaths: {
          i = 0
          mycanvas.x1List = x1
          mycanvas.y1List = y1
          mycanvas.x2List = x2
          mycanvas.y2List = y2
          mycanvas.distanceList = distance

          drawing = true
          updateDrawPoints()
        }
        onClearCanvas: {
          var ctx = getContext("2d");
          ctx.clearRect(0, 0, cppCanvas.cppMaxCanvasSize.width, cppCanvas.cppMaxCanvasSize.height)
          mycanvas.requestPaint();
        }
      }
    }
