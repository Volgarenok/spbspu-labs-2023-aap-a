#include "inputShapes.hpp"
#include <string>
#include <stdexcept>
#include <stdexcept>

void shabalin::readPoints(std::istream &input, double *points, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    input >> points[i];
  }
   if (!input)
  {
    throw std::invalid_argument("Invalid parametrs");
  }
}

void shabalin::cleanOfShapes(Shape **Shapes, size_t &countOfShape)
{
  for (size_t i = 0; i < countOfShape; ++i)
  {
    delete Shapes[i];
  }
  delete[] Shapes;
}

void shabalin::readOfRectangle(std::istream &input, Shape **Shapes, size_t &countOfShape)
{
  double points[4]{};
  shabalin::readPoints(input, points, 4);
  Shapes[countOfShape] = new Rectangle({ points[0], points[1] } , { points[2], points[3] });
}

void shabalin::readOfSquare(std::istream &input, Shape **Shapes, size_t &countOfShape)
{
  double points[3]{};
  shabalin::readPoints(input, points, 3);
  Shapes[countOfShape] = new Square({ points[0], points[1] } , points[2]);
}

void shabalin::readOfTriangle(std::istream &input, Shape **Shapes, size_t &countOfShape)
{
  double points[6]{};
  shabalin::readPoints(input, points, 6);
  Shapes[countOfShape] = new Triangle({ points[0], points[1] } , { points[2], points[3] }, { points[4], points[5]});
}

void shabalin::readOfParallelogram(std::istream &input, Shape **Shapes, size_t &countOfShape)
{
  double points[6]{};
  shabalin::readPoints(input, points, 6);
  Shapes[countOfShape] = new Parallelogram({ points[0], points[1] } , { points[2], points[3] }, { points[4], points[5]});
}

void shabalin::readOfShapes(std::istream &input, Shape **Shapes, size_t &countOfShape, const std::string &name)
{
  try
  {
    if (name == "RECTANGLE")
    {
      readOfRectangle(input, Shapes, countOfShape);
    }
    else if (name == "TRIANGLE")
    {
      readOfTriangle(input, Shapes, countOfShape);
    }
    else if (name == "SQUARE")
    {
      readOfSquare(input, Shapes, countOfShape);
    }
    else if (name == "PARALLELOGRAM")
    {
      readOfParallelogram(input, Shapes, countOfShape);
    }
    else
    {
      throw std::runtime_error("Unknown shapes");
    }
    ++countOfShape;
  }
  catch (const std::bad_alloc& e)
  {
    cleanOfShapes(Shapes, countOfShape);
    throw;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
}
/*
shabalin::Shape *shabalin::inputOfRectangle(const char str[])
{
  const char *coordsOfString = str + 10;
  double coordsOfArray[4]{};
  size_t position = 0;
  for (size_t i = 0; i < 4; ++i)
  {
    coordsOfArray[i] = std::stod(coordsOfArray, std::addressof(position));
    coordsOfString += position;
  }
  if (*coordsOfArray != '\0')
  {
    throw std::invalid_argument("Invalid arguments for Rectangle");
  }
  constexpr size_t numberOfPoints = 2;
  point_t points[numberOfPoints]{};
  creatingPoints(numberOfPoints, coordsOfArray, points);
  return new Rectangle(points[0], points[1]);
}

shabalin::Shape *shabalin::inputOfTriangle(const char str[])
{
  const char *coordsOfString = str + 9;
  double coordsOfArray[6]{};
  size_t position = 0;
  for (size_t i = 0; i < 6; ++i)
  {
    coordsOfArray[i] = std::stod(coordsOfArray, std::addressof(position));
    coordsOfString += position;
  }
  if (*coordsOfArray != '\0')
  {
    throw std::invalid_argument("Invalid arguments for Rectangle");
  }
  constexpr size_t numberOfPoints = 3;
  point_t points[numberOfPoints]{};
  creatingPoints(numberOfPoints, coordsOfArray, points);
  return new Triangle(points[0], points[1], points[2]); 
}
*/
