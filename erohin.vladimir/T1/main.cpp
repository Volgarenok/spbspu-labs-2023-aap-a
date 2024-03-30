#include <iostream>
#include <iomanip>
#include "input_shape.hpp"
#include "output_shape.hpp"
#include "geom_func.hpp"
#include "composite_shape.hpp"

int main()
{
  using namespace erohin;
  point_t scale_pos = { 0.0, 0.0 };
  double scale_ratio = 0.0;
  bool isWrongFigureCreation = false;
  CompositeShape composite_shape;
  try
  {
    inputShape(composite_shape, std::cin, scale_pos, scale_ratio);
  }
  catch (const std::invalid_argument&)
  {
    isWrongFigureCreation = true;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << std::fixed;
  std::cout.precision(1);
  outputShape(std::cout, composite_shape);
  isoScale(composite_shape, scale_pos, scale_ratio);
  outputShape(std::cout << "\n", composite_shape);
  std::cout << "\n";
  if (isWrongFigureCreation)
  {
    std::cerr << "Wrong parameters to create a figure\n";
  }
  return 0;
}
