#ifndef COMMANDS_HPP
#define COMMANDS_HPP
#include "compositeShapes.hpp"
#include <string>
namespace shabalin
{
namespace Figures
{
static const std::string triangle = "TRIANGLE";
static const std::string square = "SQUARE";
static const std::string rectangle = "RECTANGLE";
static const std::string parallelogram = "PARALLELOGRAM";
static const std::string allFigures[] = {triangle, square, rectangle, parallelogram};
}
namespace Commands
{
static const std::string scale = "SCALE";
static const std::string allCommands[] = {scale};
}
bool isCommand(const std::string& command);
bool isFigure(const std::string& figure);
void pushFigure(const std::string& line, CompositeShape& compositeShape);
void executeCommand(const std::string& string, CompositeShape& compositeShape);
}

#endif
