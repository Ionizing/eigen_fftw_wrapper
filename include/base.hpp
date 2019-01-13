#pragma once
#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <fstream>
#include <complex>
#include <algorithm>
#include <fstream>
#include <tuple>
#include <iomanip>
#include <vector>
#include <cmath>

#include <fftw3.h>

#define EIGEN_DEFAULT_TO_ROW_MAJOR
#include <unsupported/Eigen/CXX11/Tensor>
#include <Eigen/Eigen>


namespace ionizing {
  using namespace Eigen;

  static_assert(sizeof(size_t) == sizeof(uint64_t),
      "Uncompatible compiler: sizeof(size_t) != 8 !");
  static_assert(sizeof(double) == 8,
      "Uncompatible compiler: sizeof(double) != 8 !");
  static_assert(sizeof(float)  == 4,
      "Uncompatible compiler: sizeof( float) != 4 !");
  static_assert(sizeof(int)    == 4,
      "Uncompatible compiler: sizeof(   int) != 4 !");
  static_assert(sizeof(std::complex<double>) == 16, 
      "Uncompatible compiler: sizeof(complex<double>) != 16 !");
  static_assert(sizeof(std::complex< float>) ==  8, 
      "Uncompatible compiler: sizeof(complex< float>) !=  8 !");

// global type aliasing
  using Vecd   = VectorXd;
  using Veccd  = VectorXcd;
  using Matd   = Matrix<              double, Dynamic, Dynamic, RowMajor>;
  using Matcd  = Matrix<std::complex<double>, Dynamic, Dynamic, RowMajor>;
  using Cubd   = Tensor<              double,                3, RowMajor>;
  using Cubcd  = Tensor<std::complex<double>,                3, RowMajor>;
  using Mat33d = Matrix<double,                     3,       3, RowMajor>;
  using MatX3d = Matrix<double,               Dynamic,       3, RowMajor>;

  template <typename T>
    using MatT    = Matrix<T, Dynamic, Dynamic, RowMajor>;

  template <typename T>
    using ColVecT = Matrix<T, Dynamic,       1, RowMajor>;

  template <typename T>
    using RowVecT = Matrix<T,       1, Dynamic, RowMajor>;
  
static IOFormat CommaInitFmt{StreamPrecision, DontAlignCols, ", ", ", ", "", "", " << ", ";"};
static IOFormat CleanFmt{4, 0, ", ", "\n", "[", "]"};
static IOFormat OctaveFmt{StreamPrecision, 0, ", ", ";\n", "", "", "[", "]"};
static IOFormat HeavyFmt{FullPrecision, 0, ", ", ";\n", "[", "]", "[", "]"};
}

#endif // BASE_H
