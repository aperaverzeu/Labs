#include <iostream>

/*
 * This is some custom funcs read, write, more in future
 * This is new abilities of C++17,
 * and this tricks can help me and my code to be original
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
    int year;
    read(year);
    write((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? "YES" : "NO");
    return 0;
}
