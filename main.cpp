#include <iostream>
#include <vector>
#include <chrono>
#include "rng.h"
#include "stats.h"
#include "csv.h"

const int N = 1000000;

template<typename RNGType> std::vector<double> generate(RNGType& rng) {
    std::vector<double> data;
    data.reserve(N);

    for (int i = 0; i < N; i++) {
        data.push_back(rng.next());
    }

    return data;
}

template<typename RNGType> void benchmark(RNGType& rng, const std::string& name) {
    auto start = std::chrono::high_resolution_clock::now();
    auto data = generate(rng);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    std::cout<<"\n=== "<<name<<" ===\n";
    std::cout<<"Time: "<<diff.count()<<"s\n";
    std::cout<<"Chi-square: "<<chi_square_test(data, 10)<<"\n";
    std::cout<<"Kolmogorov-Smirnov test: "<<kolmogorov_smirnov_test(data)<<"\n";
    std::cout<<"Serial correlation: "<<serial_correlation(data)<<"\n";
    std::cout<<"\nHistogram:\n";
    print_histogram(data, 10);

    std::string filename = name + "_data.csv";
    save_to_csv(filename, data);
}

int main() {
    LCG lcg(12345);
    MT19937 mt(12345);
    benchmark(lcg, "LCG");
    benchmark(mt, "MT19937");
    return 0;
}
