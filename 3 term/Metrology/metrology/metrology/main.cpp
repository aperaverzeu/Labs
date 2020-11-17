#include <iostream>
#include <random>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <thread>
#include <utility>
#include <vector>

// unused random generator
struct GaussGenerator {
    GaussGenerator(double mean, double stddev, std::uint32_t seed)
    : engine_(seed), distribution_(mean, stddev) {}
    
    GaussGenerator(double mean, double stddev)
    : distribution_(mean, stddev) {
        std::seed_seq seeds {
            (uint64_t)std::chrono::high_resolution_clock::now().time_since_epoch().count(),
            (uint64_t)std::chrono::system_clock::now().time_since_epoch().count(),
            (uint64_t)std::hash<std::thread::id>{}(std::this_thread::get_id()),
        };
        engine_.seed(seeds);
    }
    
    double operator()() { return distribution_(engine_); }
    
    std::mt19937 engine_;
    std::normal_distribution<double> distribution_;
};

void print(std::vector<int> &input) {
    for (int i = 0; i < input.size(); ++i) {
        std::cout << "[" << i << "] element of collection is " << input[i] << std::endl;
    }
    std::cout << std::endl; // Gap
}


int main(int argc, const char * argv[]) {
    
    uint64_t counter = 0;
    const uint64_t arraySize = 8;
    std::vector<int> A,B,C, BElements;
    GaussGenerator rand(1, 100);
    
    // initialization A&B'collections
    for (int i = 0; i < arraySize; i++) {
        A.push_back(rand());
        B.push_back(rand());
    }
    std::cout << std::endl; // Gap
    
    // count minimum value of element of collection
    for (int i = 0; i < arraySize; i++) {
        C.push_back(std::min(4*A[i], B[i]*B[i]));
        if ((int)sqrt(C[i]) == B[i]) {
            BElements.push_back(B[i]);
            counter++;
        }
    }
    
    std::cout << "A'collection:" << std::endl; // Gap
    print(A);
    
    std::cout << "B'collection:" << std::endl; // Gap
    print(B);
    
    std::cout << "C'collection:" << std::endl; // Gap
    print(C);
    
    std::cout << std::endl; // Gap
    std::cout << "Number of B'elements of C'collection is " << counter << std::endl;
    print(BElements);
    
    return 0;
}
