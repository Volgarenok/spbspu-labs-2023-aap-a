#include "freeshapes.hpp"

void petuhov::freeShapes(petuhov::Shape ** shapes, size_t shapeCount)
{
  for (size_t i = 0; i < shapeCount; ++i)
  {
    delete shapes[i];
    shapes[i] = nullptr;
  }
  delete[] shapes;
}
