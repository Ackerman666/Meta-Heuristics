#include <iostream>
#include <random>
#include <cmath>



// Function to generate a random number using a normal distribution
double inline static normalRandom(double mean, double stddev) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(mean, stddev);
    return d(gen);
}

// Function to generate a step size for Levy flight
double inline levy_flight(double beta) {
    // Levy distribution parameters
    double sigma_u = pow((tgamma(1 + beta) * sin(M_PI * beta / 2)) / (tgamma((1 + beta) / 2) * pow(beta, (beta - 1) / 2)), 1 / beta);
    double sigma_v = 1.0;

    // Generate u and v
    double u = normalRandom(0, sigma_u);
    double v = normalRandom(0, sigma_v);

    // Generate step size
    //double step = u / pow(fabs(v), 1 / beta);
    return u / pow(fabs(v), 1 / beta);

}