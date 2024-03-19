#include "commands.hpp"
#include "analize.hpp"
#include <iostream>
#include "parallelogram.hpp"
#include "rectangle.hpp"
//#include "square.hpp"
//#include "triangle.hpp"

bool shabalin::isCommand(const std::string &command)
{
  for (const std::string &name : Commands::allCommands)
  {
    if (name == command)
    {
      return true;
    }
  }
  return false;
}
bool shabalin::isFigure(const std::string &figure)
{
  for (const std::string &name : Figures::allFigures)
  {
    if (name == figure)
    {
      return true;
    }
  }
  return false;
}
