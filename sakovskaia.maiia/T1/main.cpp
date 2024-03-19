#include <iostream>
#include <cstring>
#include <string_reader.hpp>
#include "shape.hpp"
#include "input.hpp"
#include "output.hpp"
#include "rectangle.hpp"
#include "parallelogram.hpp"
#include "sqare.hpp"
#include "ellipse.hpp"

int main()
{
  using namespace sakovskaia;
  Shape * shapes[1000]{};
  size_t cnt = 0;
  point_t scalePoint = {0, 0};
  size_t scaleRatio = 0;
  double k = 0;
  char * string = nullptr;
  string = readString(std::cin);
  constexpr size_t shapes_cnt = 5;
  const char * shapes_my[shapes_cnt] = {"RECTANGLE", "PARALLELOGRAM", "SQUARE", "ELLIPSE", "SCALE"};
  for (size_t i = 0; i < shapes_cnt; i++)
  {
    size_t shape_name = std::strlen(shapes_my[i]);
    if (std::strncmp(shapes_my[i], string, shape_name) == 0)
    {
      if (i == 0)
      {
        Shape * shape = inputRectangle(string);
        if (shape != nullptr)
        {
          shapes[cnt++] = shape;
        }
      }
      if (i == 1)
      {
        Shape * shape = inputParallelogram(string);
        if (shape != nullptr)
        {
          shapes[cnt++] = shape;
        }
      }
      if (i == 2)
      {
        Shape * shape = inputSquare(string);
        if (shape != nullptr)
        {
          shapes[cnt++] = shape;
        }
      }
      if (i == 3)
      {
        Shape * shape = inputEllipse(string);
        if (shape != nullptr)
        {
          shapes[cnt++] = shape;
        }
      }
      outputShapes(std::cout, shapes, cnt);
      std::cout << '\n';
      if (i == 4)
      {
        for (size_t i = 0; i < cnt; ++i)
        {
          scaleShapes(shapes[i], scalePoint, scaleRatio);
        }
        outputShapes(std::cout, shapes, cnt);
        std::cout << '\n';
      }
    }
  }
  delete [] string;
  for (size_t i = 0; i < cnt; i++)
  {
    delete shapes[i];
  }
}
