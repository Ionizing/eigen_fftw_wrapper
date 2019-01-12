#pragma once
#ifndef FFT_H
#define FFT_H

#include <base.hpp>

namespace ionizing {
  // using Vecd   = VectorXd;
  // using Veccd  = VectorXcd;
  // using Matd   = Matrix<              double, Dynamic, Dynamic>;
  // using Matcd  = Matrix<std::complex<double>, Dynamic, Dynamic>;
  // using Cubd   = Tensor<              double,                3, RowMajor>;
  // using Cubcd  = Tensor<std::complex<double>,                3, RowMajor>;
  // using Mat33d = Matrix<double,                     3,       3>;
  // using MatX3d = Matrix<double,               Dynamic,       3>;

  Veccd  fft_1d(const Veccd& vec);
  Veccd  fft_1d(const  Vecd& vec);
  Veccd ifft_1d(const Veccd& vec);
  Veccd ifft_1d(const  Vecd& vec);

  Matcd  fft_2d(const Matcd& mat);
  Matcd  fft_2d(const  Matd& mat);
  Matcd ifft_2d(const Matcd& mat);
  Matcd ifft_2d(const  Matd& mat);

  Cubcd  fft_3d(const Cubcd& cub);
  Cubcd  fft_3d(const  Cubd& cub);
  Cubcd ifft_3d(const Cubcd& cub);
  Cubcd ifft_3d(const  Cubd& cub);

  Veccd  rfft_1d(const  Vecd& vec);
  Vecd  irfft_1d(       Veccd& vec);
           
  Matcd  rfft_2d(const  Matd& mat);
  Matd  irfft_2d(       Matcd& mat);
           
  Cubcd  rfft_3d(const  Cubd& cub);
  Cubd  irfft_3d(       Cubcd& cub);
}
#endif // FFT_H
