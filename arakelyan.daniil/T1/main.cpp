#include <iostream>
#include <stdexcept>
#include <cstring>
#include <inputLine.hpp>

#include "shape.hpp"
#include "base-types.hpp"
#include "inputAndOutputOperations.hpp"
#include "scaleOperations.hpp"
#include "shape-creation.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "parallelogram.hpp"

int main()
{
  using namespace arakelyan;
  size_t maxShapesCount = 1000;
  size_t currentShapesCount = 0;
  Shape **myShapes = new Shape *[maxShapesCount]{nullptr};

  bool errorsFlagShapes = false;
  bool errorsFlagScale = false;

  point_t scalePoint = {0.0, 0.0};
  double scaleK = 0;
  const char *targetWordScale = "SCALE";

  char *string = nullptr;

  bool scaleEntered = false;

  while (!scaleEntered)
  {
    if (!std::cin.good())
    {
      freeMem(myShapes, currentShapesCount);
      std::cerr << "Somthing went wrong with input, might be EOF!\n";
      return 1;
    }

    try
    {
      string = inputLine(std::cin);
    }
    catch (const std::exception &e)
    {
      freeMem(myShapes, currentShapesCount);
      std::cerr << "Error: " << e.what() << "\n";
      return 1;
    }

    const char * foundScale = std::strstr(string, targetWordScale);
    if (foundScale != nullptr)
    {
      inputScaleParam(string, scalePoint, scaleK);
      try
      {
        scaleFunction(myShapes, currentShapesCount, scalePoint, scaleK, std::cout);
      }
      catch (const std::logic_error &e)
      {
        errorsFlagScale = true;
      }
      scaleEntered = true;
    }
    else
    {
      try
      {
        if (string[0] != '\0')
        {
          defineAndCreateShape(myShapes, currentShapesCount, string);
        }
      }
      catch (const std::logic_error &e)
      {
        errorsFlagShapes = true;
      }

      if (myShapes[currentShapesCount] != nullptr)
      {
        currentShapesCount++;
      }
    }
    delete [] string;
  }

  if (errorsFlagShapes)
  {
    std::cerr << "\nSomething went wrong with shapes creation!\n";
  }
  if (errorsFlagScale)
  {
    std::cerr << "Something went wrong with scale process, might be incorrect k of scale!\n";
    freeMem(myShapes, currentShapesCount);
    return 2;
  }

  if (currentShapesCount == 0)
  {
    std::cerr << "\nNothing to scale!\n";
    freeMem(myShapes, currentShapesCount);
    return 2;
  }

  freeMem(myShapes, currentShapesCount);
  return 0;
}
