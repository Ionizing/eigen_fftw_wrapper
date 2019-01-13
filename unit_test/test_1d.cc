#include <fft.hpp>

using namespace ionizing;

void test1() {
  std::cout << "--------------- First Test --------------" << std::endl;
  IOFormat HeavyFmt(5, 0, ", ", ";\n", "[", "]", "[", "]");

  std::cout << "Testing 1D-FFT..." << std::endl;

  Vecd vec{24};
  for (int i=0; i!=vec.size(); ++i) {
    vec(i) = i + .0;
  }
  std::cout << "vec = \n" << vec.format(HeavyFmt) << std::endl;

  Veccd vec_fft = fft_1d(vec);
  std::cout << "fft_1d(vec) = \n" << vec_fft.format(HeavyFmt) 
    << std::endl << std::endl;

  Veccd vec_ifft = ifft_1d(vec_fft);
  std::cout << "ifft_1d(vec_fft) = \n" << vec_ifft.real().format(HeavyFmt)
    << std::endl << std::endl;

  Veccd vec_rfft = rfft_1d(vec);
  std::cout << "rfft_1d(vec) = \n" << vec_rfft.format(HeavyFmt)
    << std::endl << std::endl; 

  Vecd vec_irfft = irfft_1d(vec_rfft);
  std::cout << "irfft_1d(vec_rfft) = \n" << vec_irfft.format(HeavyFmt)
    << std::endl << std::endl;
}

void test2() {
  std::cout << "--------------- Second Test --------------" << std::endl;
  IOFormat HeavyFmt(5, 0, ", ", ";\n", "[", "]", "[", "]");

  std::cout << "Testing 1D-FFT..." << std::endl;

  Vecd vec{23};
  for (int i=0; i!=vec.size(); ++i) {
    vec(i) = i + .0;
  }
  std::cout << "vec = \n" << vec.format(HeavyFmt) << std::endl;

  Veccd vec_fft = fft_1d(vec);
  std::cout << "fft_1d(vec) = \n" << vec_fft.format(HeavyFmt) 
    << std::endl << std::endl;

  Veccd vec_ifft = ifft_1d(vec_fft);
  std::cout << "ifft_1d(vec_fft) = \n" << vec_ifft.real().format(HeavyFmt)
    << std::endl << std::endl;

  Veccd vec_rfft = rfft_1d(vec);
  std::cout << "rfft_1d(vec) = \n" << vec_rfft.format(HeavyFmt)
    << std::endl << std::endl; 

  Vecd vec_irfft = irfft_1d(vec_rfft);
  std::cout << "irfft_1d(vec_rfft) = \n" << vec_irfft.format(HeavyFmt)
    << std::endl << std::endl;
}


int main(int argc, char* argv[]) {
  test1();
  test2();
  return 0;
}
