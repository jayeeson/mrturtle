using xserver:
set DISPLAY to `DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0` to set display to windows, then run program.

can do this from w with vbscript:
`args = "-c" & " -l " & """DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0 helloworld""" WScript.CreateObject("Shell.Application").ShellExecute "bash", args, "", "open", 0`

replace terminator with file

### Design

LOGO at its core consists of two parts:

1. a command interpreter that allows a) moving a sprite and b) drawing lines
2. the drawing area, consisting of backdrop (canvas) and sprite (turtle)

extended third part: script execution that builds on 1)
optional fourth part: tutorials/problems to make it a game

Will do TDD

#### PART 1: command interpreter

```
SpriteData
{
  double heading; // value in radians
  Point
  {
    double x;
    double y;
  } position;
  bool penDown;
  bool penColor;
  double penSize;
}
CanvasData
{
  painting handled by qt...
  Size
  {
    double height;
    double width;
  } size;
}
```

for each command: define arguments. Test that it takes valid arguments.
Mock the drawing instruction functions. Should have sane heading / poisition
Allow parsing of multiple commands in a line

Create textbox area in ui. Enter prints the line and moves to next line.
Up key cycles through previous commands.

Commands:

```
{
  forward | fd
  backward | bk
  right | rt
  left | lt
  position | pos
}
```

#### PART 2: Canvas

Don't see a way to unit test ui. But we can code in a sensible way:

1. Create canvas. Connect the sprite position to brush position.
2. Connect commands to drawing functions.

Window resizing:
if turtle is outside the bounds of a window getting smaller, move it so it stays within the bounds (without drawing)

#### Window

model for window stuff. Basically all data inside the UI that's not the sprite & is interesting...
