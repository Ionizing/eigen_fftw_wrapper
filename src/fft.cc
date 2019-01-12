#include <fft.hpp>

namespace ionizing {
  // using Vecd   = VectorXd;
  // using Veccd  = VectorXcd;
  // using Matd   = Matrix<              double, Dynamic, Dynamic>;
  // using Matcd  = Matrix<std::complex<double>, Dynamic, Dynamic>;
  // using Cubd   = Tensor<              double,                3, RowMajor>;
  // using Cubcd  = Tensor<std::complex<double>,                3, RowMajor>;
  // using Mat33d = Matrix<double,                     3,       3>;
  // using MatX3d = Matrix<double,               Dynamic,       3>;

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


namespace ionizing {



  Veccd rfft_1d(const Vecd& vec){
    Veccd out(vec.size());
    auto plan = fftw_plan_dft_r2c_1d(vec.size(),
        (double *)vec.data(), (fftw_complex *)out.data(),
        FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    return out;
  }

  Vecd irfft_1d(Vecd& vec) {
    Vecd out(vec.size());
    auto plan = fftw_plan_dft_c2r_1d(vec.size(),
        (fftw_complex *)vec.data(), (double *)out.data(),
        FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    out /= out.size();
    return out;
  }

  Matcd  rfft_2d(const Matd& mat) {
    Matcd out(mat.rows(), mat.cols());
    auto plan = fftw_plan_dft_r2c_2d(mat.rows(), mat.cols(),
        (double *)mat.data(), (fftw_complex *)out.data(),
        FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    return out;
  }
  
  Matd irfft_2d(Matcd& mat) {
    Matd out(mat.rows(), mat.cols());
    auto plan = fftw_plan_dft_c2r_2d(mat.rows(), mat.cols(),
        (fftw_complex *)mat.data(), (double *)out.data(),
        FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    out /= out.size();
    return out;
  }

  Cubcd  rfft_3d(const Cubd& cub) {
    Cubcd out(cub.dimension(0), cub.dimension(1), cub.dimension(2));
    auto plan = fftw_plan_dft_r2c_3d(
        cub.dimension(0), cub.dimension(1), cub.dimension(2), 
        (double *)cub.data(), (fftw_complex *)out.data(),
        FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    return out;
  }

  Cubd irfft_3d(Cubcd& cub) {
    Cubd out(cub.dimension(0), cub.dimension(1), cub.dimension(2));
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
