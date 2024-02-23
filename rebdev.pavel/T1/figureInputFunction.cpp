#include "figureInputFunction.hpp"
#include "rectangle.hpp"
#include "concave.hpp"
#include "polygon.hpp"


rebdev::Shape * rebdev::newFigure(std::istream & input, const std::string & name)
{
  Shape * pointerToFigure = nullptr;
  point_t * points = nullptr;

  size_t numOfPoints = 0;
  points = inputPoints(input, numOfPoints);

  try
  {
    if (name.find("RECTANGLE") != std::string::npos)
    {
      pointerToFigure = new Rectangle(points[0], points[1]);
    }
    else if (name.find("CONCAVE") != std::string::npos)
    {
      pointerToFigure = new Concave(points[0], points[1], points[2], points[3]);
    }
    else if (name.find("POLYGON") != std::string::npos)
    {
      pointerToFigure = new Polygon(points, numOfPoints);
    }
  }
  catch (const std::logic_error & e)
  {
    delete[] points;
    throw;
  }

  delete[] points;
  return pointerToFigure;
}

rebdev::point_t * rebdev::inputPoints(std::istream & input, size_t & numOfPoints)
{
    point_t * points = new point_t[1];
    point_t * bufferArr = nullptr;
    size_t bufferSize = 0;

    while (input >> points[numOfPoints].x >> points[numOfPoints].y)
    {
      if (numOfPoints == bufferSize)
      {
        bufferSize += 10;
        try
        {
          bufferArr = new point_t[bufferSize];
        }
        catch (const std::bad_alloc & e)
        {
          delete[] points;
          throw;
        }

        for (size_t i = 0; i <= numOfPoints; ++i)
        {
          bufferArr[i] = points[i];
        }

        delete[] points;
        points = bufferArr;
        bufferArr = nullptr;
      }

      numOfPoints += 1;
    }

    input.clear();

    try
    {
      bufferArr = new point_t[numOfPoints];
    }
    catch (const std::bad_alloc & e)
    {
      delete[] points;
      throw;
    }

    for (size_t i = 0; i < numOfPoints; ++i)
    {
      bufferArr[i] = points[i];
    }

    delete[] points;
    points = bufferArr;
    bufferArr = nullptr;

    return points;
}
