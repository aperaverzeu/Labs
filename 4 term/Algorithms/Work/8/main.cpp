#include <iostream>
#include <string>

template<typename... T>
void read(T&... args) {
    ((std::cin >> args), ...);
}

template<typename... T>
void write(T... args) {
    ((std::cout << args << " "), ...);
}

int main() {
    std::string input;
    read(input);
    int input_length = static_cast<int>(input.length());
    bool is_repeat = true;
    for (int i = 0, j = input_length - 1; i <= j; i++, j--) {
        if (input[i] != input[j]) {
            write(input.length());
            return 0;
        }
        if (is_repeat && input[i] != input[0]) {
            is_repeat = false;
        }
    }

    write(is_repeat ? -1 : input_length - 1);
    return 0;
}
