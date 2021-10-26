#include <iostream>
#include <vector>
#include <set>

void print_vector(const std::vector<int>& vector) {
    for (const auto& v : vector) {
        std::cout << v << " ";
    }
    std::cout << "\n";
}

void print_2D(const std::vector<std::vector<int>>& vector) {
    for (const auto& v : vector) {
        print_vector(v);
    }
    std::cout << "\n";
}

int N, M, I, J;

std::vector<std::pair<int, int>> steps;
std::vector<std::vector<int>> board;
std::vector<std::vector<bool>> was_here;

static const std::set<std::pair<int, int>> possible_moves = {
        std::make_pair(-2, 1),
        std::make_pair(-1, 2),
        std::make_pair(1, 2),
        std::make_pair(2, 1),
        std::make_pair(2, -1),
        std::make_pair(1, -2),
        std::make_pair(-1, -2),
        std::make_pair(-2, -1)
};

static const std::string impossible_move = "NEVAR";

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

std::vector<std::vector<int>> make_board(int m, int n) {
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < m; i++) {
        std::vector<int> tmp(n, 0);
        matrix.push_back(tmp);
    }
    return matrix;
}

std::vector<std::vector<bool>> make_was_here(int m, int n) {
    std::vector<std::vector<bool>> visited;
    for (int i = 0; i < m; i++) {
        std::vector<bool> tmp(n, false);
        visited.push_back(tmp);
    }
    return visited;
}

int main() {
    read(N, M, I, J);
    --I;
    --J;

    board = make_board(M, N);
    was_here = make_was_here(M, N);
    --M;
    --N;

    auto initial_position = std::make_pair(0, 0);
    steps.push_back(initial_position);

    was_here[initial_position.first][initial_position.second] = true;

    int qb = 0;
    while (qb != steps.size()) {
        for (auto s : possible_moves) {
            auto mb = std::make_pair(steps[qb].first + s.first, steps[qb].second + s.second);
            if (mb.first < 0 || mb.second < 0) {
                continue;
            }
            if (mb.first > M || mb.second > N) {
                continue;
            }
            if (was_here[mb.first][mb.second]) {
                continue;
            }
            steps.push_back(mb);
            board[mb.first][mb.second] = board[steps[qb].first][steps[qb].second] + 1;
            was_here[mb.first][mb.second] = true;
        }
        qb++;
    }

    for (const auto& q : steps) {
        std::cout << "(" << q.first << "," << q.second << ")\t";
    }
    std::cout << "\n";


    write(board[I][J] == 0 ? impossible_move : std::to_string(board[I][J]));

    return 0;
}
