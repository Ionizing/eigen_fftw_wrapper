#include <fft.hpp>

using namespace ionizing;

IOFormat CommaInitFmt{StreamPrecision, DontAlignCols, ", ", ", ", "", "", " << ", ";"};
IOFormat CleanFmt{4, 0, ", ", "\n", "[", "]"};
IOFormat OctaveFmt{StreamPrecision, 0, ", ", ";\n", "", "", "[", "]"};
IOFormat HeavyFmt{FullPrecision, 0, ", ", ";\n", "[", "]", "[", "]"};
std::string sep("\n-----------------------------------------\n");

void test(const int dim1, const int dim2, const int dim3) {
  Cubd in(dim1, dim2, dim3);
  in.setRandom();

  Cubcd out = fft_3d(in);
  Cubcd out_rfft = rfft_3d(in);
  
  Cubcd out_ifft = ifft_3d(out);
  Cubd out_irfft = irfft_3d(out_rfft);

  std::cout << sep;
  std::cout << "Original Cube is\n" << in << std::endl;
  std::cout << sep;
  std::cout << "fft of cube is\n" << out << std::endl;
  std::cout << sep;
  std::cout << "rfft of cube is\n" << out_rfft << std::endl;
  std::cout << sep;
  std::cout << "ifft of cube is\n" << out_ifft.real() << std::endl;
  std::cout << sep;
  std::cout << "irfft of cube is\n" << out_irfft << std::endl;
  std::cout << sep;
  std::cout << std::endl << std::endl;
}

int main(int argc, char* argv[]) {
  test(2, 3, 4);
  test(2, 3, 5);
  test(2, 4, 4);
  test(2, 4, 5);
  test(3, 3, 4);
  test(3, 3, 5);
  test(3, 4, 4);
  test(3, 4, 5);
  return 0;
}
