#ifndef MATRIX_H
#define MATRIX_H
#include <istream>
void sMatrix (std::istream & in, int * a, int e);
void dMatrix (std::istream & in, int * a, int e);
void matrixSubtraction(int * original, int * reverse, int n);
void clockwise(int * a, int rows, int columns);
#endif

