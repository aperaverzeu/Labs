#include <iostream>
#include <vector>
#include <string>
#include <cctype>

template<typename... T>
void read(T&... args) {
    ((std::cin >> args), ...);
}

template<typename... T>
void write(T... args) {
    ((std::cout << args << " "), ...);
}

int main() {
    std::string S;
    read(S);

    std::vector<int> inv(S.length() + 1, 0);

    int Q;
    read(Q);

    for (int i = 0; i < Q; i++) {
        int L, R;
        read(L, R);
        if (R < L) {
            std::swap(L, R);
        }
        inv[L - 1]++;
        inv[R]--;
    }

    for (int i = 1; i < inv.size(); i++) {
        inv[i] += inv[i - 1];
    }

    for (int i = 0; i < S.length(); i++) {
        if (inv[i] % 2 == 1) {
            if (static_cast<bool>(std::isupper(S[i]))) {
                S[i] = static_cast<char>(std::tolower(S[i]));
            } else {
                S[i] = static_cast<char>(std::toupper(S[i]));
            }
        }
    }

    write(S);
    return 0;
}
