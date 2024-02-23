#include "geometryFunctions.hpp"
#include <cmath>

void isaychev::changeCoords(point_t & p, double dX, double dY)
{
  p.x += dX;
  p.y += dY;
}
