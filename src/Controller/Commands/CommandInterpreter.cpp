#include "CommandInterpreter.h"
#include "ForwardCommand.h"
#include "BackwardCommand.h"
#include "RightCommand.h"
#include "LeftCommand.h"
#include "PositionCommand.h"
#include "CanvasData.h"
#include <map>
#include <regex>
#include <iostream>

static const std::map<std::string, const char *> commandRegexes{
    {"forward", "(forward|fd)\\s+(\\d+?\\.?\\d+)"},
    {"backward", "(backward|bk)\\s+(\\d+?\\.?\\d+)"},
    {"right", "(right|rt)\\s+(\\d+?\\.?\\d+)"},
    {"left", "(left|lt)\\s+(\\d+?\\.?\\d+)"},
    {"position", "(position|pos)(\\s+)?"}};

CommandInterpreter::CommandInterpreter(Turtle &turtle, CanvasData &canvas)
    : _turtle(turtle), _canvas(canvas)
{
}

void CommandInterpreter::Parse(QString command)
{
  std::cmatch match;
  if (std::regex_match(command.toStdString().c_str(), match, std::regex(commandRegexes.at("forward"))))
  {
    double value = atof(match[2].str().c_str());
    _cmd.reset(new ForwardCommand(_turtle, value));
  }
  else if (std::regex_match(command.toStdString().c_str(), match, std::regex(commandRegexes.at("backward"))))
  {
    double value = atof(match[2].str().c_str());
    _cmd.reset(new BackwardCommand(_turtle, value));
  }
  else if (std::regex_match(command.toStdString().c_str(), match, std::regex(commandRegexes.at("right"))))
  {
    double value = atof(match[2].str().c_str());
    _cmd.reset(new RightCommand(_turtle, value));
  }
  else if (std::regex_match(command.toStdString().c_str(), match, std::regex(commandRegexes.at("left"))))
  {
    double value = atof(match[2].str().c_str());
    _cmd.reset(new LeftCommand(_turtle, value));
  }
  else if (std::regex_match(command.toStdString().c_str(), match, std::regex(commandRegexes.at("position"))))
  {
    double value = atof(match[2].str().c_str());
    _cmd.reset(new PositionCommand(_turtle, _canvas));
  }
}

void CommandInterpreter::Execute()
{
  if (_cmd != nullptr)
  {
    _cmd->Execute();
    _cmd.reset(nullptr);
  }
}
