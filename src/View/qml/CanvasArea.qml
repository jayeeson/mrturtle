import QtQuick 2.0

Canvas {
  property var originalWidth: mainWindow.minimumWidth - leftPanel.width
  property var originalHeight: mainWindow.minimumHeight - navMenu.height - commandArea.height + mainRect.border.width
  property var widthDiff: width - originalWidth
  property var heightDiff: height - originalHeight

  property var x1List: []
  property var y1List: []
  property var x2List: []
  property var y2List: []

  id: mycanvas

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

  onPaint: {
    var ctx = getContext("2d");
    ctx.lineWidth = 2;

    ctx.beginPath ();
    if (x1List) // if one has values, all do
  {
    for(var i = 0; i < x1List.length; ++i)
  {
    ctx.moveTo(x1List[i], y1List[i])
    ctx.lineTo(x2List[i], y2List[i])
  }
  ctx.stroke()


  x1List = []
  y1List = []
  x2List = []
  y2List = []
}
}

Connections {
  target: cppCanvas
  onDrawPaths: {
    mycanvas.x1List = x1
    mycanvas.y1List = y1
    mycanvas.x2List = x2
    mycanvas.y2List = y2
    mycanvas.requestPaint();
  }
  onClearCanvas: {
    var ctx = getContext("2d");
    ctx.clearRect(0, 0, cppCanvas.cppMaxCanvasSize.width, cppCanvas.cppMaxCanvasSize.height)
    mycanvas.requestPaint();
  }
}
}
