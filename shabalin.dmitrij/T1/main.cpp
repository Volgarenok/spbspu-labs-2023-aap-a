#include <fstream>
#include <iostream>
#include "square.hpp"
#include "commands.hpp"
#include "compositeshape.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include "checker.hpp"

void pushFigure(const std::string& line, shabalin::CompositeShape& compositeShape);
void executeCommand(const std::string& string, shabalin::CompositeShape& compositeShape);

int main()
{
  std::istream* inputStream;
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
    shabalin::Checker checker(line);
    checker >> entity;
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
    catch (const std::exception& e)
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

void pushFigure(const std::string& line, shabalin::CompositeShape& compositeShape)
{
  double x = 0;
  double y = 0;
  double x2 = 0;
  double y2 = 0;
  double x3 = 0;
  double y3 = 0;
  double side = 0;
  shabalin::Checker checker(line);
  std::string figure = "";
  checker >> figure;
  try
  {
    if (figure == shabalin::Figures::triangle)
    {
      checker >> x >> y >> x2 >> y2 >> x3 >> y3;
      if (checker)
      {
        compositeShape.push_back(new shabalin::Triangle{{x, y}, {x2, y2}, {x3, y3}});
      }
    }
    else if (figure == shabalin::Figures::square)
    {
      checker >> x >> y >> side;
      if (checker)
      {
        compositeShape.push_back(new shabalin::Square{{x, y}, side});
      }
    }
    else if (figure == shabalin::Figures::rectangle)
    {
      checker >> x >> y >> x2 >> y2;
      if (checker)
      {
        compositeShape.push_back(new shabalin::Rectangle{{x, y}, {x2, y2}});
      }
    }
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
  }
}

void executeCommand(const std::string& string, shabalin::CompositeShape& compositeShape)
{
  shabalin::Checker checker(string);
  std::string commandName = "";
  tokenizer >> commandName;
  if (commandName == shabalin::Commands::scale)
  {
    double x = 0;
    double y = 0;
    double scale = 0;
    checker >> x >> y >> scale;
    if (checker && scale > 0.0)
    {
      if (compositeShape.empty())
      {
        throw std::runtime_error("Nothing to scale");
      }
      std::cout << compositeShape << '\n';
      compositeShape.scale(shabalin::point_t{x, y}, scale);
      std::cout << compositeShape << '\n';
    }
    else
    {
      throw std::invalid_argument("Scale command has negative ratio");
    }
  }
}
