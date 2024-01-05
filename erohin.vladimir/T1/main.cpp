#include <iostream>
#include "complexquad.hpp"
#include "input_shape.hpp"
#include "output_shape.hpp"
#include "parse.hpp"
#include "geom_func.hpp"
#include "shape.hpp"
#include "triangle.hpp"

int main()
{
  using namespace erohin;
  Shape** shape = nullptr;
  size_t size = 0;
  point_t scale_pos = {0.0, 0.0};
  double scale_ratio = 0.0;
  bool isError = false;
  try
  {
    shape = inputShape(std::cin, shape, size, scale_pos, scale_ratio);
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Memory allocation fault\n";
    return 2;
  }
  try
  {
    for (size_t i = 0; i < size - 1; ++i)
    {
      if (shape[i])
      {
        if (!isNullFrameRect(shape[i]->getFrameRect()))
        {
          outputShape(std::cout, shape[i]);
          std::cout << "\n";
          isoScale(*shape[i], scale_pos, scale_ratio);
          outputShape(std::cout, shape[i]);
          std::cout << "\n";
        }
        else
        {
          std::cerr << "Wrong parametres to create a figure\n";
          isError = true;
        }
      }
    }
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what();
    for (size_t i = 0; i < size - 1; ++i)
    {
      delete shape[i];
    }
    return 3;
  }
  for (size_t i = 0; i < size; ++i)
  {
    delete shape[i];
  }
  return isError;
}
