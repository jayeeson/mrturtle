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

const std::string DECIMAL_REGEX = "((\\d+\\.?\\d*)|(\\.\\d+))";

static const std::map<std::string, std::string>
    commandRegexes{
        {"forward", "(forward|fd)\\s+" + DECIMAL_REGEX},
        {"backward", "(backward|bk)\\s+" + DECIMAL_REGEX},
        {"right", "(right|rt)\\s+" + DECIMAL_REGEX},
        {"left", "(left|lt)\\s+" + DECIMAL_REGEX},
        {"position", "(position|pos)(\\s+)?"}};

CommandInterpreter::CommandInterpreter(Turtle &turtle, CanvasData &canvas)
    : _turtle(turtle), _canvas(canvas)
{
}

void CommandInterpreter::Parse(QString command)
{
  std::smatch match;
  auto commandStr = command.toStdString();
  if (std::regex_match(commandStr, match, std::regex(commandRegexes.at("forward"))))
  {
    double value = atof(match[2].str().c_str());
    _cmd.reset(new ForwardCommand(_turtle, value));
  }
  else if (std::regex_match(commandStr, match, std::regex(commandRegexes.at("backward"))))
  {
    double value = atof(match[2].str().c_str());
    _cmd.reset(new BackwardCommand(_turtle, value));
  }
  else if (std::regex_match(commandStr, match, std::regex(commandRegexes.at("right"))))
  {
    double value = atof(match[2].str().c_str());
    _cmd.reset(new RightCommand(_turtle, value));
  }
  else if (std::regex_match(commandStr, match, std::regex(commandRegexes.at("left"))))
  {
    double value = atof(match[2].str().c_str());
    _cmd.reset(new LeftCommand(_turtle, value));
  }
  else if (std::regex_match(commandStr, match, std::regex(commandRegexes.at("position"))))
  {
    double value = atof(match[2].str().c_str());
    _cmd.reset(new PositionCommand(_turtle, _canvas));
  }
}

bool CommandInterpreter::Execute()
{
  if (_cmd != nullptr)
  {
    _cmd->Execute();
    _cmd.reset(nullptr);
    return true;
  }
  return false;
}
