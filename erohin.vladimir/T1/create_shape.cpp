#include "create_shape.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "complexquad.hpp"

erohin::Shape* erohin::createShape(const std::string name, const double* par, size_t par_size)
{
  Shape* shape = nullptr;
  if (name == "RECTANGLE")
  {
    shape = createRectangle(par, par_size);
  }
  else if (name == "TRIANGLE")
  {
    shape = createTriangle(par, par_size);
  }
  else if (name == "DIAMOND")
  {
    shape = createDiamond(par, par_size);
  }
  else if (name == "COMPLEXQUAD")
  {
    shape = createComplexquad(par, par_size);
  }
  else
  {
    throw std::runtime_error("No figure match found");
  }
  return shape;
}

erohin::Shape* erohin::createRectangle(const double* par, size_t par_size)
{
  if (par_size != 4)
  {
    throw std::invalid_argument("Wrong figure parameters number");
  }
  Shape* shape = new Rectangle({ par[0], par[1] }, { par[2], par[3] });
  return shape;
}

erohin::Shape* erohin::createTriangle(const double* par, size_t par_size)
{
  if (par_size != 6)
  {
    throw std::invalid_argument("Wrong figure parameters number");
  }
  point_t point[3]{ {0.0, 0.0} };
  for (int i = 0; i < 3; ++i)
  {
    point[i] = { par[2 * i], par[2 * i + 1] };
  }
  Shape* shape = new Triangle(point[0], point[1], point[2]);
  return shape;
}

erohin::Shape* erohin::createComplexquad(const double* par, size_t par_size)
{
  if (par_size != 8)
  {
    throw std::invalid_argument("Wrong figure parameters number");
  }
  point_t point[4]{ 0.0, 0.0 };
  for (int i = 0; i < 4; ++i)
  {
    point[i] = { par[2 * i], par[2 * i + 1] };
  }
  Shape* shape = new Complexquad(point[0], point[1], point[2], point[3]);
  return shape;
}

erohin::Shape* erohin::createDiamond(const double* par, size_t par_size)
{
  if (par_size != 6)
  {
    throw std::invalid_argument("Wrong figure parameters number");
  }
  point_t point[3]{ {0.0, 0.0} };
  for (int i = 0; i < 3; ++i)
  {
    point[i] = { par[2 * i], par[2 * i + 1] };
  }
  Shape* shape = new Diamond(point[0], point[1], point[2]);
  return shape;
}

void erohin::inputScaleParameteres(const double* par, size_t par_size, point_t& pos, double& ratio)
{
  if (par_size != 3 || par[2] <= 0.0)
  {
    throw std::logic_error("Wrong scale command parameters");
  }
  pos = { par[0], par[1] };
  ratio = par[2];
}
