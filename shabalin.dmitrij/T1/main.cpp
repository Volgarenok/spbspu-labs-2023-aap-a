#include <fstream>
#include <iostream>
#include "square.hpp"
#include "commands.hpp"
#include "compositeshape.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include "analize.hpp"

int main()
{
  std::istream *inputStream;
  shabalin::CompositeShape shapes;
  bool scaleExecuted = false;
  while (*inputStream)
  {
    std::string line, entity;
    std::getline(*inputStream, line);
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
        pushFigure(line, shapes);
      }
      else if (shabalin::isCommand(entity))
      {
        executeCommand(line, shapes);
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