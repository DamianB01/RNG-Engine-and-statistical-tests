#include "rng.h"

LCG::LCG(unsigned int s) : engine(s) {}

double LCG::next() {
    return static_cast<double>(engine()) / (static_cast<double>(engine.max()) + 1.0);
}

MT19937::MT19937(unsigned int seed) : gen(seed), dist(0.0, 1.0) {}

double MT19937::next() {
    return dist(gen);
}
