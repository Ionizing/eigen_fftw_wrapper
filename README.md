# Self-implemented fftw3 wrapper for Eigen3

# Dependencies
- Eigen3
- FFTW3
- CXX11 support

# Test standard

Numpy results

# Achieved
- 1D/2D/3D Complex FFT(forward & backward);
- 1D/2D/3D Real to Complex FFT (fftw_forward);
- 1D Complex to Real FFT (fftw_backward).

# Tips:

- if an array have even elements, the `fft`/`rfft` of it ends with
a real number (i.e. Im(num) == 0)

# TODO

- Fix 2D/3D Complex to Real FFT (fftw_backward) issues.
