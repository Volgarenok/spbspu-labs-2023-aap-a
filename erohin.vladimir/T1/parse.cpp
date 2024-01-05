#include "parse.hpp"
#include <cstring>
#include <stdexcept>
#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "diamond.hpp"
#include "complexquad.hpp"
#include "input_string.hpp"

erohin::Shape* erohin::parseShape(const char* str, point_t& pos, double& ratio)
{
  erohin::Shape* shape = nullptr;
  const char* type[] = { "RECTANGLE", "TRIANGLE", "DIAMOND", "COMPLEXQUAD", "SCALE" };
  char* string = nullptr;
  try
  {
    string = new char[30 + 1];
  }
  catch (const std::bad_alloc&)
  {
    return nullptr;
  }
  string[0] = '\0';
  size_t i = 0;
  while (str[i] != '\0' && str[i] != ' ' && i < 30)
  {
    string[i] = str[i];
    string[i + 1] = '\0';
    ++i;
  }
  size_t add_ind = i + 1;
  i = 0;
  const size_t iter_size = 10;
  size_t size = iter_size;
  char* num = nullptr;
  char* temp = nullptr;
  double* par = nullptr;
  try
  {
    num = new char[iter_size + 1];
    double* par = new double[iter_size]{ 0.0 };
    size_t j = 0;
    while (str[add_ind + i] != '\0')
    {
      if (add_ind + i == size)
      {
        temp = resize(num, size, iter_size);
        size += iter_size;
        delete[] num;
        num = temp;
      }
      num[i] = str[add_ind + i];
      num[i + 1] = '\0';
      ++i;
      if (str[add_ind + i] == ' ' || str[add_ind + i] == '\0')
      {
        par[j] = std::stod(num, nullptr);
        delete[] num;
        num = new char[iter_size + 1];
        add_ind = i + add_ind + 1;
        i = 0;
        ++j;
        if (j == iter_size)
        {
          throw std::overflow_error("Too many arguments");
        }
      }
    }
    shape = createShape(string, par, j, pos, ratio);
    delete[] num;
    delete[] string;
    delete[] par;
  }
  catch (...)
  {
    delete[] string;
    delete[] num;
    delete[] par;
    shape = nullptr;
  }
  return shape;
}

erohin::Shape* erohin::createShape(const char* name, double* par, size_t par_size, point_t& pos, double& ratio)
{
  Shape* shape = nullptr;
  if (!strcmp(name, "RECTANGLE"))
  {
    if (par_size != 4)
    {
      shape = new Rectangle();
    }
    else
    {
      shape = new Rectangle({ par[0], par[1] }, { par[2], par[3] });
    }
  }
  else if (!strcmp(name, "TRIANGLE"))
  {
    if (par_size != 6)
    {
      shape = new Triangle();
    }
    else
    {
      point_t point[3];
      for (int i = 0; i < 3; ++i)
      {
        point[i] = { par[2 * i], par[2 * i + 1] };
      }
      shape = new Triangle(point);
    }  
  }
  else if (!strcmp(name, "DIAMOND"))
  {
    if (par_size != 6)
    {
      shape = new Diamond();
    }
    else
    {
      point_t point[3];
      for (int i = 0; i < 3; ++i)
      {
        point[i] = { par[2 * i], par[2 * i + 1] };
      }
      shape = new Diamond(point);
    }
  }
  else if (!strcmp(name, "COMPLEXQUAD"))
  {
    if (par_size != 8)
    {
      shape = new Complexquad();
    }
    else
    {
      point_t point[4];
      for (int i = 0; i < 4; ++i)
      {
        point[i] = { par[2 * i], par[2 * i + 1] };
      }
      shape = new Complexquad(point);
    }
  }
  else if (!strcmp(name, "SCALE"))
  {
    pos = { par[0], par[1] };
    ratio = par[2];
    return nullptr;
  }
  return shape;
}
