#include <fft.hpp>

namespace ionizing {
  /*
   * using Vecd   = VectorXd;
   * using Veccd  = VectorXcd;
   * using Matd   = Matrix<              double, Dynamic, Dynamic>;
   * using Matcd  = Matrix<std::complex<double>, Dynamic, Dynamic>;
   * using Cubd   = Tensor<              double,                3, RowMajor>;
   * using Cubcd  = Tensor<std::complex<double>,                3, RowMajor>;
   * using Mat33d = Matrix<double,                     3,       3>;
   * using MatX3d = Matrix<double,               Dynamic,       3>;
   */

  Veccd fft_1d(const Veccd& vec){
    Veccd out(vec.size());
    auto plan = fftw_plan_dft_1d(vec.size(),
        (fftw_complex *)vec.data(), (fftw_complex *)out.data(),
        FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    return out;
  }

  Veccd fft_1d(const Vecd& vec){
    Veccd tmp = vec.cast<std::complex<double>>();
    // std::cout << __FUNCTION__ << ": tmp = \n" << tmp << std::endl;
    return fft_1d(tmp);
  }

  Veccd ifft_1d(const Veccd& vec) {
    Veccd out(vec.size());
    auto plan = fftw_plan_dft_1d(vec.size(),
        (fftw_complex *)vec.data(), (fftw_complex *)out.data(),
        FFTW_BACKWARD, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    out /= out.size();
    return out;
  }

  Veccd ifft_1d(const Vecd& vec){
    Veccd tmp = vec.cast<std::complex<double>>();
    // std::cout << __FUNCTION__ << ": tmp = \n" << tmp << std::endl;
    return ifft_1d(tmp);
  }


  Matcd  fft_2d(const Matcd& mat) {
    Matcd out(mat.rows(), mat.cols());
    auto plan = fftw_plan_dft_2d(mat.rows(), mat.cols(),
        (fftw_complex *)mat.data(), (fftw_complex *)out.data(),
        FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    return out;
  }



  Matcd  fft_2d(const  Matd& mat) {
    Matcd tmp = mat.cast<std::complex<double>>();
    // std::cout << __FUNCTION__ << ": tmp = \n" << tmp << std::endl;
    return fft_2d(tmp);
  }
  
  Matcd ifft_2d(const Matcd& mat) {
    Matcd out(mat.rows(), mat.cols());
    auto plan = fftw_plan_dft_2d(mat.rows(), mat.cols(),
        (fftw_complex *)mat.data(), (fftw_complex *)out.data(),
        FFTW_BACKWARD, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    out /= out.size();
    return out;
  }

  Matcd ifft_2d(const  Matd& mat) {
    Matcd tmp = mat.cast<std::complex<double>>();
    // std::cout << __FUNCTION__ << ": tmp = \n" << tmp << std::endl;
    return ifft_2d(tmp);
  }

  Cubcd  fft_3d(const Cubcd& cub) {
    Cubcd out(cub.dimension(0), cub.dimension(1), cub.dimension(2));
    auto plan = fftw_plan_dft_3d(
        cub.dimension(0), cub.dimension(1), cub.dimension(2), 
        (fftw_complex *)cub.data(), (fftw_complex *)out.data(),
        FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    return out;
  }

  Cubcd  fft_3d(const  Cubd& cub) {
    Cubcd tmp = cub.cast<std::complex<double>>();
    // std::cout << __FUNCTION__ << ": tmp = \n" << tmp << std::endl;
    return fft_3d(tmp);
  }

  Cubcd ifft_3d(const Cubcd& cub) {
    Cubcd out(cub.dimension(0), cub.dimension(1), cub.dimension(2));
    auto plan = fftw_plan_dft_3d(
        cub.dimension(0), cub.dimension(1), cub.dimension(2), 
        (fftw_complex *)cub.data(), (fftw_complex *)out.data(),
        FFTW_BACKWARD, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    // std::cout << __FUNCTION__ << "out.size() == " << out.size() << std::endl;
    out /= out.constant(out.size());
    return out;
  }

  Cubcd ifft_3d(const  Cubd& cub) {
    Cubcd tmp = cub.cast<std::complex<double>>();
    // std::cout << __FUNCTION__ << ": tmp = \n" << tmp << std::endl;
    return ifft_3d(tmp);
  }


}


/************************************************/
/************* For real numbers *****************/
/************************************************/

  /*
   * using Vecd   = VectorXd;
   * using Veccd  = VectorXcd;
   * using Matd   = Matrix<              double, Dynamic, Dynamic>;
   * using Matcd  = Matrix<std::complex<double>, Dynamic, Dynamic>;
   * using Cubd   = Tensor<              double,                3, RowMajor>;
   * using Cubcd  = Tensor<std::complex<double>,                3, RowMajor>;
   * using Mat33d = Matrix<double,                     3,       3>;
   * using MatX3d = Matrix<double,               Dynamic,       3>;
   */

namespace ionizing {

/*
 * For real to complex FFT, out array only need to have a
 * size of [in.size() / 2 + 1].
 *  in array shape: m
 * out array shape: m/2 + 1
 */
  Veccd rfft_1d(const Vecd& vec){
    Veccd out(vec.size() / 2 + 1);
    auto plan = fftw_plan_dft_r2c_1d(vec.size(),
        (double *)vec.data(), (fftw_complex *)out.data(),
        FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    return out;
  }

/*
 * fftw_c2r destroyes the original vector, so in this function
 * you cannot pass `const T& in`
 *  in array shape:  m
 * out array shape:  (m-1) * 2
 */
  Vecd irfft_1d(Vecd& vec) {
    if (vec.size() == 1) {
      std::cerr << std::endl << __FILE__ << ":" << __FUNCTION__ 
        << ": " << "size of input vector is 1" << std::endl;
      std::abort();
    }
    Vecd out(vec.size() * 2 - 2);
    auto plan = fftw_plan_dft_c2r_1d(vec.size(),
        (fftw_complex *)vec.data(), (double *)out.data(),
        FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    out /= out.size();
    return out;
  }



/*
 * For real to comlex 2D-FFT:
 *  in array shape:  m x n,
 * out array shape:  m x (n/2 + 1);
 */
  Matcd  rfft_2d(const Matd& mat) {
    Matcd out(mat.rows(), mat.cols() / 2 + 1);
    auto plan = fftw_plan_dft_r2c_2d(mat.rows(), mat.cols(),
        (double *)mat.data(), (fftw_complex *)out.data(),
        FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    return out;
  }
  
/*
 * fftw_c2r destroyes the original matrix, you cannot pass
 * `const T& in`
 *  in array shape: m x n
 * out array shape: m x ((n-1) * 2)
 */
  Matd irfft_2d(Matcd& mat) {
    if (mat.cols() == 1) {
      std::cerr << std::endl << __FILE__ << ":" << __LINE__ << ": "
        << "columns of input matrix is 1" << std::endl;
      std::abort();
    }
    Matd out(mat.rows(), mat.cols()*2 - 2);
    auto plan = fftw_plan_dft_c2r_2d(mat.rows(), mat.cols(),
        (fftw_complex *)mat.data(), (double *)out.data(),
        FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    out /= out.size();
    return out;
  }

/*
 * For real to comlex 3D-FFT:
 *  in array shape:  m x n x q,
 * out array shape:  m x n x (q/2 + 1);
 */
  Cubcd  rfft_3d(const Cubd& cub) {
    Cubcd out(cub.dimension(0), cub.dimension(1), cub.dimension(2) / 2 + 1);
    auto plan = fftw_plan_dft_r2c_3d(
        cub.dimension(0), cub.dimension(1), cub.dimension(2), 
        (double *)cub.data(), (fftw_complex *)out.data(),
        FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    return out;
  }

/*
 *  in array shape: m x n x q
 * out array shape: m x n x ((q-1) * 2)
 */
  Cubd irfft_3d(Cubcd& cub) {
    if (cub.dimension(2) == 1) {
      std::cerr << std::endl << __FILE__ << ":" << __FUNCTION__ << ": "
        << "third dimension of input cub is 1" << std::endl;
      std::abort();
    }
    Cubd out(cub.dimension(0), cub.dimension(1), cub.dimension(2)*2 - 2);
    auto plan = fftw_plan_dft_c2r_3d(
        cub.dimension(0), cub.dimension(1), cub.dimension(2), 
        (fftw_complex *)cub.data(), (double *)out.data(),
        FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    out /= out.constant(out.size());
    return out;
  }





}
