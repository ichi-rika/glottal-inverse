#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cstddef>

// Audio sample rate
#define SAMPLE_RATE 48000
#define FRAMES_PER_BUFFER 1024

// Vector basis
#define J 6

// Basis length
constexpr size_t basis_length() {
    // There are Sum[0..J] 2^j wavelets.
    // That's 2^(J+1) - 1 elements.
    // Add one for the constant scaling function.
    return 2 << (J + 1);
}
#define WINDOW_LENGTH (basis_length())

// AM-GIF max iter count
#define MAX_ITER 5

// GNUPlot data exporting
#define GNUPLOT_FILE_IAIF_SOURCE "iaif_source.dat"
#define GNUPLOT_FILE_IAIF_SOURCE_DERIV "iaif_source_deriv.dat"
#define GNUPLOT_FILE_AMGIF_SOURCE "amgif_source.dat"
#define GNUPLOT_FILE_AMGIF_DERIV "amgif_source_deriv.dat"

#endif // CONSTANTS_H
