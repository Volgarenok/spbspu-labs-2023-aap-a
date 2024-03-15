#include <iostream>
#include <inputString.hpp>
#include "creatingFigures.hpp"
#include "stringManipulations.hpp"
#include "outputResults.hpp"
#include "compositeShape.hpp"
#include "isoscale.hpp"

int main()
{
  using namespace isaychev;
  const char * scaleStr = "SCALE ";
  char * currDesc = nullptr;
  CompositeShape cShape;
  size_t figDescMistakeCheck = 0, capacity = 10;
  bool eofCheck = false, scaleCheck = false;
  while (!scaleCheck)
  {
    try
    {
      currDesc = inputString(std::cin, capacity);
      if (std::cin.eof())
      {
        eofCheck = true;
        break;
      }
      if (checkString(currDesc, scaleStr) == 1)
      {
        scaleCheck = true;
      }
      Shape * figure = createFigure(currDesc);
      if (figure != nullptr)
      {
        cShape.pushBack(figure);
      }
    }
    catch (const std::bad_alloc &)
    {
      delete [] currDesc;
      std::cerr << "can't allocate memory for description of figure or a figure itself\n";
      return 1;
    }
    catch (const std::out_of_range & e)
    {
      std::cerr << e.what() << "\n";
    }
    catch (const std::logic_error &)
    {
      figDescMistakeCheck++;
    }
    if (!scaleCheck)
    {
      delete [] currDesc;
    }
  }
  if (cShape.size() == 0 && checkString(currDesc, scaleStr) == 1)
  {
    delete [] currDesc;
    std::cerr << "nothing to scale\n";
    return 2;
  }
  else if (eofCheck == 1 && checkString(currDesc, scaleStr) == 0)
  {
    delete [] currDesc;
    std::cerr << "input was finished with eof symbol; scale wasn't inputed\n";
    return 3;
  }
  else if (countWSpaces(currDesc) > 1)
  {
    constexpr size_t numOfScalePars = 3;
    double scaleParams[numOfScalePars] = {};
    parseParams(currDesc, numOfScalePars, scaleParams);
    try
    {
      std::cout << std::fixed;
      std::cout.precision(1);
      if (scaleParams[2] > 0)
      {
        outputResults(std::cout, cShape);
        std::cout << "\n";
      }
      isoscale(scaleParams, cShape);
      outputResults(std::cout, cShape);
      std::cout << "\n";
    }
    catch (const std::invalid_argument & e)
    {
      std::cerr << e.what() << "\n";
      delete [] currDesc;
      return 4;
    }
  }
  if (figDescMistakeCheck > 0)
  {
    std::cerr << "There were mistakes in figure descriptions\n";
  }
  delete [] currDesc;
}
