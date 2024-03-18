#include "commands.hpp"

namespace shabalin
{
  bool isCommand(const std::string &command)
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
  bool isFigure(const std::string &figure)
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
  catch (const std::invalid_argument &e)
  {
    std::cerr << e.what() << '\n';
  }
}

void executeCommand(const std::string &string, shabalin::CompositeShape &compositeShape)
{
  shabalin::Analize analize(string);
  std::string commandName = "";
  tokenizer >> commandName;
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
      throw std::invalid_argument("Scale command has negative ratio");
    }
  }
}
