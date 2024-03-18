#include "utils.h"

size_t kovtun::parseShapes(std::istream & in, Shape ** shapes)
{
  std::string instruction = "";
  size_t counter = 0;
  for (; instruction != "SCALE"; counter++)
  {
    in >> instruction;
    if (instruction == "RECTANGLE")
    {
      // uninitialized?
      kovtun::point_t rectanglePoints[2];
      for (size_t i = 0; i < 2; i++)
      {
        in >> rectanglePoints[i].x >> rectanglePoints[i].y;
      }
      shapes[counter] = new kovtun::Rectangle(rectanglePoints[0], rectanglePoints[1]);
    }
    else if (instruction == "ELLIPSE")
    {

    }
    else if (instruction == "CIRCLE")
    {

    }
    else if (instruction == "RING")
    {

    }

    // ?
    if (!std::cin)
    {
      std::cerr << "bad input\n";
      // clear shapes
      throw;
    }
  }

  return counter;
}

