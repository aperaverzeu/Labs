#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<vector<long long>> lengths;

long long nodesCount;
long long sum = 0;
const long long module = 1e7 + 7;

int dfs(int node, int root){
    int countOfWays = 1;
    for (int i = 0; i < graph[node].size(); i++){
        int nextNode = graph[node][i];
        if (nextNode != root){
            long long countNext = dfs(nextNode, node);
            sum = (sum + (countNext * (nodesCount - countNext)
                          * lengths[node][nextNode] * 2)) % module;
            countOfWays += countNext;
        }
    }
    return countOfWays;
}

int main() {
    cin >> nodesCount;

    graph.assign(nodesCount + 1, vector<int>());
    lengths.assign(nodesCount + 1, vector<long long>(nodesCount + 1, 0));

    for (int i = 0; i < nodesCount - 1; i++){
        int firstNode, secondNode, length;
        cin >> firstNode >> secondNode >> length;
        graph[firstNode].push_back(secondNode);
        graph[secondNode].push_back(firstNode);
        lengths[firstNode][secondNode] = length;
    }

    dfs(1, 0);

    cout << sum;
    return 0;
}
