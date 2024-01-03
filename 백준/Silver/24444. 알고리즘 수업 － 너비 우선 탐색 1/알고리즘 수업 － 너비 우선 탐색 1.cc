#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define ENDL '\n'

using namespace std;
using ll = long long;

class Graph
{
public:
    int nodeNum;
    int edgeNum;
    int visitNum = 0;
    vector<int> visited;
    vector<vector<int>> node;


    Graph(int nodeNum, int edgeNum) : visited(nodeNum, 0), node(nodeNum, vector<int>())
    {
        this->nodeNum = nodeNum;
        this->edgeNum = edgeNum;
    }

    void insert_edge(int nodeNum1, int nodeNum2)
    {
        node[nodeNum1].push_back(nodeNum2);
        node[nodeNum2].push_back(nodeNum1);
    }

    void sort_node() {
        for (int i = 0; i < nodeNum; i++) {
            sort(node[i].begin(), node[i].end(), less<>());
        }
    }

    void dfs(int startNode) {
        stack<int> s;
        s.push(startNode);
        while (!s.empty()) {
            int nextNode = s.top();
            s.pop();
            if (visited[nextNode] != 0) continue;
            visited[nextNode] = ++visitNum;
            for (auto x : node[nextNode]) {
                if (visited[x] == 0) {
                    s.push(x);
                }
            }
        }
    }

    void bfs(int startNode) {
        queue<int> q;
        q.push(startNode);
        while (!q.empty()) {
            int nextNode = q.front();
            q.pop();
            if (visited[nextNode] != 0) continue;
            visited[nextNode] = ++visitNum;
            for (auto x : node[nextNode]) {
                if (visited[x] == 0) {
                    q.push(x);
                }
            }
        }
    }

    void show_visit_num() {
        for (auto x : visited) {
            cout << x << ENDL;
        }
    }
};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int nodeNum, edgeNum, startNode;
    cin >> nodeNum >> edgeNum >> startNode;
    Graph graph(nodeNum, edgeNum);
    for (int i = 0; i < edgeNum; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        graph.insert_edge(n1 - 1, n2 - 1);
    }
    graph.sort_node();
    graph.bfs(startNode - 1);
    graph.show_visit_num();
    return 0;
}