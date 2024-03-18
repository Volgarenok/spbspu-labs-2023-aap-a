#include <iostream>
#include <iomanip>
#include <cstring>
#include <getString.hpp>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "parallelogram.hpp"
#include "inputShapes.hpp"
#include "stringProc.hpp"

using namespace strelyaev;

int main()
{
  std::cin >> std::noskipws;
  constexpr size_t maxshapes = 1000;
  char* string = nullptr;
  size_t current_index = 0;
  Shape* list[maxshapes] = {nullptr};
  bool errors = false;
  bool scale_was_met = false;

  while (!scale_was_met)
  {
    if (!std::cin.good())
    {
      std::cerr << "Something went wrong with the input\n";
      for (size_t i = 0; i < current_index; i++)
      {
        delete list[i];
      }
      return 1;
    }

    try
    {
      string = getString(std::cin);
    }
    catch (const std::logic_error& e)
    {
      std::cerr << e.what() << "\n";
      delete [] string;
      for (size_t i = 0; i < current_index; i++)
      {
        delete list[i];
      }
      return 2;
    }
    constexpr size_t shapes_count = 4;
    const char* shape_names[shapes_count] = { "RECTANGLE", "TRIANGLE", "PARALLELOGRAM", "SCALE"};
    try
    {
      for (size_t i = 0; i < shapes_count; i++)
      {
        size_t name_size = std::strlen(shape_names[i]);
        if (std::strncmp(shape_names[i], string, name_size) == 0)
        {
          if (i == 0)
          {
            Shape* shape = inputRectangle(string);
            if (shape != nullptr)
            {
              list[current_index++] = shape;
            }
          }
          if (i == 1)
          {
            Shape* shape = inputTriangle(string);
            if (shape != nullptr)
            {
              list[current_index++] = shape;
            }
          }
          if (i == 2)
          {
            Shape* shape = inputParallelogram(string);
            if (shape != nullptr)
            {
              list[current_index++] = shape;
            }
          }
          if (i == 3)
          {
            scale_was_met = true;
            scaleCommand(string, list, current_index, std::cout);
          }
        }
      }
    }
    catch (const std::invalid_argument& e)
    {
      errors = true;
    }
    catch (const std::logic_error& e)
    {
      std::cerr << e.what() << "\n";
      delete [] string;
      for (size_t i = 0; i < current_index; i++)
      {
        delete list[i];
      }
      return 1;
    }
    delete [] string;
  }
  if (errors)
  {
    std::cerr << "Some names are incorrect!\n";
  }
  for (size_t i = 0; i < current_index; i++)
  {
    delete list[i];
  }
  std::cin >> std::skipws;
}
