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
  property var currentX: width / 2
  property var currentY: height / 2
  property var currentXTarget: -1
  property var currentYTarget: -1
  property var prevDrawPointX: -1
  property var prevDrawPointY: -1

  property var precision: 1E-3

  property var i: 0
  
  width: mainRect.width - leftPanel.width
  height: mainRect.height - navMenu.height - commandArea.height + mainRect.border.width
  anchors.leftMargin: - leftPanel.border.width
  anchors.left: leftPanel.right
  anchors.topMargin: -navMenu.border.width
  anchors.top: navMenu.bottom
  z: 1

  signal positionChanged(real xPos, real yPos)

  ParallelAnimation {
    id: drawAnimation
    NumberAnimation { target: mycanvas; property: "currentX"; to: currentXTarget;
      duration: distanceList[i] > 0 ? distanceList[i]/(cppTurtle.speed / (10 * cppTurtle.defaultSpeed)): 10 }
    NumberAnimation { target: mycanvas; property: "currentY"; to: currentYTarget;
      duration: distanceList[i] > 0 ? distanceList[i]/(cppTurtle.speed / (10 * cppTurtle.defaultSpeed)): 10 }
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
    console.log("painting")
    var ctx = getContext("2d");
    ctx.lineWidth = cppCanvas.cppPenSize;
    ctx.strokeStyle = cppCanvas.cppPenColor

    ctx.beginPath();
    if (x1List.length > 0)
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
      timerFps.start()
    }
  }
  function onDrawLineComplete()
  {
    if (i + 1 >= x1List.length )
    {
      clearLists()
      i = 0;
      cppCommand.NotifyRunStopped()
      timerFps.stop();
    }
    else
    {
      ++i
      updateDrawPoints()
      drawAnimation.start()
    }
  }

  Timer {
    id: timerFps
    interval: 16
    onTriggered: mycanvas.requestPaint()
    onRunningChanged: {
      positionChanged(currentX, currentY)
      if (Math.abs(prevDrawPointX - x2List[i]) < precision && Math.abs(prevDrawPointY - y2List[i]) < precision) {
        onDrawLineComplete()
      }
    }
  }

  function updateDrawPoints()
  {
    currentX = x1List[i]
    currentY = y1List[i]
    currentXTarget = x2List[i]
    currentYTarget = y2List[i]
    prevDrawPointX = -1
    prevDrawPointY = -1
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
      mycanvas.x1List = x1
      mycanvas.y1List = y1
      mycanvas.x2List = x2
      mycanvas.y2List = y2
      mycanvas.distanceList = distance

      i = 0
      currentXTarget = x2List[i]
      currentYTarget = y2List[i]
      updateDrawPoints()
      drawAnimation.start()
      mycanvas.requestPaint();
    }
    onClearCanvas: {
      var ctx = getContext("2d");
      ctx.clearRect(0, 0, cppCanvas.cppMaxCanvasSize.width, cppCanvas.cppMaxCanvasSize.height)
      mycanvas.requestPaint();
    }
  }
}
