#include "creatingFigures.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>
#include "stringManipulations.hpp"
#include "regular.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

size_t determineShape(const char * str)
{
  constexpr size_t numOfFigures = 3;
  const char * figureNames[numOfFigures] = {"RECTANGLE", "CIRCLE", "REGULAR"};
  size_t numOfCurrFigure = 1;
  for (size_t i = 0; i < numOfFigures; i++)
  {
    if (isaychev::checkString(str, figureNames[i]) == 1)
    {
      return numOfCurrFigure;
    }
    numOfCurrFigure++;
  }
  return 0;
}

isaychev::Rectangle * createRectangle(const double * params)
{
  isaychev::point_t bot = {params[0], params[1]};
  isaychev::point_t top = {params[2], params[3]};
  isaychev::Rectangle * rec = new isaychev::Rectangle(bot, top);
  return rec;
}

isaychev::Circle * createCircle(const double * params)
{
  return new isaychev::Circle({params[0], params[1]}, params[2]);
}

isaychev::Regular * createRegular(const double * params)
{
  isaychev::point_t p1 = {params[0], params[1]};
  isaychev::point_t p2 = {params[2], params[3]};
  isaychev::point_t p3 = {params[4], params[5]};
  return new isaychev::Regular(p1, p2, p3);
}

isaychev::Shape * isaychev::createFigure(char * str)
{
  size_t numOfCurrFigure = determineShape(str);
  Shape * currFigure = nullptr;
  if (numOfCurrFigure == 1)
  {
    double parameters[4] = {};
    parseParams(str, 4, parameters);
    currFigure = createRectangle(parameters);
  }
  else if (numOfCurrFigure == 2)
  {
    double parameters[3] = {};
    parseParams(str, 3, parameters);
    currFigure = createCircle(parameters);
  }
  else if (numOfCurrFigure == 3)
  {
    double parameters[6] = {};
    parseParams(str, 6, parameters);
    currFigure = createRegular(parameters);
  }
  return currFigure;
}
