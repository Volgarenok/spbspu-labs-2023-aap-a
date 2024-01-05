#include <iostream>
#include "shape.hpp"
#include "concave.hpp"
#include "polygon.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"
#include "figureInputFunction.hpp"

int main()
{
  const char figureName[] = {
    "RECTANGLE",
    "CONCAVE",
    "POLYGON"
  };
  const int sizeOfFigureName[] = {9, 7, 7};

  rebdev::Shape * shapes = nullptr;
  try
  {
    shapes = new rebdev::Shape[1000];
  }
  catch (const std::exception & e)
  {
    std::cerr >> "Error in allocat dynamic memory";
    return 2;
  }

  int numOfShape = 0;
  bool isScale = 0, figureError = 0;
  char sym = 0;

  while (std::cin >> sym)
  {
    rebdev::point_t * pointArr = nullptr;
    int figureNumber = -1;
    size_t numberOfVertexs = 0;
    if (sym == 'S')
    {
      if (isNameCorrect(std::cin, 5, "SCALE"))
      {
        break;
      }
    }
    else if (sym == 'R')
    {
      figureNumber = 0;
      numberOfVertexs = 2;
    }
    else if (sym == 'C')
    {
      figureNumber = 1;
      numberOfVertexs = 4;
    }
    else if (sym == 'P')
    {
      figureNumber = 2;
      numberOfVertexs = 0;
    }

    if (figureNumber != -1)
    {
      if (rebdev::isNameCorrect(std::cin, sizeOfFigureName[figureNumber], figureName[figureNumber]))
      {
        if (rebdev::ipnutVertexs(pointArr, numberOfVertexs))
        {
          if (rebdev::figureIsCorrect(pointArr, numberOfVertexs, figureNumber))
          {
            rebdev::Shape[numOfShape] = newFigure(pointArr, numberOfVertexs, figureNumber);
          }
          else
          {
            figureError = 1;
          }
        }
        else
        {
          figureError = 1;
        }
      }
    }

    while (sym != '\n')
    {
      std::cin >> sym;
    }
  }

  delete[] shapes;

  if (figureError)
  {
    std::cerr << "Some figure is incorrect!\n";
  }
  if (!isScale)
  {
   std::cerr << "Programm end without scale!\n";
   return 1;
  }

  return 0;
}
