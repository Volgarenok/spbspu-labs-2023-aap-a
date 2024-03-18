#include "compositeShape.hpp"
#include <limits>
#include <cmath>
#include <stdexcept>
#include "isoscale.hpp"

isaychev::CompositeShape::CompositeShape():
  capacity_(1000),
  currNumOfFigures_(0)
{}

void deleteFigures(isaychev::Shape ** figures, size_t figureCount)
{
  for (size_t i = 0; i < figureCount; i++)
  {
    delete figures[i];
  }
}

isaychev::CompositeShape::~CompositeShape()
{
  deleteFigures(figures_, currNumOfFigures_);
}

void moveFigures(isaychev::Shape ** figs1, isaychev::Shape ** figs2, size_t n)
{
  for (size_t i = 0; i < n; i++)
  {
    figs1[i] = figs2[i];
    figs2[i] = nullptr;
  }
}

isaychev::CompositeShape::CompositeShape(CompositeShape && diffCShape):
  currNumOfFigures_(diffCShape.currNumOfFigures_)
{
  moveFigures(figures_, diffCShape.figures_, diffCShape.currNumOfFigures_);
  diffCShape.currNumOfFigures_ = 0;
}

isaychev::CompositeShape & isaychev::CompositeShape::operator=(CompositeShape && diffCShape)
{
  if (this != std::addressof(diffCShape))
  {
    deleteFigures(figures_, currNumOfFigures_);
    moveFigures(figures_, diffCShape.figures_, diffCShape.currNumOfFigures_);
    currNumOfFigures_ = diffCShape.currNumOfFigures_;
    diffCShape.currNumOfFigures_ = 0;
  }
  return *this;
}

void isaychev::CompositeShape::pushBack(Shape * figure)
{
  if (currNumOfFigures_ != 1000)
  {
    figures_[currNumOfFigures_] = figure;
    currNumOfFigures_++;
  }
  else
  {
    throw std::out_of_range("Max figure number was achieved");
  }
}

void isaychev::CompositeShape::popBack()
{
  if (currNumOfFigures_ == 0)
  {
    throw std::out_of_range("There is nothing to delete");
  }
  delete figures_[currNumOfFigures_ - 1];
  currNumOfFigures_--;
}

void checkPosition(size_t n, size_t numOfPositions)
{
  if (n >= numOfPositions)
  {
    throw std::out_of_range("There is no such position in array");
  }
}

isaychev::Shape & isaychev::CompositeShape::at(size_t n)
{
  checkPosition(n, currNumOfFigures_);
  return *figures_[n];
}

const isaychev::Shape & isaychev::CompositeShape::at(size_t n) const
{
  checkPosition(n, currNumOfFigures_);
  return *figures_[n];
}

isaychev::Shape & isaychev::CompositeShape::operator[](size_t n)
{
  return *figures_[n];
}

const isaychev::Shape & isaychev::CompositeShape::operator[](size_t n) const
{
  return *figures_[n];
}

bool isaychev::CompositeShape::empty() const
{
  return (currNumOfFigures_ == 0);
}

size_t isaychev::CompositeShape::size() const
{
  return currNumOfFigures_;
}

size_t isaychev::CompositeShape::maxSize() const
{
  return capacity_;
}

double isaychev::CompositeShape::getArea() const
{
  double sumOfAreas = 0;
  for (size_t i = 0; i < currNumOfFigures_; i++)
  {
    sumOfAreas += figures_[i]->getArea();
  }
  return sumOfAreas;
}

void getPntsOfRec(isaychev::point_t & p1, isaychev::point_t & p2, isaychev::rectangle_t & rec)
{
  p1 = {rec.pos.x - rec.width / 2, rec.pos.y - rec.height / 2};
  p2 = {rec.pos.x + rec.width / 2, rec.pos.y + rec.height / 2};
}

isaychev::rectangle_t isaychev::CompositeShape::getFrameRect() const
{
  if (currNumOfFigures_ == 0)
  {
    throw std::logic_error("no figures to get frame rectangle of");
  }
  rectangle_t rec = figures_[0]->getFrameRect();
  point_t botL = {0.0, 0.0};
  point_t topR = {0.0, 0.0};
  getPntsOfRec(botL, topR, rec);
  for (size_t i = 1; i < currNumOfFigures_; i++)
  {
    rectangle_t rec = figures_[i]->getFrameRect();
    point_t currBL = {0.0, 0.0};
    point_t currTP = {0.0, 0.0};
    getPntsOfRec(currBL, currTP, rec);
    botL.x = std::min(botL.x, currBL.x);
    topR.x = std::max(topR.x, currTP.x);
    botL.y = std::min(botL.y, currBL.y);
    topR.y = std::max(topR.y, currTP.y);
  }
  double width = topR.x - botL.x;
  double height = topR.y - botL.y;
  point_t pos = {topR.x - width / 2, topR.y - height / 2};
  return {width, height, pos};
}

void isaychev::CompositeShape::move(const point_t & newPos)
{
  point_t center = getFrameRect().pos;
  double dX = newPos.x - center.x;
  double dY = newPos.y - center.y;
  for (size_t i = 0; i < currNumOfFigures_; i++)
  {
    figures_[i]->move(dX, dY);
  }
}

void isaychev::CompositeShape::move(double dX, double dY)
{
  for (size_t i = 0; i < currNumOfFigures_; i++)
  {
    figures_[i]->move(dX, dY);
  }
}

void isaychev::CompositeShape::scale(double coeff)
{
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i < currNumOfFigures_; i++)
  {
    isoscaleFigure(center, coeff, *figures_[i]);
  }
}
