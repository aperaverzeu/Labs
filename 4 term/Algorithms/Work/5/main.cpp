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

std::vector<std::vector<std::pair<int, long>>> graph;

int main() {
    int N, M, A, B;
    long C;
    read(N, M);

    bool was_here[N];
    long roads[N];

    for (int i = 0; i < N; i++) {
        was_here[i] = false;
        roads[i] = 100000000000;
        graph.emplace_back();
    }

    for (int i = 0; i < M; i++) {
        read(A, B, C);
        graph[A - 1].push_back(std::make_pair(B - 1, C));
        graph[B - 1].push_back(std::make_pair(A - 1, C));
    }

    int start, end;
    read(start, end);
    start--; end--;
    roads[start] = 0;

    int i = 0;
    while (i < N) {
        int min_vertex = -1;

        for (int k = 0; k < N; k++) {
            if (!was_here[k] && (min_vertex == -1 || roads[k] < roads[min_vertex])) {
                min_vertex = k;
            }
        }

        for (int k = 0; k < graph[min_vertex].size(); k++) {
            int vertex = std::get<0>(graph[min_vertex][k]);
            long weight = std::get<1>(graph[min_vertex][k]);

            if (roads[min_vertex] + weight < roads[vertex]) {
                roads[vertex] = roads[min_vertex] + weight;
            }
        }
        was_here[min_vertex] = true;
        i++;
    }
    write(roads[end]);
    return 0;
}
