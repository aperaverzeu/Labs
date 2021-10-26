#include <iostream>
#include <vector>

const long mod = 10000007;

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

int dfs(std::vector<std::vector<std::pair<int, int>>>& graph, int root, int node, long long& sum) {
    int tree_size = 1, i = 0;

    while (i < graph[node].size()) {
        int child = graph[node][i].first;
        int child_weight = graph[node][i].second;
        if (child != root) {
            long subtree_size = dfs(graph, node, child, sum);
            tree_size += subtree_size;
            sum += (2 * subtree_size * child_weight * (graph.size() - subtree_size));
            sum %= mod;
        }
        i++;
    }

    return tree_size;
}

void input(std::vector<std::vector<std::pair<int, int>>>& graph, int N) {
    for (int i = 0; i < N - 1; i++) {
        int A, B, C;
        read(A, B, C);
        graph[A - 1].push_back(std::make_pair(B - 1, C));
        graph[B - 1].push_back(std::make_pair(A - 1, C));
    }
}

int main() {
    int N;
    read(N);

    std::vector<std::vector<std::pair<int, int>>> graph(N, std::vector<std::pair<int, int>>());
    input(graph, N);

    long long sum = 0;
    int i = 0;
    while (i < graph[0].size()) {
        int child = graph[0][i].first;
        int child_weight = graph[0][i].second;
        long subtree_size = dfs(graph, 0, child, sum);
        sum += (2 * subtree_size * child_weight * (graph.size() - subtree_size));
        sum %= mod;
        i++;
    }

    write(sum);
    return 0;
}
