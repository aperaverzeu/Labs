#include <iostream>

template<typename... T>
void read(T&... args) {
    ((std::cin >> args), ...);
}

template<typename... T>
void write(T... args) {
    ((std::cout << args << " "), ...);
}

int main() {
    int m, n, x1, y1, x2, y2;
    read(m, n, x1, y1, x2, y2);
    write(abs(x1 - x2) == abs(y1 - y2) ? "NO" : "YES");
    return 0;
}
