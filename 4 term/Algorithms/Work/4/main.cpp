#include <iostream>
#include <vector>
#include <map>
#include <queue>

template<typename... T>
void read(T&... args) {
    ((std::cin >> args), ...);
}

template<typename... T>
void write(T... args) {
    ((std::cout << args << " "), ...);
}

struct coordinates {
    int x;
    int y;

    bool operator < (const coordinates& other) const{
        if(x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }
};

const int TABLE_SIZE = 102;
std::map<coordinates, std::vector<coordinates>> graphOfMoves;
bool isSquarePossible[TABLE_SIZE][TABLE_SIZE];
bool isVisited[TABLE_SIZE][TABLE_SIZE];
int numOfMoves[TABLE_SIZE][TABLE_SIZE];
int rowsNum, columnsNum, finalRowNum, finalColumnNum;

void addPossibleSquares(coordinates square){
    std::vector<coordinates> possibleMoves;
    isSquarePossible[square.x][square.y] = true;

    for (int i = -2; i < 3; i++) {
        for (int j = -2; j < 3; j++) {
            if (i == 0 || j == 0 || (abs(i) == 2 && abs(j) == 2) || (abs(i) == 1 && abs(j) == 1)) {
                continue;
            }
            if (square.x + j <= rowsNum && 1 <= square.x + j && square.y + i <= columnsNum && 1 <= square.y + i) {
                possibleMoves.push_back(coordinates{square.x + j, square.y + i});
            }
        }
    }

    graphOfMoves.insert(std::pair<coordinates, std::vector<coordinates>> (square, possibleMoves));

    for (auto & possibleMove : possibleMoves) {
        if (!isSquarePossible[possibleMove.x][possibleMove.y]) {
            addPossibleSquares(possibleMove);
        }
    }
}

void bfs(coordinates square){
    isVisited[square.x][square.y] = true;
    std::queue<coordinates> moves;
    moves.push(square);
    while (!moves.empty()) {
        coordinates from = moves.front();
        moves.pop();
        std::vector<coordinates> c = graphOfMoves[from];
        for (auto to : c) {
            if (!isVisited[to.x][to.y]) {
                isVisited[to.x][to.y] = true;
                moves.push(to);
                numOfMoves[to.x][to.y] = numOfMoves[from.x][from.y] + 1;
            }
        }
    }
}

void enter() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            isSquarePossible[i][j] = false;
            isVisited[i][j] = false;
            numOfMoves[i][j] = 0;
        }
    }
}


int main() {
    read(rowsNum, columnsNum, finalRowNum, finalColumnNum);

    enter();

    coordinates firstSquare = {1, 1};
    addPossibleSquares(firstSquare);

    if(!isSquarePossible[finalRowNum][finalColumnNum]){
        write("NEVAR");
        return 0;
    }

    bfs(firstSquare);
    write(numOfMoves[finalRowNum][finalColumnNum]);
    return 0;
}
