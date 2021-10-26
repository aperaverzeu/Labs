#include <iostream>

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
    int minimum_sum = 0;

    int sequence_length, previous_number;
    read(sequence_length, previous_number);

    int max_value = previous_number;
    for (int i = 1; i < sequence_length; i++) {
        int number;
        read(number);
        if (number > max_value) {
            minimum_sum += (number - max_value);
            max_value = number;
        }
        else {
            if (number < previous_number) {
                minimum_sum += (previous_number - number);
            }
        }
        previous_number = number;
    }

    write(minimum_sum);
    return 0;
}
