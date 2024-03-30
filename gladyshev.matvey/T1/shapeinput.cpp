#include "shapeinput.hpp"

#include <iostream>

#include "definedata.hpp"

void gladyshev::shapeInput(std::istream& in, Shape ** shapes, size_t& counter)
{
  size_t mainCounter = 0;
  bool unsupFig = false;
  std::string inputName = "";
  while ((in >> inputName) && (inputName != "SCALE"))
  {
    try
    {
      Shape * checkedShape = identifyShape(inputName, in);
      if (in.get() != '\n')
      {
        delete checkedShape;
        throw std::logic_error("too many args");
      }
      shapes[mainCounter++] = checkedShape;
    }
    catch (const std::invalid_argument& e)
    {
      unsupFig = true;
    }
    catch (const std::logic_error& e)
    {
      freeMemory(shapes, mainCounter);
      throw;
    }
  }
  if (in.eof())
  {
    freeMemory(shapes, mainCounter);
    throw std::out_of_range("EOF");
  }
  counter = mainCounter;
  if (counter == 0)
  {
    throw std::logic_error("lack of support data");
  }
  if (unsupFig)
  {
    throw std::runtime_error("there are incorrect or unsupported figures");
  }
}
