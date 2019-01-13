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

#include <unsupported/Eigen/CXX11/Tensor>
#include <Eigen/Eigen>


#define EIGEN_DEFAULT_TO_ROW_MAJOR

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
  using Matd   = Matrix<              double, Dynamic, Dynamic>;
  using Matcd  = Matrix<std::complex<double>, Dynamic, Dynamic>;
  using Cubd   = Tensor<              double,                3, RowMajor>;
  using Cubcd  = Tensor<std::complex<double>,                3, RowMajor>;
  using Mat33d = Matrix<double,                     3,       3>;
  using MatX3d = Matrix<double,               Dynamic,       3>;

  template <typename T>
    using MatT    = Matrix<T, Dynamic, Dynamic>;

  template <typename T>
    using ColVecT = Matrix<T, Dynamic,       1>;

  template <typename T>
    using RowVecT = Matrix<T,       1, Dynamic>;
  
}

#endif // BASE_H
