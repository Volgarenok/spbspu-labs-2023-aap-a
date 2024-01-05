#include "inputshape.hpp"
#include <string>
#include "rectangle.hpp"
#include "triangle.hpp"
#include "parallelogram.hpp"

piyavkin::Shape** piyavkin::inputShape(std::istream& in, size_t& shapeCount)
{
  std::string name = "";
  double* parameters = nullptr;
  std::string shapeNames[3] = { "RECTANGLE", "TRIANGLE", "PARALLELOGRAM" };
  size_t shapeParametersCount[3] = {4, 6, 6};
  Shape** shapeArray = nullptr;
  Shape** oldShapeArray = nullptr;
  char symbol = 0;
  while (in >> name)
  {
    for (size_t i = 0; i < 3; ++i)
    {
      if (name == shapeNames[i])
      {
        parameters = new double[shapeParametersCount[i]];
        for (size_t j = 0; j < shapeParametersCount[i]; ++j)
        {
          in >> parameters[j];
        }
        if (!in)
        {
          for (size_t i = 0; i < shapeCount; ++i)
          {
            delete shapeArray[i];
          }
          delete[] shapeArray;
          delete[] parameters;
          throw std::logic_error("Invalid arguments");
        }
        oldShapeArray = shapeArray;
        shapeArray = new Shape * [shapeCount + 1];
        if (oldShapeArray)
        {
          for (size_t i = 0; i < shapeCount + 1; ++i)
          {
            shapeArray[i] = oldShapeArray[i];
          }
        }
        delete[] oldShapeArray;
        try
        {
          if (name == "RECTANGLE")
          {
            shapeArray[shapeCount] = new Rectangle({ parameters[0], parameters[1] }, { parameters[2], parameters[3] });
          }
          else if (name == "TRIANGLE")
          {
            shapeArray[shapeCount] = new Triangle({ parameters[0], parameters[1] }, { parameters[2], parameters[3] }, { parameters[4], parameters[5] });
          }
          else if (name == "PARALLELOGRAM")
          {
            shapeArray[shapeCount] = new Parallelogram({ parameters[0], parameters[1] }, { parameters[2], parameters[3] },\
                { parameters[4], parameters[5] });
          }
        }
        catch (const std::logic_error& e)
        {
          std::cerr << e.what() << "\n";
          delete[] parameters;
          continue;
        }
        catch (const std::bad_alloc& e)
        {
          delete[] parameters;
          for (size_t i = 0; i < shapeCount; ++i)
          {
            delete shapeArray[i];
          }
          delete[] shapeArray;
          throw std::logic_error("Memory not allocated");
        }
        delete[] parameters;
        ++shapeCount;
      }
    }
    if (name == "SCALE")
    {
      break;
    }
    in >> std::noskipws;
    while (symbol != '\n')
    {
      in >> symbol;
    }
    in >> std::skipws;
  }
  if (name == "")
  {
    throw std::logic_error("It is not shape");
  }
  return shapeArray;
}

