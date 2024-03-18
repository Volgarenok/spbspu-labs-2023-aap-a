#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

#include "rectangle.hpp"
#include "triangle.hpp"
#include "concave.hpp"
#include "results_printer.hpp"
#include "iso_scale.hpp"
#include "reader.hpp"

int main()
{
  belokurskaya::Shape* shapes[1000];
  int shape_count = 0;
  while (true)
  {
    belokurskaya::point_t * points = nullptr;
    try
    {
      if (std::cin.peek())
      {
        if (std::cin.eof())
        {
          for (int i = 0; i < shape_count; ++i)
          {
            delete shapes[i];
          }
          std::cerr << "EOF reached\n";
          return 1;
        }
      }
      else
      {
        continue;
      }
      std::string command;
      std::cin >> command;

      if (command == "RECTANGLE")
      {
        points = new belokurskaya::point_t[2];
        belokurskaya::readPointsArray(std::cin, points, 2);

        shapes[shape_count] = new belokurskaya::Rectangle(points[0], points[1]);
        shape_count++;
        delete[] points;
      }
      else if (command == "TRIANGLE")
      {
        points = new belokurskaya::point_t[3];
        belokurskaya::readPointsArray(std::cin, points, 3);

        shapes[shape_count] = new belokurskaya::Triangle(points[0], points[1], points[2]);
        shape_count++;
        delete[] points;
      }
      else if (command == "CONCAVE")
      {
        points = new belokurskaya::point_t[4];
        belokurskaya::readPointsArray(std::cin, points, 4);

        shapes[shape_count] = new belokurskaya::Concave(points[0], points[1], points[2], points[3]);
        shape_count++;
        delete[] points;
      }
      else if (command == "SCALE")
      {
        double scale_point_x = 0.0, scale_point_y = 0.0, scale_factor = 0.0;
        if (!(std::cin >> scale_point_x >> scale_point_y >> scale_factor))
        {
          throw std::invalid_argument("Invalid input for scale");
        }
        if (scale_factor <= 0.0)
        {
          for (int i = 0; i < shape_count; ++i)
          {
            delete shapes[i];
          }
          throw std::invalid_argument("Invalid scaling factor");
        }
        if (shape_count == 0)
        {
          return 1;
        }
        const belokurskaya::point_t scale_point = {scale_point_x, scale_point_y};
        belokurskaya::printResults(std::cout, shapes, shape_count);
        for (int i = 0; i < shape_count; ++i)
        {
          belokurskaya::isoScale(shapes[i], scale_point, scale_factor);
        }

        belokurskaya::printResults(std::cout, shapes, shape_count);
        break;
      }
      else
      {
        continue;
      }
    }
    catch (const std::invalid_argument & e)
    {
      std::cerr << e.what() << "\n";
      delete[] points;
      return 1;
    }

    catch (const std::logic_error & e)
    {
      std::cerr << e.what() << "\n";
      delete[] points;
    }
  }
  for (int i = 0; i < shape_count; ++i)
  {
    delete shapes[i];
  }
  return 0;
}
