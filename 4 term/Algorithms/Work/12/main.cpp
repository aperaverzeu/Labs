#include <iostream>
#include <string>

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
    std::string number;
    read(number);
    if (number[number.length() - 1] == '0') {
        write("NO");
    } else {
        write(number[number.length() - 1]);
    }
    return 0;
}
