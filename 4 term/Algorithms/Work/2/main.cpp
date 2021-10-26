#include <iostream>
#include <vector>

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

int main() {
    unsigned int length = 0;
    std::vector<long long int> sequence;

    read(length);

    for (int i = 0; i < length; i++) {
        long long int temp = 0;
        read(temp);
        sequence.push_back(temp);
    }

    std::sort(sequence.begin(), sequence.end());

//    for (auto i : sequence) {
//        write(i);
//    }
//    std::cout << std::endl;

    long long int result = sequence.at(sequence.size() - 1) * sequence.at(sequence.size()-2);
    long long int negResult = sequence.at(0) * sequence.at(1);

    write(result > negResult ? result : negResult);

    return 0;
}
