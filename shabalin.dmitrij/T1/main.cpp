#include <fstream>
#include <iostream>
//#include "square.hpp"
#include "commands.hpp"
#include "compositeShapes.hpp"
//#include "triangle.hpp"
#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "analize.hpp"

void pushFigure(const std::string& line, shabalin::CompositeShape& compositeShape);
void executeCommand(const std::string& string, shabalin::CompositeShape& compositeShape);

int main()
{
  std::istream *inputStream = &std::cin;
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
  shabalin::Analize analize(line);
  std::string figure = "";
  analize >> figure;
  bool isError = false;
  try
  {
    /*
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
    */
    if (figure == shabalin::Figures::rectangle)
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
        if(analize)
        {
            compositeShape.push_back(new shabalin::Parallelogram{{x, y}, {x2, y2}, {x3, y3}});
        }
    }
  }
  catch (const std::exception &e)
  {
    if (!isError)
    {
      std::cerr << e.what() << '\n';
      isError = true;
    }
  }
}

void executeCommand(const std::string& string, shabalin::CompositeShape& compositeShape)
{
  shabalin::Analize analize(string);
  std::string commandName = "";
  analize >> commandName;
  if (commandName == shabalin::Commands::scale)
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
