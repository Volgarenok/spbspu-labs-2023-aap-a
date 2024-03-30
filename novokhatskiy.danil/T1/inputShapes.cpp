#include "inputShapes.hpp"
#include <iostream>
#include <string>
#include "rectangle.hpp"
#include "ring.hpp"
#include "ellipse.hpp"

void novokhatskiy::freeShapes(Shape** shapes, size_t shapeCounter)
{
  for (size_t i = 0; i < shapeCounter; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}

novokhatskiy::Shape** novokhatskiy::inputShapes(std::istream& input, size_t& shapeCounter)
{
  std::string shapesNames[3] = { "RECTANGLE", "RING", "ELLIPSE" };
  size_t rightShapesParametersCount[3] = { 4, 4, 4 };
  std::string currentName = "";
  double* currentParameters = nullptr;
  novokhatskiy::Shape** currentShapes = nullptr;
  novokhatskiy::Shape** oldShapes = nullptr;
  while (input >> currentName)
  {
    for (size_t i = 0; i < 3; ++i)
    {
      if (currentName == shapesNames[i])
      {
        try
        {
          currentParameters = new double[rightShapesParametersCount[i]];
        }
        catch (const std::bad_alloc&)
        {
          if (currentShapes != nullptr)
          {
            freeShapes(currentShapes, shapeCounter);
          }
          throw;
        }
        for (size_t j = 0; j < rightShapesParametersCount[i]; j++)
        {
          input >> currentParameters[j];
        }

        if (!input)
        {
          if (currentShapes != nullptr)
          {
            freeShapes(currentShapes, shapeCounter);
          }
          delete[] currentParameters;
          throw std::invalid_argument("Wrong arguments");
        }
        oldShapes = currentShapes;
        currentShapes = new Shape * [shapeCounter + 1];
        if (oldShapes)
        {
          for (size_t i = 0; i < shapeCounter; i++)
          {
            currentShapes[i] = oldShapes[i];
          }
        }
        delete[] oldShapes;
        try
        {
          double* cP = currentParameters;
          if (currentName == "RECTANGLE")
          {
            currentShapes[shapeCounter] = new Rectangle({ cP[0], cP[1] }, { cP[2], cP[3] });
          }
          else if (currentName == "RING")
          {
            currentShapes[shapeCounter] = new Ring({ cP[0], cP[1] }, cP[2], cP[3]);
          }
          else if (currentName == "ELLIPSE")
          {
            currentShapes[shapeCounter] = new Ellipse({ cP[0], cP[1] }, cP[2], cP[3]);
          }
          ++shapeCounter;
        }
        catch (const std::bad_alloc&)
        {
          delete[] currentParameters;
          freeShapes(currentShapes, shapeCounter);
          throw;
        }
        catch (const std::exception& e)
        {
          std::cerr << e.what() << '\n';
        }
        delete[] currentParameters;
      }
    }
    if (currentName == "")
    {
      std::cerr << "Wrong input\n";
    }
    if (currentName == "SCALE")
    {
      break;
    }
    std::string emptyString = "";
    std::getline(std::cin, emptyString);
  }
  return currentShapes;
}
