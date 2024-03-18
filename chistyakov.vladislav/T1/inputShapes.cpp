#include "inputShapes.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "complexquad.hpp"

void chistyakov::inputShapes(std::istream & input, Shape ** array, double * scaleInfo, size_t & size, bool & isBadShape)
{
  std::string shapeName = "";
  bool isScale = false;

  while (std::getline(input, shapeName, ' '))
  {
    if (shapeName.find('\n') == 0)
    {
      shapeName.erase(0, 1);
    }

    try
    {
      if (shapeName.find("RECTANGLE") != std::string::npos)
      {
        double cords[4]{};
        inputDouble(input, 4, cords);
        inputRectangle(cords, array);
        size++;
      }
      else if (shapeName.find("SQUARE") != std::string::npos)
      {
        double cords[3]{};
        inputDouble(input, 3, cords);
        inputSquare(cords, array);
        size++;
      }
      else if (shapeName.find("COMPLEXQUAD") != std::string::npos)
      {
        double cords[8]{};
        inputDouble(input, 8, cords);
        inputComplexquad(cords, array);
        size++;
      }
      else if (shapeName.find("SCALE") != std::string::npos)
      {
        double cords[3]{};
        isScale = true;

        inputDouble(input, 3, cords);
        parseInfoScale(cords, scaleInfo);
        break;
      }
    }
    catch (const std::invalid_argument & e)
    {
      isBadShape = true;
    }

    shapeName.clear();
  }

  if (!isScale)
  {
    throw std::logic_error("No SCALE command!\n");
  }
}

void chistyakov::inputRectangle(double * cords, Shape ** array)
{
  Rectangle * shape = new Rectangle({ {cords[0], cords[1]}, {cords[2], cords[3]} });
  writeShapeInArray(shape, array, 1000);
}

void chistyakov::inputSquare(double * cords, Shape ** array)
{
  Square * shape = new Square({ cords[0], cords[1] }, cords[2]);
  writeShapeInArray(shape, array, 1000);
}

void chistyakov::inputComplexquad(double * cords, Shape ** array)
{
  Complexquad * shape = new Complexquad({ cords[0], cords[1] }, { cords[2], cords[3] }, { cords[4], cords[5] }, { cords[6], cords[7] });
  writeShapeInArray(shape, array, 1000);
}

void chistyakov::inputDouble(std::istream & input, size_t numOfPoints, double * pointsArray)
{
  for (size_t i = 0; i < numOfPoints; ++i)
  {
    input >> pointsArray[i];

    if (!input)
    {
      throw std::logic_error("Bad input!");
    }
  }
}

void chistyakov::writeShapeInArray(Shape * shape, Shape ** array, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    if (array[i] == nullptr)
    {
      array[i] = shape;
      break;
    }
  }
}

void chistyakov::freeArray(Shape ** array, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    if (array[i] == nullptr)
    {
      break;
    }
    delete array[i];
  }
}

void chistyakov::parseInfoScale(double * cords, double * scaleInfo)
{
  scaleInfo[0] = cords[0];
  scaleInfo[1] = cords[1];
  scaleInfo[2] = cords[2];
}
