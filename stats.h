#pragma once
#include <vector>

double chi_square_test(const std::vector<double>& data, int bins);
double kolmogorov_smirnov_test(const std::vector<double>& data);
double serial_correlation(const std::vector<double>& data);
void print_histogram(const std::vector<double>& data, int bins);
