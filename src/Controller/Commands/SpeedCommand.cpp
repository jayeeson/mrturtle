#include "SpeedCommand.h"
#include "Turtle.h"
#include <QObject>
#include <QMetaObject>
#include <QString>

SpeedCommand::SpeedCommand(Turtle &turtle, double speed)
    : _turtle(turtle), _speed((speed < 1E-7 && speed > -1E-7) ? 1000 : speed), _gettingSpeed(false)
{
}

SpeedCommand::SpeedCommand(Turtle &turtle) : _turtle(turtle), _speed(0.), _gettingSpeed(true) {}

bool SpeedCommand::Execute()
{
    if (_gettingSpeed)
    {
        QString str = QString("Current speed: %1").arg(_turtle.GetSpeed());
        _turtle.GetCanvas().DoAddLineToCommandHistoryPanel(str, "#084808");  // dark darkgreen
        return true;
    }
    else if (Validate())
    {
        _turtle.SetSpeed(_speed);
        return true;
    }
    return false;
}

bool SpeedCommand::Validate()
{
    if (_speed < 0)
    {
        QString str = "Can't set a negative speed";
        _turtle.GetCanvas().DoAddLineToCommandHistoryPanel(str, "darkred");
        return false;
    }

    if (_speed >= _turtle.GetDefaultSpeed() * 100)
    {
        QString str = "Too fast!";
        _turtle.GetCanvas().DoAddLineToCommandHistoryPanel(str, "darkred");
        return false;
    }
    return true;
}
