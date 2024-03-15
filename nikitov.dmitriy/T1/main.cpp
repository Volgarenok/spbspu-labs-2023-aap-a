#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include "shape.hpp"
#include "input_array.hpp"
#include "scale_figures.hpp"
#include "composite_shape.hpp"

int main()
{
  using namespace nikitov;
  std::string line;
  bool isErrorInProgram = false;
  CompositeShape composition;

  try
  {
    inputArray(composition, line, std::cin);
  }
  catch (const std::invalid_argument&)
  {
    isErrorInProgram = true;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

  try
  {
    if (!composition.empty())
    {
      point_t isoScaleCenter = {};
      double ratio = 0.0;
      recognizeScaleParameters(line, isoScaleCenter, ratio);

      std::cout << std::fixed << std::setprecision(1);
      if (ratio > 0)
      {
        std::cout << composition.getArea();
        for (size_t i = 0; i != composition.size(); ++i)
        {
          std::cout << ' ';
          outputFrame(std::addressof(composition[i]), std::cout);
        }
        std::cout << '\n';

        scaleComposition(composition, isoScaleCenter, ratio);

        std::cout << composition.getArea();
        for (size_t i = 0; i != composition.size(); ++i)
        {
          std::cout << ' ';
          outputFrame(std::addressof(composition[i]), std::cout);
        }
        std::cout << '\n';
      }
      else
      {
        throw std::invalid_argument("Error: Wrong argument for scaling");
      }
    }
    else
    {
      std::cerr << "Error: Not enough figures for scaling\n";
      return 2;
    }
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
    return 3;
  }

  if (isErrorInProgram)
  {
    std::cerr << "Error: Wrong coordinates for figure\n";
  }

  return 0;
}
