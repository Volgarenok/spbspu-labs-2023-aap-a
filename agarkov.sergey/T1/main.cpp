#include <iostream>
#include <string>

#include "shape.hpp"
#include "square.hpp"
#include "rectangle.hpp"
#include "parallelogram.hpp"
#include "diamond.hpp"
#include "isoScale.hpp"
#include "printShapes.hpp"
#include "workWithArray.hpp"
#include "inputParam.hpp"

int main()
{
  std::string shape_name = "";
  double scale_coefficient = 0.0;
  agarkov::point_t scale_point{0.0, 0.0};
  bool is_scaling = false;
  bool has_broken_shape = false;
  size_t capacity = 10;
  size_t buf = 10;
  size_t size = 0;
  agarkov::Shape** shapes = new agarkov::Shape*[capacity];
  do
  {
    agarkov::Shape* shape = nullptr;
    try
    {
      if (size + 1 == capacity)
      {
        agarkov::Shape** expanded_shapes = agarkov::expandArray(shapes, capacity, buf);
        capacity += buf;
        delete[] shapes;
        shapes = expanded_shapes;
      }
      std::cin >> shape_name;
      if (shape_name == "RECTANGLE")
      {
        double parameters[4]{};
        agarkov::inputParam(std::cin, parameters, 4);
        shape = new agarkov::Rectangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]});
        shapes[size] = shape;
        size++;
      }
      if (shape_name == "SQUARE")
      {
        double parameters[3]{};
        agarkov::inputParam(std::cin, parameters, 3);
        shape = new agarkov::Square({parameters[0], parameters[1]}, parameters[2]);
        shapes[size] = shape;
        size++;
      }
      if (shape_name == "PARALLELOGRAM")
      {
        double parameters[6]{};
        agarkov::inputParam(std::cin, parameters, 6);
        shape = new agarkov::Parallelogram({parameters[0], parameters[1]}, {parameters[2], parameters[3]}, {parameters[4], parameters[5]});
        shapes[size] = shape;
        size++;
      }
      if (shape_name == "DIAMOND")
      {
        double parameters[6]{};
        agarkov::inputParam(std::cin, parameters, 6);
        shape = new agarkov::Diamond({parameters[0], parameters[1]}, {parameters[2], parameters[3]}, {parameters[4], parameters[5]});
        shapes[size] = shape;
        size++;
      }
      if (shape_name == "SCALE")
      {
        is_scaling = true;
        std::cin >> scale_point.x >> scale_point.y >> scale_coefficient;
        break;
      }
    }
    catch (const std::invalid_argument& e)
    {
      has_broken_shape = true;
      std::cerr << e.what() << "\n";
      continue;
    }
    catch (...)
    {
      std::cerr << "Error\n";
      agarkov::deleteArray(shapes, size);
      return 1;
    }
  }
  while (std::cin);
  if (is_scaling && size > 0)
  {
    agarkov::printShapes(std::cout, shapes, size);
    std::cout << "\n";
    try
    {
      for (size_t i = 0; i < size; i++)
      {
        agarkov::isoScale(shapes[i], scale_point, scale_coefficient);
      }
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << e.what() << "\n";
      agarkov::deleteArray(shapes, size);
      return 1;
    }
    agarkov::printShapes(std::cout, shapes, size);
    std::cout << "\n";
    if (has_broken_shape)
    {
      std::cerr << "Exist broken shape\n";
    }
    agarkov::deleteArray(shapes, size);
  }
  else
  {
    agarkov::deleteArray(shapes, size);
    std::cerr << "Error\n";
    return 1;
  }
}
