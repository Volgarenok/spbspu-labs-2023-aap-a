#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
namespace shabalin
{
  void pushFigure(const std::string &line, shabalin::CompositeShape &compositeShape);
  void executeCommand(const std::string &string, shabalin::CompositeShape &compositeShape);
  static const std::string triangle = "TRIANGLE";
  static const std::string square = "SQUARE";
  static const std::string rectangle = "RECTANGLE";
  static const std::string allFigures[] = {triangle, square, rectangle};
  static const std::string scale = "SCALE";
  static const std::string allCommands[] = {scale};
  bool isCommand(const std::string &command);
  bool isFigure(const std::string &figure);
}

#endif
