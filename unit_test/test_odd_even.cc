#include <fft.hpp>

using namespace ionizing;

void test(const int arraysize) {
  std::cout << "Initial ArraySize = " << arraysize << std::endl;
  Vecd vec{arraysize};
  vec.setRandom();
  std::cout << "Original array is \n" << vec << std::endl;
  Veccd vec_rfft = rfft_1d(vec);
  std::cout << "rfft of original array is \n" << vec_rfft << std::endl;

  std::cout << "\n\n\n" << std::endl;
}

void test_2d(const int cols) {
  std::cout << "Initial Array cols = " << cols << std::endl;
  Matd mat{6, cols};
  mat.setRandom();
  std::cout << "Original matrix is \n" << mat << std::endl;
  Matcd mat_fft  = fft_2d(mat);
  std::cout << "fft_2d of original matrix is \n" << mat_fft << std::endl;
  Matcd mat_rfft = rfft_2d(mat);
  std::cout << "rfft_2d of original matrix is \n" << mat_rfft << std::endl;
  std::cout << "\n\n\n" << std::endl;
}

int main(int argc, char* argv[]) {
  for (int i=2; i!=25; ++i) {
    test(i);
  }
  test(1);
  // test(0);


  for (int i=2; i!=6; ++i) {
    test_2d(i);
  }
  return 0;
}
