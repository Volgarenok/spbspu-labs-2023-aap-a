#include "input_figures.hpp"
#include <limits>
#include <stdexcept>
#include <string>

std::string* nikitov::inputFigures(std::istream& input)
{
  size_t size = 1;
  bool status = true;
  std::string* figures = new std::string[size]{};
  try
  {
    do
    {
      std::string line;
      input >> std::noskipws;
      status = enterLine(line, input);
      input >> std::skipws;
      figures[size - 1] = line;

      if (!status)
      {
        return figures;
      }

      size_t maxLim = std::numeric_limits< size_t >::max();
      if (size > maxLim - 1)
      {
        throw std::out_of_range("Error: Array size out of range");
      }
      size += 1;

      std::string* tempFigures = nullptr;
      try
      {
        figures = increaseArray(figures, tempFigures, size);
      }
      catch (const std::bad_alloc&)
      {
        delete[] tempFigures;
        throw;
      }

    } while (status);
  }
  catch (...)
  {
    delete[] figures;
    throw;
  }
  return figures;
}

bool nikitov::enterLine(std::string line, std::istream& input)
{
  char symb = 0;
  while (input >> symb)
  {
    if (symb == '\n')
    {
      line.push_back('\0');
      if (line.find("SCALE") != std::string::npos)
      {
        return false;
      }
      else
      {
        return true;
      }
    }
  }
  if (!input)
  {
    return false;
  }
  return true;
}

std::string* nikitov::increaseArray(std::string* figures, std::string* tempFigures, size_t size)
{
  tempFigures = new std::string[size - 1]{};
  for (size_t j = 0; j != size; ++j)
  {
    tempFigures[j] = figures[j];
  }
  delete[] figures;

  figures = new std::string[size]{};
  for (size_t j = 0; j != size; ++j)
  {
    figures[j] = tempFigures[j];
  }
  delete[] tempFigures;
  return figures;
}
