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

void merge(std::vector<int> sequence, size_t left, size_t right, size_t center, u_long* inverse_count) {
    std::vector<int> tmp(right - left + 1);

    size_t i = left, j = center + 1, k = 0;
    while (i <= center && j <= right) {
        tmp[k] = std::min(sequence[i], sequence[j]);
        if (std::min(sequence[i], sequence[j]) == sequence[i]) {
            i++;
        } else {
            j++;
            *inverse_count += (center - i + 1);
        }
        k++;
    }

    if (i > center) {
        while (j <= right) {
            tmp[k] = sequence[j];
            j++;
            k++;
        }
    } else {
        while (i <= center) {
            tmp[k] = sequence[i];
            i++;
            k++;
        }
    }

    for (size_t l = left, in = 0; i <= right; i++, in++) {
        sequence[l] = tmp[in];
    }
}

void merge_sort(std::vector<int> sequence, size_t left, size_t right, u_long* inverse_count) {
    if (left < right) {
        size_t center = left + (right - left) / 2;
        merge_sort(sequence, left, center, inverse_count);
        merge_sort(sequence, center + 1, right, inverse_count);
        merge(sequence, left, right, center, inverse_count);
    }
}

std::vector<int> read_vector(size_t length) {
    std::vector<int> sequence(length);
    for (auto i = 0; i < length; i++) {
        read(sequence[i]);
    }
    return sequence;
}

int main() {
    u_long inverse_count = 0;
    int length = 0;
    read(length);

    auto sequence = read_vector(length);

    merge_sort(sequence, 0, length - 1, &inverse_count);
    write(inverse_count);
    return 0;
}
