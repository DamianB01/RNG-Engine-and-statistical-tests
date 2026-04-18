#pragma once
#include <random>
#include <cstdint>

class LCG {
private:
    std::linear_congruential_engine<uint32_t, 1664525, 1013904223, 0> engine;
public:
    LCG(unsigned int s);
    double next();
};

class MT19937 {
private:
    std::mt19937 gen;
    std::uniform_real_distribution<double> dist;
public:
    MT19937(unsigned int seed);
    double next();
};
