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

const auto max_length = 10001;
std::vector<int> graph[max_length];
bool is_checked[max_length];
auto components = 0;

void dfs(const int& n) {
    is_checked[n] = true;
    for (auto v : graph[n]) {
        if (!is_checked[v]) {
            dfs(v);
        }
    }
}

void enter_graph(const int& M) {
    for (int i = 0; i < M; i++) {
        int U, V;
        read(U, V);
        graph[U].push_back(V);
        graph[V].push_back(U);
    }
}

void min_q_to_be_con(const int& N) {
    for (int i = 1; i <= N; i++) {
        if (!is_checked[i]) {
            dfs(i);
            components++;
        }
    }
}

int main() {
    int N, M;
    read(N, M);
    enter_graph(M);
    min_q_to_be_con(N);
    write(components - 1);
    return 0;
}
