#include <matplotlibcpp.h>
#include <vector>
#include <cmath>
#include <iostream>

namespace plt = matplotlibcpp;

int main() {
    // Constants for the lift equation
    double rho = 1.225; // Air density at sea level (kg/m³)
    double S = 20.0;    // Wing area (m²)
    double CL = 0.5;    // Lift coefficient (dimensionless)

    // Define velocity range
    std::vector<double> velocities;
    std::vector<double> lift;

    for (double v = 0; v <= 100; v += 1) {
        velocities.push_back(v);
        // Compute lift force
        double L = 0.5 * rho * v * v * S * CL;
        lift.push_back(L);
    }

    // Plot
    plt::figure_size(800, 600);
    plt::plot(velocities, lift, "b-");
    plt::title("Lift vs. Velocity");
    plt::xlabel("Velocity (m/s)");
    plt::ylabel("Lift (N)");
    plt::grid(true);
    plt::show();

    return 0;
}
