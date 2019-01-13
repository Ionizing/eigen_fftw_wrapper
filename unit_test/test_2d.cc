#include <fft.hpp>

using namespace ionizing;

void test(const Matd mat) {
  std::cout << "Original Matrix is \n" << mat.format(HeavyFmt) << std::endl;
  Matcd mat_fft = fft_2d(mat);
  std::cout << "fft of mat is \n" << mat_fft.format(HeavyFmt) << std::endl;
  Matcd mat_rfft = rfft_2d(mat);
  std::cout << "rfft of mat is \n" << mat_rfft.format(HeavyFmt) << std::endl;

  Matcd mat_ifft = ifft_2d(mat_fft);
  std::cout << "ifft of mat_fft is \n" << mat_ifft.real().format(HeavyFmt) << std::endl;

  Matd mat_irfft = irfft_2d(mat_rfft);
  std::cout << "irfft of mat_rfft is \n" << mat_irfft.format(HeavyFmt) << std::endl;
}

int main(int argc, char* argv[]) {
  Matd mat{6, 4};
  for (int i=0; i!=mat.rows(); ++i) {
    for (int j=0; j!=mat.cols(); ++j) {
      mat(i,j) = i * mat.cols() + j;
    }
  }

  std::cout << "------------ First Test ------------" << std::endl;
  test(mat);

  Matd mat2(6,3);
  for (int i=0; i!=mat2.rows(); ++i) {
    for (int j=0; j!=mat2.cols(); ++j) {
      mat2(i,j) = i * mat2.cols() + j;
    }
  }
  std::cout << "------------ Second Test ------------" << std::endl;
  test(mat2);

  
  Matd mat3(6,5);
  for (int i=0; i!=mat3.rows(); ++i) {
    for (int j=0; j!=mat3.cols(); ++j) {
      mat3(i,j) = i * mat3.cols() + j;
    }
  }
  std::cout << "------------ Third Test ------------" << std::endl;
  test(mat3);
  return 0;
}
