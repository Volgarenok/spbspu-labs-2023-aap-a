#include "commands.hpp"
#include "analize.hpp"
#include <iostream>
#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "triangle.hpp"

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

double shabalin::isTriangle(shabalin::point_t &p1, shabalin::point_t &p2, shabalin::point_t &p3)
{
  return p1.x * (p2.y - p3.y) - p2.x * (p1.y - p3.y) + p3.x * (p1.y - p2.y);
}
