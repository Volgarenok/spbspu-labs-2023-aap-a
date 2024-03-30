#include "inputshape.hpp"
#include <string>
#include <iostream>
#include "compositeshape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "parallelogram.hpp"

void piyavkin::inputParameters(std::istream& in, double* parameters, size_t parametersCount)
{
  for (size_t j = 0; j < parametersCount; ++j)
  {
    in >> parameters[j];
  }
  if (!in)
  {
    throw std::logic_error("Invalid arguments");
  }
}

void piyavkin::clearMemory(Shape** shapes, size_t shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    delete shapes[i];
  }
  delete[] shapes;
}

piyavkin::Shape* piyavkin::inputRectangle(std::istream& in)
{
  constexpr size_t parametersCount = 4;
  double parameters[parametersCount] = {};
  inputParameters(in, parameters, parametersCount);
  Shape* shape = new Rectangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]});
  return shape;
}

piyavkin::Shape* piyavkin::inputTriangle(std::istream& in)
{
  constexpr size_t parametersCount = 6;
  double parameters[parametersCount] = {};
  inputParameters(in, parameters, parametersCount);
  Shape* shape = new Triangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]}, {parameters[4], parameters[5]});
  return shape;
}

piyavkin::Shape* piyavkin::inputParallelogram(std::istream& in)
{
  constexpr size_t parametersCount = 6;
  double parameters[parametersCount] = {};
  inputParameters(in, parameters, parametersCount);
  Shape* shape = new Parallelogram({parameters[0], parameters[1]}, {parameters[2], parameters[3]}, {parameters[4], parameters[5]});
  return shape;
}

void piyavkin::inputShape(std::istream& in, CompositeShape& cs)
{
  std::string name = "";
  constexpr size_t numbersFigures = 3;
  std::string shapeNames[numbersFigures] = {"RECTANGLE", "TRIANGLE", "PARALLELOGRAM"};
  char symbol = 0;
  while (in >> name)
  {
    for (size_t i = 0; i < numbersFigures; ++i)
    {
      if (name == shapeNames[i])
      {
        Shape* shape = nullptr;
        try
        {
          if (name == "RECTANGLE")
          {
            shape = inputRectangle(in);
            cs.push_back(shape);
          }
          else if (name == "TRIANGLE")
          {
            shape = inputTriangle(in);
            cs.push_back(shape);
          }
          else if (name == "PARALLELOGRAM")
          {
            shape = inputParallelogram(in);
            cs.push_back(shape);
          }
        }
        catch (const std::logic_error& e)
        {
          std::cerr << e.what() << '\n';
          continue;
        }
        catch (const std::bad_alloc& e)
        {
          delete shape;
          throw std::logic_error(e.what());
        }
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
  if (!in)
  {
    throw std::logic_error("It is not shape");
  }
}

