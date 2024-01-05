#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "base-types.h"
#include "Geom_functions.h"
#include "Shapes_i_o.h"

int main()
{
  using namespace zaitsev;

  std::string shape_type;
  std::string shape_param;
  char* shape_param_copy = nullptr;
  size_t size = 0;
  size_t capacity = 0;
  Shape** shapes = nullptr;
  bool wrong_args = false;

  try
  {
    while (1)
    {
      std::cin >> shape_type;
      std::getline(std::cin, shape_param);
      if (!std::cin)
      {
        std::cerr << "No scale command entered\n";
        for (size_t i = 0; i < size; ++i)
        {
          delete shapes[i];
        }
        delete[] shapes;
        return 1;
      }
      if (shape_type == "RECTANGLE")
      {
        shape_param_copy = new char[shape_param.size() + 1];
        memcpy(shape_param_copy, shape_param.c_str(), shape_param.size() + 1);
        Shape* res = readRectangle(shape_param_copy);
        if (res)
        {
          addShape(std::addressof(shapes), size, capacity, res);
        }
        else
        {
          wrong_args = true;
        }
      }
      else if (shape_type == "COMPLEXQUAD")
      {
        shape_param_copy = new char[shape_param.size() + 1];
        memcpy(shape_param_copy, shape_param.c_str(), shape_param.size() + 1);
        Shape* res = readComplexquad(shape_param_copy);
        if (res)
        {
          addShape(std::addressof(shapes), size, capacity, res);
        }
        else
        {
          wrong_args = true;
        }
      }
      else if (shape_type == "PARALLELOGRAM")
      {
        shape_param_copy = new char[shape_param.size() + 1];
        memcpy(shape_param_copy, shape_param.c_str(), shape_param.size() + 1);
        Shape* res = readParallelogram(shape_param_copy);
        if (res)
        {
          addShape(std::addressof(shapes), size, capacity, res);
        }
        else
        {
          wrong_args = true;
        }
      }
      else if (shape_type == "SCALE")
      {
        shape_param_copy = new char[shape_param.size() + 1];
        memcpy(shape_param_copy, shape_param.c_str(), shape_param.size() + 1);
        if (size == 0)
        {
          std::cerr << "Error: No shapes to scale\n";
          delete[] shape_param_copy;
          delete[] shapes;
          return 1;
        }

        double factor = 0;
        point_t center = { 0,0 };
        try
        {
          readScale(shape_param_copy, center, factor);
          shapesOutput(std::cout, shapes, size);
          for (size_t i = 0; i < size; ++i)
          {
            scale(shapes[i], factor, center);
          }
          shapesOutput(std::cout, shapes, size);
          if (wrong_args)
          {
            std::cerr << "Warning: Some shapes were set incorrectly\n";
          }
        }
        catch (std::invalid_argument& e)
        {
          std::cerr << "Error: " << e.what() << "\n";
          delete[] shape_param_copy;
          for (size_t i = 0; i < size; ++i)
          {
            delete shapes[i];
          }
          delete[] shapes;
          return 1;
        }

        delete[] shape_param_copy;
        for (size_t i = 0; i < size; ++i)
        {
          delete shapes[i];
        }
        delete[] shapes;
        return 0;
      }
      delete[] shape_param_copy;
      shape_param_copy = nullptr;
    }
  }
  catch (std::bad_alloc&)
  {
    std::cerr << "Error: Failed to allocate memory\n";
    delete[] shape_param_copy;
    for (size_t i = 0; i < size; ++i)
    {
      delete shapes[i];
    }
    delete[] shapes;
  }

  return 1;
}
