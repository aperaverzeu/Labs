#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

/*
 * This is some custom funcs read, write, more in future
 * This is new abilities of C++17,
 * and this tricks can help me and my code to be original
 * Alaksiej Pieravierzieǔ, 2021
 */

template<typename... T>
void read(T&... args) {
    ((std::cin >> args), ...);
}

template<typename... T>
void write(T... args) {
    ((std::cout << args << " "), ...);
}

bool isOneDigit(long number) {
    return number % 10 == number;
}

std::vector<long> toArray(long number) {
    std::vector<long> array;
    do {
        array.push_back(number % 10);
        number /= 10;
    } while (number != 0);
    return array;
}

long toNumber(const std::vector<long>& array) {
    std::string number;
    for (auto a : array) {
        number += std::to_string(a);
    }
    return std::stoi(number);
}

int main() {
    long number;
    read(number);

    if (isOneDigit(number)) {
        write(-1);
        return 0;
    }

    std::vector<long> numbers = toArray(number);

    std::vector<std::pair<long, long>> variants;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            if (numbers.at(i) > numbers.at(j)) {
                variants.emplace_back(i, j);
                break;
            }
        }
    }

    if (variants.empty()) {
        write(-1);
        return 0;
    }

    std::sort(variants.begin(), variants.end(),[](std::pair<long, long> a,std::pair<long, long> b) {
        return a.second < b.second;
    });

    std::vector<long> j_variants;
    for (auto variant : variants) {
        if (variant.second == variants.at(0).second) {
            j_variants.push_back(variant.first);
        }
    }

    std::vector<long> elements;
    elements.reserve(j_variants.size());
    for (auto j_variant : j_variants) {
        elements.push_back(numbers.at(j_variant));
    }

    std::swap(numbers.at(variants.at(0).second),
              numbers.at(j_variants.at(std::distance(elements.begin(),std::min_element(elements.begin(), elements.end())))));

    std::vector<long> s;
    s.reserve(variants.at(0).second);
    for (int i = 0; i < variants.at(0).second; i++) {
        s.push_back(numbers.at(i));
    }

    std::sort(s.begin(), s.end());
    std::reverse(s.begin(), s.end());

    for (int i = 0; i < variants.at(0).second; i++) {
        numbers.at(i) = s.at(i);
    }

    std::reverse(numbers.begin(), numbers.end());
    write(toNumber(numbers));

    return 0;
}
