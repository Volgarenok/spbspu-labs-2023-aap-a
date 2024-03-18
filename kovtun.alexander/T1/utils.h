#ifndef UTILS_H
#define UTILS_H

#include <iostream>

#include "shape.h"
#include "rectangle.h"

namespace kovtun
{
  size_t parseShapes(std::istream & in, Shape ** shapes);
}

#endif

