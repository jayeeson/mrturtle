#include "CommandInterpreter.h"
#include "ForwardCommand.h"
#include "BackwardCommand.h"
#include "RightCommand.h"
#include "LeftCommand.h"
#include "PositionCommand.h"
#include "SizeCommand.h"
#include "PenDownCommand.h"
#include "PenUpCommand.h"
#include "PenSizeCommand.h"
#include "ColorCommand.h"
#include "ClearCommand.h"
#include "HomeCommand.h"
#include "UnknownCommand.h"
#include "Turtle.h"
#include <QString>
#include <map>
#include <regex>
#include <iostream>

const std::string DECIMAL_REGEX = "((\\d+\\.?\\d*)|(\\.\\d+))";

static const std::map<std::string, std::string> commandRegexes{
    {"forward", "(forward|fd)\\s+" + DECIMAL_REGEX},
    {"backward", "(backward|bk)\\s+" + DECIMAL_REGEX},
    {"right", "(right|rt)\\s+" + DECIMAL_REGEX},
    {"left", "(left|lt)\\s+" + DECIMAL_REGEX},
    {"position", "(position|pos)\\s*"},
    {"size", "(size)\\s*"},
    {"penDown", "(pendown)\\s*"},
    {"penUp", "(penup)\\s*"},
    {"penSize", "(pensize)\\s+" + DECIMAL_REGEX},
    {"color", "(color)\\s+(\\w+)"},
    {"clear", "(clear)\\s*"},
    {"home", "(home)\\s*"}};

CommandInterpreter::CommandInterpreter(Turtle &turtle) : _turtle(turtle) {}

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
        _cmd.reset(new PositionCommand(_turtle));
    }
    else if (std::regex_match(commandStr, match, std::regex(commandRegexes.at("size"))))
    {
        _cmd.reset(new SizeCommand(_turtle.GetCanvas()));
    }
    else if (std::regex_match(commandStr, match, std::regex(commandRegexes.at("penDown"))))
    {
        _cmd.reset(new PenDownCommand(_turtle));
    }
    else if (std::regex_match(commandStr, match, std::regex(commandRegexes.at("penUp"))))
    {
        _cmd.reset(new PenUpCommand(_turtle));
    }
    else if (std::regex_match(commandStr, match, std::regex(commandRegexes.at("penSize"))))
    {
        double value = atof(match[2].str().c_str());
        _cmd.reset(new PenSizeCommand(_turtle, value));
    }
    else if (std::regex_match(commandStr, match, std::regex(commandRegexes.at("color"))))
    {
        QString value = match[2].str().c_str();
        _cmd.reset(new ColorCommand(_turtle, value));
    }
    else if (std::regex_match(commandStr, match, std::regex(commandRegexes.at("clear"))))
    {
        _cmd.reset(new ClearCommand(_turtle.GetCanvas()));
    }
    else if (std::regex_match(commandStr, match, std::regex(commandRegexes.at("home"))))
    {
        _cmd.reset(new HomeCommand(_turtle));
    }
    else
    {
        _cmd.reset(new UnknownCommand(_turtle.GetCanvas(), QString(commandStr.c_str())));
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
