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

const long long int number = 1087388483;
const int first_simple_number  = 1021;
const int second_simple_number = 1031;
const int third_simple_number  = 1033;

const int firstSecond_simple_number = first_simple_number  * second_simple_number;
const int firstThird_simple_number  = first_simple_number  * third_simple_number;
const int secondThird_simple_number = second_simple_number * third_simple_number;

void print_result(bool exists) {
    write(exists ? "YES" : "NO");
}

int main() {
    int count;
    read(count);

    std::vector<int> v(count);

    for (int i = 0; i < count; i++) {
        read(v.at(i));
    }

    if (std::find(v.begin(), v.end(), number) != v.end()) {
        print_result(true);
        return 0;
    }

    if (std::find(v.begin(), v.end(), first_simple_number) != v.end() &&
        std::find(v.begin(), v.end(), secondThird_simple_number) != v.end()) {
        print_result(true);
        return 0;
    }

    if (std::find(v.begin(), v.end(), second_simple_number) != v.end() &&
        std::find(v.begin(), v.end(), firstThird_simple_number) != v.end()) {
        print_result(true);
        return 0;
    }

    if (std::find(v.begin(), v.end(), third_simple_number) != v.end() &&
        std::find(v.begin(), v.end(), firstSecond_simple_number) != v.end()) {
        print_result(true);
        return 0;
    }

    if (std::find(v.begin(), v.end(), first_simple_number) != v.end() &&
        std::find(v.begin(), v.end(), second_simple_number) != v.end() &&
        std::find(v.begin(), v.end(), third_simple_number) != v.end()) {
        print_result(true);
        return 0;
    }

    print_result(false);

    return 0;
}
