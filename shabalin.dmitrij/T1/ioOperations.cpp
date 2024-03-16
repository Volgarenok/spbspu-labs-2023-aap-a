#include "ioOperations.hpp"

void shabalin::inputShapes(std::istream &input, size_t &countOfShapes)
{
  std::string shapes[4] = { "RECTANGLE", "TRIANGLE", "SQUARE", "PARALLELOGRAM"};
  std::string name = "";
  Shape **shape = nullptr;
  char character = 0;

  while ((input >> name) && (name != "") && (name != "SCALE"))
  {
    for (size_t i = 0; i < shape; ++i)
    {
      if (name == shapes[i])
      {
        Shape **newShape = new Shape *[countOfShapes + 1];
        for (size_t k = 0; k < countOfShapes; ++k)
        {
          newShapes[k] = shape[k];
        }
        delete[] shape;
        shape = newShape;
        try
        {
          readOfShapes(input, shape, countOfShapes, name);
        }
        catch (const std::exception& e)
        {
          std::cerr << e.what() << '\n';
        }
      }
    }

    input >> std::noskipws;
    while (character != '\n')
    {
      input >> character;
    }
    input >> std::skipws;
  }
  return shape;
}

void shabalin::outputOfShapes(std::ostream &output, const Shape *const *shapes, const size_t &numberOfShapes)
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
  /*
  output << std::fixed; 
  output.precision(1);
  double area = 0;
  for (size_t i = 0; i < numberOfShapes; ++i)
  {
    area += shapes[i]->getArea();
  }
  output << area;
  for (size_t i = 0; i < numberOfShapes; ++i)
  {
    rectangle_t currentShape = shapes[i]->getFrameRect();
    double leftCornerX = currentShape.position.x - (currentShape.width / 2.0);
    double leftCornerY = currentShape.position.y - (currentShape.height / 2.0);
    double rightCornerX = currentShape.position.x + (currentShape.height / 2.0);
    double rightCornerY = currentShape.position.y + (currentShape.width / 2.0);
    output << " " << leftCornerX << " " << leftCornerY << " " << rightCornerX << " " << rightCornerY;
  }
  output << "\n";
  */
}
