#include "stats.h"
#include <cmath>
#include <iostream>
#include <algorithm>

double chi_square_test(const std::vector<double>& data, int bins) {
    std::vector<int> counts(bins, 0);

    for (double x : data) {
        int idx = std::min((int)(x * bins), bins - 1);
        counts[idx]++;
    }

    double expected = data.size() / (double)bins;
    double chi2 = 0;

    for (int c : counts) {
        chi2 += (c - expected) * (c - expected) / expected;
    }

    return chi2;
}

double kolmogorov_smirnov_test(const std::vector<double>& data) {
    std::vector<double> sorted = data;
    std::sort(sorted.begin(), sorted.end());
    int n = sorted.size();
    double D = 0.0;
    for (int i = 0; i < n; i++) {
        double F_emp = (i + 1) / (double)n;
        double F_theo = sorted[i];

        D = std::max(D, std::abs(F_emp - F_theo));
    }

    return D;
}

double serial_correlation(const std::vector<double>& data) {
    int n = data.size();
    double mean = 0;
    for (double x : data) mean += x;
    mean /= n;
    double num = 0, den = 0;
    for (int i = 0; i < n - 1; i++) {
        num += (data[i] - mean) * (data[i + 1] - mean);
    }

    for (double x : data) {
        den += (x - mean) * (x - mean);
    }

    return num / den;
}

void print_histogram(const std::vector<double>& data, int bins) {
    int width = 100;
    std::vector<int> counts(bins, 0);
    for (double x : data) {
        int idx = std::min((int)(x * bins), bins - 1);
        counts[idx]++;
    }

    int max_count = *std::max_element(counts.begin(), counts.end());
    for (int i = 0; i < bins; i++) {
        int bar_len = (int)((double)counts[i] / max_count * width);
        std::cout << i << ": ";
        for (int j = 0; j < bar_len; j++)
            std::cout << "*";
        std::cout << " (" << counts[i] << ")\n";
    }
}
