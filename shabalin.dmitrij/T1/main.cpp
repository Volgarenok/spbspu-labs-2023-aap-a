#include <fstream>
#include <iostream>
#include "square.hpp"
#include "commands.hpp"
#include "compositeShapes.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include "analize.hpp"

void pushFigure(const std::string &line, shabalin::CompositeShape &compositeShape);
void executeCommand(const std::string &string, shabalin::CompositeShape &compositeShape);

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

void pushFigure(const std::string &line, shabalin::CompositeShape &compositeShape)
{
  double x, y, x2, y2, x3, y3, side = 0;
  shabalin::Analize analize(line);
  std::string figure = "";
  analize >> figure;
  try
  {
    if (figure == shabalin::Figures::triangle)
    {
      analize >> x >> y >> x2 >> y2 >> x3 >> y3;
      if (analize)
      {
        compositeShape.push_back(new shabalin::Triangle{{x, y}, {x2, y2}, {x3, y3}});
      }
    }
    else if (figure == shabalin::Figures::square)
    {
      analize >> x >> y >> side;
      if (analize)
      {
        compositeShape.push_back(new shabalin::Square{{x, y}, side});
      }
    }
    else if (figure == shabalin::Figures::rectangle)
    {
      analize >> x >> y >> x2 >> y2;
      if (analize)
      {
        compositeShape.push_back(new shabalin::Rectangle{{x, y}, {x2, y2}});
      }
    }
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << e.what() << '\n';
  }
}
