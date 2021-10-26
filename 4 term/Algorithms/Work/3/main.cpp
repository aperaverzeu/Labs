#include <iostream>
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

const long long mod = 1e10+7;
const long long N = 100000;

long long mod_mul(long long a, long long b){
    return ((a % mod) * (b % mod)) % mod;
}

int main() {
    int quantity, k;
    long long result = 1;
    read(quantity, k);
    long long nums [N];
    for (int i = 0; i < quantity; i++) {
        read(nums[i]);
    }

    std::sort(nums, nums + quantity);

    if (nums[0] >= 0) {
        for (int i = quantity - 1; i > quantity - k - 1; i--) {
            result = mod_mul(result, nums[i]);
        }
    } else if (nums[quantity - 1] <= 0) {
        if (k % 2 == 0) {
            for (int i = 0; i > k; i++) {
                result = mod_mul(result, nums[i]);
            }
        } else {
            for (int i = quantity - 1; i > quantity - k - 1; i--) {
                result = mod_mul(result, nums[i]);
            }
        }
    } else {
        int left = 0, right = quantity - 1;
        while (k > 0) {
            if (k > 1 && (nums[left] * nums[left + 1]) >= (nums[right] * nums[right - 1])) {
                result = mod_mul(result, mod_mul(nums[left], nums[left + 1]));
                left += 2;
                k -= 2;
            } else {
                result = mod_mul(result, nums[right]);
                right--;
                k--;
            }
        }
    }

    result = (result + mod) % mod;
    write(result);
    return 0;
}
