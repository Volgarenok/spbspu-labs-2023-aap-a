#include "input_shape.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include "triangle.hpp"
#include "composite_shape.hpp"
#include "create_shape.hpp"

void erohin::inputShape(CompositeShape& result, std::istream& input, point_t& pos, double& ratio)
{
  bool isFigureCreationFullSuccesful = true;
  bool isScaleCommandEntered = false;
  std::string name;
  double current_par = 0.0;
  size_t par_size = 0;
  double par[10]{ 0.0 };
  while (!input.eof() && !isScaleCommandEntered)
  {
    input.clear();
    input >> name;
    while ((input >> current_par) && (par_size != 10))
    {
      par[par_size++] = current_par;
    }
    if (name == "SCALE")
    {
      inputScaleParameteres(par, par_size, pos, ratio);
      isScaleCommandEntered = true;
    }
    else
    {
      Shape* shape = nullptr;
      try
      {
        shape = createShape(name, par, par_size);
        result.push(shape);
      }
      catch (const std::invalid_argument&)
      {
        isFigureCreationFullSuccesful = false;
      }
      catch (const std::bad_alloc&)
      {
        delete shape;
        throw;
      }
      catch (const std::runtime_error&)
      {}
    }
    par_size = 0;
  }
  if (!isScaleCommandEntered)
  {
    throw std::logic_error("Scale command do not find");
  }
  else if (result.empty())
  {
    throw std::runtime_error("Nothing to scale");
  }
  else if (!isFigureCreationFullSuccesful)
  {
    throw std::invalid_argument("Wrong figure creation");
  }
}
