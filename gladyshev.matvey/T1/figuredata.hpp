#ifndef FIGUREDATA_HPP
#define FIGUREDATA_HPP

#include <iostream>

namespace gladyshev
{
  struct FigureData
  {
    std::string name = "";
    double cord[6]{};
  };
}

#endif