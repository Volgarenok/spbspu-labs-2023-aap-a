#include <iostream>
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "del_out_functions.hpp"
#include "isoscale.hpp"

int main()
{
  using namespace lopatina;

  Shape * array[1000] = {};
  size_t counter = 0;
  int error_flag = 0;
  int figure_exist_flag = 0;

  std::string shapesNames[4] = {"RECTANGLE", "SQUARE", "TRIANGLE", "DIAMOND"};
  size_t amountParameters[4] = {4, 3, 6, 6};

  while (counter != 1000)
  {
    std::string name = "";
    std::cin >> name;
    if (name == "SCALE")
    {
      double center_x = 0.0, center_y = 0.0, index = 0.0;
      std::cin >> center_x >> center_y >> index;
      if (figure_exist_flag == 0)
      {
        std::cerr << "Nothing to scale\n";
        return 1;
      }
      if (counter != 0)
      {
        outputResult(std::cout, array, counter);
        for (size_t i = 0; i < counter; ++i)
        {
          try
          {
            isoScale(array[i], {center_x, center_y}, index);
          }
          catch (const std::invalid_argument & e)
          {
            std::cerr << e.what();
            deleteArray(array, counter);
            return 1;
          }
        }
        outputResult(std::cout, array, counter);
      }
      if (error_flag == 1)
      {
        std::cerr << "Some figure has wrong parameters\n";
      }
      deleteArray(array, counter);
      return 0;
    }
    if (!std::cin)
    {
      std::cerr << "No SCALE command entered\n";
      deleteArray(array, counter);
      return 1;
    }

    double parameters[6] = {};
    for (size_t i = 0; i < 4; ++i)
    {
      if (shapesNames[i] == name)
      {
        figure_exist_flag = 1;
        for (size_t j = 0; j < amountParameters[i]; ++j)
        {
          double param = 0.0;
          std::cin >> param;
          parameters[j] = param;
        }
        try
        {
          if (name == "RECTANGLE")
          {
            array[counter++] = new Rectangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]});
          }
          if (name == "SQUARE")
          {
            array[counter++] = new Square({parameters[0], parameters[1]}, parameters[2]);
          }
          if (name == "TRIANGLE")
          {
            array[counter++] = new Triangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]}, {parameters[4], parameters[5]});
          }
          if (name == "DIAMOND")
          {
            array[counter++] = new Diamond({parameters[0], parameters[1]}, {parameters[2], parameters[3]}, {parameters[4], parameters[5]});
          }
        }
        catch (const std::invalid_argument &)
        {
          error_flag = 1;
        }
      }
    }
  }
}
