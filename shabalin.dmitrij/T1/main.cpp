#include <fstream>
#include <iostream>

#include "square.hpp"
#include "commands.hpp"
#include "compositeShapes.hpp"
#include "triangle.hpp"
#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "analize.hpp"

int main()
{
  std::istream *input = &std::cin;
  shabalin::CompositeShape shapes;
  bool scaleExecuted = false;
  while (*input)
  {
    std::string line, entity;
    std::getline(*input, line);
    if (line.empty())
    {
      continue;
    }
    shabalin::Analize analize(line);
    analize >> entity;
    try
    {
      if (shabalin::isFigure(entity))
      {
        shabalin::pushFigure(line, shapes);
      }
      else if (shabalin::isCommand(entity))
      {
        shabalin::executeCommand(line, shapes);
        if (entity == shabalin::Commands::scale)
        {
          scaleExecuted = true;
        }
      }
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << '\n';
      return 1;
    }
  }
  if (!scaleExecuted)
  {
    std::cerr << "Scale command wasn't executed" << '\n';
    return 1;
  }
  return 0;
}
