// include/gs.h

#ifndef GS_H
#define GS_H

#include <vector>

// Declare simulation parameters
extern const int width;
extern const int height;
extern double Du;
extern double Dv;
extern double F;
extern double k;
extern double threshold;
extern const double dt;
extern const int numIterations;
extern const int outputInterval;

// Declare grid and constants
extern std::vector<std::vector<double>> u;
extern std::vector<std::vector<double>> v;

// Initialization function
void init();

// Function to write the u array to a VTK file
void writeVTKFile(int iteration);

// Function to perform one time step of the simulation
void simulateStep();

// Function to count elements above a threshold in a 2D vector
double countElementsAboveThreshold(double threshold);

#endif // GS_H
