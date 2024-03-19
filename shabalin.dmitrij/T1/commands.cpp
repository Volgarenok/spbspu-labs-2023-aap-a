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

void shabalin::pushFigure(const std::string& line, shabalin::CompositeShape& compositeShape)
{
  double x = 0;
  double y = 0;
  double x2 = 0;
  double y2 = 0;
  double x3 = 0;
  double y3 = 0;
  double side = 0;
  shabalin::Analize analize(line);
  std::string figure = "";
  analize >> figure;
  //bool isExecute = false;
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
    else if (figure == shabalin::Figures::parallelogram)
    {
        analize >> x >> y >> x2 >> y2 >> x3 >> y3;
        if (analize)
        {
            compositeShape.push_back(new shabalin::Parallelogram{{x, y}, {x2, y2}, {x3, y3}});
        }
    }
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << e.what() << '\n';
  }
}

void shabalin::executeCommand(const std::string &string, shabalin::CompositeShape &compositeShape)
{
  shabalin::Analize analize(string);
  std::string name = "";
  analize >> name;
  if (name == shabalin::Commands::scale)
  {
    double x = 0;
    double y = 0;
    double scale = 0;
    analize >> x >> y >> scale;
    if (analize && scale > 0.0)
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
      throw std::invalid_argument("Scale command has negative coeff or insufficient parameters");
    }
  }
}
