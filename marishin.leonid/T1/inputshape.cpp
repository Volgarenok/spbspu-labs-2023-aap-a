#include "inputshape.hpp"

marishin::Shape** marishin::inputShape(std::istream& in, size_t& shapeCount)
{
  const size_t NUM_SHAPES = 3;
  const std::string shapeNames[NUM_SHAPES] = { "RECTANGLE", "TRIANGLE", "RING" };
  const size_t shapeParametrsCount[NUM_SHAPES] = { 4, 6, 4};

  Shape** shapeArray = nullptr;
  char symbol = 0;

  while (true)
  {
    std::string name;
    in >> name;

    if (name == "SCALE")
    {
      break;
    }

    bool isValidShape = false;
    for (size_t i = 0; i < NUM_SHAPES; ++i)
    {
      if (name == shapeNames[i])
      {
        isValidShape = true;

        double* parameters = new double[shapeParametersCount[i]];

        for (size_t j = 0; j < shapeParametersCount[i]; ++j)
        {
          in >> parameters[j];
        }

        if (!in)
        {
          marishin::cleanupShapes(shapeArray, shapeCount);
          delete[] parameters;
          throw std::logic_error("Invalid arguments");
        }

        Shape** oldShapeArray = ShapeArray;
        shapeArray = new Shape* [shapeCount + 1];

        if (oldShapeArray)
        {
          for (size_t k = 0; k < shapeCount; ++k)
          {
            shapeArray[k] = oldShapeArray[k];
          }
          delete[] oldShapeArray;
        }

        try
        {
          shapeArray[shapeCount] = marishin::createShape(name, parameters);
        }
        catch (const std::exception& ex)
        {
          std::cerr << ex.what() << "\n";
          delete[] parameters;
          continue;
        }

        delete[] parameters;
        ++shapeCount;
      }
    }

    if (!isValidShape)
    {
      marishin::skipLine(in);
      throw std::logic_error("It is not a valid shape");
    }
  }

  if (shapeCount = 0)
  {
    throw std::logic_error("No shapes provided");
  }

  return shapeArray;
}

void marishin::cleanupShapes(Shape** shapes, size_t count)
{
  for (size_t i = 0; i < count; ++i)
  {
    delete shapes[i];
  }
  delete[] shapes;
}

marishin::Shape* marishin::createShape(const std::string& name, double* parameters)
{
  if (name == "RECTANGLE")
  {
    return new Rectangle({ parameters[0], parameters[1] }, { parameters[2], parameters[3] });
  }
  else if (name == "TRIANGLE")
  {
    return new Triangle({ parameters[0], parameters[1] }, { parameters[2], parameters[3] }, { parameters[4], parameters[5] });
  }
  else if (name == "RING")
  {
    return new Ring({ parameters[0], parameters[1] }, parameters[2], parameters[3] );
  }

  throw std::logic_error("Unsupported shape type");
}

void marishin::skipLine(std::istream& in)
{
  char symbol;
  in >> std::noskipws;
  while (in >> symbol && symbol != '\n');
  in >> std::skipws;
}
