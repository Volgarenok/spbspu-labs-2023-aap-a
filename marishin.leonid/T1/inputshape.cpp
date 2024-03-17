#include "inputshape.hpp"

void marishin::readRectangle(std::istream& in, Shape** currentShapes, size_t& shapeCount)
{
  double option[4]{};
  marishin::readArray(in, option, 4);

  if (!in)
  {
    throw std::invalid_argument("Invalid rectangle parameters");
  }
  currentShapes[shapeCount] = new Rectangle({ option[0], option[1] }, { option[2], option[3] });
}

void marishin::readTriangle(std::istream& in, Shape** currentShapes, size_t& shapeCount)
{
  double option[6]{};
  marishin::readArray(in, option, 6);

  if (!in)
  {
    throw std::invalid_argument("Invalid triangle parameters");
  }
  currentShapes[shapeCount] = new Triangle({ option[0], option[1] }, { option[2], option[3] }, { option[4], option[5] });
}

void marishin::readRing(std::istream& in, Shape** currentShapes, size_t& shapeCount)
{
  double option[4]{};
  marishin::readArray(in, option, 4);

  if (!in)
  {
    throw std::invalid_argument("Invalid ring parameters");
  }
  currentShapes[shapeCount] = new Ring({ option[0], option[1] }, option[2], option[3]);
}

void marishin::readShape(std::istream& in, Shape** currentShapes, size_t& shapeCount, const std::string& currentName)
{
  try
  {
    if (currentName == "RECTANGLE")
    {
      readRectangle(in, currentShapes, shapeCount);
    }
    else if (currentName == "TRIANGLE")
    {
      readTriangle(in, currentShapes, shapeCount);
    }
    else if (currentName == "RING")
    {
      readRing(in, currentShapes, shapeCount);
    }
    else
    {
      throw std::runtime_error("Unknown shape type: ");
    }
    ++shapeCount;
  }
  catch (const std::bad_alloc& e)
  {
    cleanupShapes(currentShapes, shapeCount);
    throw;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
}

marishin::Shape** marishin::inputShape(std::istream& in, size_t& shapeCount)
{
  const size_t numShapes = 3;
  std::string shapeNames[numShapes] = { "RECTANGLE", "TRIANGLE", "RING" };
  Shape** currentShapes = nullptr;
  char symbol = 0;
  std::string currentName = "";

  while ((in >> currentName) && (currentName != "") && (currentName != "SCALE"))
  {
    for (size_t i = 0; i < numShapes; ++i)
    {
      if (currentName == shapeNames[i])
      {
        Shape** newShapes = new Shape* [shapeCount + 1];
        for (size_t k = 0; k < shapeCount; k++)
        {
          newShapes[k] = currentShapes[k];
        }
        delete[] currentShapes;
        currentShapes = newShapes;
        try
        {
          readShape(in, currentShapes, shapeCount, currentName);
        }
        catch (const std::exception& e)
        {
          std::cerr << e.what() << '\n';
        }
      }
    }

    in >> std::noskipws;
    while (symbol != '\n')
    {
      in >> symbol;
    }
    in >> std::skipws;
  }
  return currentShapes;
}

void marishin::cleanupShapes(Shape** shapes, size_t& count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}
