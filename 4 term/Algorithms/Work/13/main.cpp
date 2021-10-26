#include <iostream>
#include <vector>

#define maxNodes 10001

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

void dfs(int node);

std::vector<int> graph[maxNodes];
bool checked[maxNodes];
int N, M;

int main() {
    read(N, M);

    for (int i = 0; i < M; i++) {
        int U, V;
        read(U, V);
        graph[U].push_back(V);
        graph[V].push_back(U);
    }

    bool is_connected = true;

    dfs(1);
    for (int i = 2; i < N; i++)
        if (!checked[i]) {
            is_connected = false;
        }

    write(is_connected ? M - N + 1 : -1);
    return 0;
}

void dfs(int node) {
    checked[node] = true;
    for (auto next : graph[node]) {
        if (!checked[next]) {
            dfs(next);
        }
    }
}
