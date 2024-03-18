#include "inputOutputShapes.hpp"
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
  double points[4]();
  shabalin::readPoints(input, points, 4);
  Shapes[countOfShape] = new Rectangle({ points[0], points[1] } , { points[2], points[3] });
}

void shabalin::readOfSquare(std::istream &input, Shape **Shapes, size_t &countOfShape)
{
  double points[3]();
  shabalin::readPoints(input, points, 3);
  Shapes[countOfShape] = new Square({ points[0], points[1] } , points[2]);
}

void shabalin::readOfTriangle(std::istream &input, Shape **Shapes, size_t &countOfShape)
{
  double points[6]();
  shabalin::readPoints(input, points, 6);
  Shapes[countOfShape] = new Triangle({ points[0], points[1] } , { points[2], points[3] }, { points[4], points[5]});
}

void shabalin::readOfParallelogram(std::istream &input, Shape **Shapes, size_t &countOfShape)
{
  double points[6]();
  shabalin::readPoints(input, points, 6);
  Shapes[countOfShape] = new Parallelogram({ points[0], points[1] } , { points[2], points[3] }, { points[4], points[5]});
}

Shape **shabalin::readOfShapes(std::istream &input, Shape **Shapes, size_t &countOfShape)
{

  std::string name = "";
  input >> name;
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

void shabalin::outputOfShapes(std::ostream &output, const Shape **shapes, const size_t &numberOfShapes)
{
  if (numberOfShapes == 0)
  {
    throw std::logic_error("zero shape");
  }

  double area = 0.0;
  for (size_t i = 0; i < numberOfShapes; ++i)
  {
    area += shapes[i]->getArea();
  }
  output << area;

  for (size_t i = 0; i < numberOfShapes; ++i)
  {
    double width = shapes[i]->getFrameRect().width;
    double height = shapes[i]->getFrameRect().height;
    point_t poi = shapes[i]->getFrameRect().position;
    point_t leftCorner = { poi.x - width / 2.0, poi.y - height / 2.0 };
    point_t rightCorner = { poi.x + width / 2.0, poi.y + height / 2.0 };
    output << " " << leftCorner.x << " " << leftCorner.y << " " << rightCorner.x << " " << rightCorner.y;
  }
