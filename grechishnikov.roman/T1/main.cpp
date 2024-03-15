#include <stdexcept>
#include <iostream>
#include <cstring>
#include <inputString.hpp>
#include "inputShapes.hpp"
#include "parametersLogic.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "polygon.hpp"
#include "isoScale.hpp"
#include "outputShapes.hpp"

int main()
{
  using namespace grechishnikov;

  const char* str = nullptr;
  const char* name = nullptr;
  Shape* shapes[1000] = { nullptr };

  size_t count = 0;
  bool endOfInput = false;
  bool scaleHappened = true;
  try
  {
    while (!endOfInput)
    {
      const char* tempStr = inputString(std::cin);
      if (!std::cin)
      {
        endOfInput = true;
        scaleHappened = false;
        delete[] str;
        delete[] name;
        continue;
      }
      delete[] str;
      str = tempStr;
      const char* tempName = parseName(str);
      delete[] name;
      name = tempName;

      if (name != nullptr)
      {
        if (std::strcmp(name, "SCALE") != 0)
        {
          try
          {
            shapes[count] = inputShape(str);
            count++;
          }
          catch (const std::logic_error &e)
          {
            std::cerr << "Error: " << e.what() << '\n';
          }
        }
        if (std::strcmp(name, "SCALE") == 0)
        {
          endOfInput = true;
         if (count == 0)
          {
            throw std::logic_error("Nothing to scale");
          }
          size_t size = 0;
          const double* values = parseValues(str + 5, size);
          if (size != 3)
          {
            delete[] values;
            throw std::logic_error("Incorrect number of parameters to scale");
          }
          if (values[2] <= 0)
          {
            delete[] values;
            throw std::logic_error("Incorrect scale ratio");
          }

          outputShapes(std::cout, shapes, count);
          std::cout << '\n';
          for (size_t g = 0; g < count; g++)
          {
            unsafeIsoScale(shapes[g], { values[0], values[1] }, values[2]);
          }
          outputShapes(std::cout, shapes, count);
          std::cout << '\n';

          delete[] values;
          delete[] str;
          delete[] name;
        }
      }
    }
  }
  catch (const std::bad_alloc &e)
  {
    delete[] str;
    delete[] name;
    freeShapes(shapes, count);
    std::cerr << "Error: Cannot allocate enough memory" << '\n';
    return 2;
  }
  catch (const std::logic_error &e)
  {
    delete[] str;
    delete[] name;
    freeShapes(shapes, count);
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }

  if (!scaleHappened)
  {
    freeShapes(shapes, count);
    std::cerr << "Scale was not inputted" << '\n';
    return 3;
  }

  freeShapes(shapes, count);
}
