#include <iostream>
#include <algorithm>
#include <string>
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
    int quantity = 0;

    std::string s;
    read(s);

    int size = static_cast<int>(s.size());
    std::vector<int> prefix(1 + size);

    for (int i = 0; i < size; i++) {
        prefix[1] = 0;
        int len = 0;
        int max = 0;
        for (int j = 1; j < size; j++) {
            while (true) {
                if (s[j] == s[len]) {
                    len++;
                    break;
                }
                if (len == 0) {
                    break;
                }
                len = prefix[len];
            }
            prefix[j + 1] = len;
            max = std::max(max, len);
        }
        quantity += static_cast<int>(s.size()) - max;
        s.erase(s.begin());
    }
    write(quantity);
    return 0;
}
