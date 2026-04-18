#include "csv.h"
#include <fstream>
#include <iostream>

void save_to_csv(const std::string& filename, const std::vector<double>& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file: " << filename << "\n";
        throw std::runtime_error("Cannot open file: " + filename);
    }
    file << "value\n";
    for (double x : data) {
        file << x << "\n";
    }
    file.close();
}
