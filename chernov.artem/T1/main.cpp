#include "rectangle.hpp"
#include "circle.hpp"
#include "ellipse.hpp"
#include "ring.hpp"
#include "shape.hpp"
#include "base-types.hpp"
#include "addShape.hpp"
#include <iostream>
#include <string>
#include <cstddef>

int main()
{
  using namespace chernov;
  std::string input = "";
  size_t size = 0;
  Shape** shapes = new Shape * [size];
  bool badShapeDetected = false;
  try
  {
    while (std::cin >> input)
    {
      if (!std::cin)
      {
        throw std::invalid_argument("Invalid error");
      }
      if (input == "RECTANGLE")
      {
        double left_down_x = 0, left_down_y = 0, right_high_x = 0, right_high_y = 0;
        std::cin >> left_down_x >> left_down_y >> right_high_x >> right_high_y;
        if (!std::cin)
        {
          std::cerr << "Invalid input\n";
        }
        Rectangle* rect = nullptr;
        try
        {
          rect = new Rectangle(left_down_x, left_down_y, right_high_x, right_high_y);
        }
        catch (const std::bad_alloc& e)
        {
          badShapeDetected = true;
          std::cerr << "Error: Invalid rectangle parameters: " << e.what() << "\n";
          delete rect;
        }
        try
        {
          addFigure(shapes, size, rect);
        }
        catch (const std::bad_alloc& e)
        {
          std::cerr << "Error: Invalid rectangle add: " << e.what() << "\n";
          delete rect;
        }
      }
      else if (input == "RING")
      {
        double center_x, center_y, outer_radius, inner_radius;
        std::cin >> center_x >> center_y >> outer_radius >> inner_radius;
        if (!std::cin)
        {
          std::cerr << "Invalid input\n";
        }
        Ring* ring = nullptr;
        try
        {
          ring = new Ring({ center_x, center_y }, outer_radius, inner_radius);
        }
        catch (const std::bad_alloc& e)
        {
          badShapeDetected = true;
          std::cerr << "Error: Invalid ring parameters: " << e.what() << "\n";
          delete ring;
        }
        try
        {
          addFigure(shapes, size, ring);
        }
        catch (const std::bad_alloc& e)
        {
          std::cerr << "Error: Invalid ring add: " << e.what() << "\n";
          delete ring;
        }
      }
      else if (input == "CIRCLE")
      {
        double center_x = 0, center_y = 0, radius = 0;
        std::cin >> center_x >> center_y >> radius;
        if (!std::cin)
        {
          std::cerr << "Invalid input\n";
        }
        Circle* circle = nullptr;
        try
        {
          circle = new Circle({ center_x, center_y }, radius);
        }
        catch (const std::bad_alloc& e)
        {
          badShapeDetected = true;
          std::cerr << "Error: Invalid circle parameters: " << e.what() << "\n";
          delete circle;
        }
        try
        {
          addFigure(shapes, size, circle);
        }
        catch (const std::bad_alloc& e)
        {
          std::cerr << "Error: Invalid circle add: " << e.what() << "\n";
          delete circle;
        }
      }
      else if (input == "ELLIPSE")
      {
        double center_x = 0, center_y = 0, vertical_radius = 0, horizontal_radius = 0;
        std::cin >> center_x >> center_y >> vertical_radius >> horizontal_radius;
        if (!std::cin)
        {
          std::cerr << "Invalid input\n";
        }
        Ellipse* ellipse = nullptr;
        try
        {
          ellipse = new Ellipse({ center_x, center_y }, vertical_radius, horizontal_radius);
        }
        catch (const std::bad_alloc& e)
        {
          badShapeDetected = true;
          std::cerr << "Error: Invalid ellipse parameters: " << e.what() << "\n";
          delete ellipse;
        }
        try
        {
          addFigure(shapes, size, ellipse);
        }
        catch (const std::bad_alloc& e)
        {
          std::cerr << "Error: Invalid ellipse add: " << e.what() << "\n";
          delete ellipse;
        }
      }
      else if (input == "SCALE")
      {
        double center_x = 0, center_y = 0, multiplier = 0;
        std::cin >> center_x >> center_y >> multiplier;
        if (!std::cin || multiplier <= 0)
        {
          std::cerr << "Error input\n";
        }
      }
      else if (input == "MOVE")
      {
        double pos_x = 0, pos_y = 0;
        if (!std::cin)
        {
          std::cerr << "Error input\n";
          return 1;
        }
        for (size_t i = 0; i < size; ++i)
        {
          shapes[i]->move(pos_x, pos_y);
        }
      }
      else if (input == "END")
      {
        break;
      }
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  if (badShapeDetected)
  {
    std::cerr << "There is bad shape\n";
    return 1;
  }
  return 0;
}
