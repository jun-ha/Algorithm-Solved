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
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;
using ll = long long;

int N;
int danji = 2;

pair<int, int> translate_to_row_col(int nodeNum) {
    return make_pair(nodeNum / N, nodeNum % N);
}

void bfs(vector<vector<int>>&graph, int row, int col) {
    if (graph[row][col] != 1) return;
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    graph[row][col] = danji;
    while (!q.empty()) {
        pair<int, int> idx = q.front();
        q.pop();
        int row = idx.first;
        int col = idx.second;
        if (row - 1 >= 0 && graph[row - 1][col] == 1) {
            q.push(make_pair(row - 1, col));
            graph[row - 1][col] = danji;
        }

        if (row + 1 < N && graph[row + 1][col] == 1) {
            q.push(make_pair(row + 1, col));
            graph[row + 1][col] = danji;
        }
        if (col - 1 >= 0 && graph[row][col - 1] == 1) {
            q.push(make_pair(row, col - 1));
            graph[row][col-1] = danji;
        }
        if (col + 1 < N && graph[row][col + 1] == 1) {
            q.push(make_pair(row, col + 1));
            graph[row][col + 1] = danji;
        }
    }
    danji++;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    vector<vector<int>>graph(N, vector<int>());
    rep(i, 0, N) {
        string line;
        cin >> line;
        rep(j, 0, N) {
            graph[i].push_back(line[j]-'0');
        }
    }
    rep(i, 0, N) {
        rep(j, 0, N) {
            bfs(graph, i, j);
        }
    }

    vector<int>count(500, 0);
    int danjiNum = 0;
    int max = -999;
    rep(i, 0, N) {
        rep(j, 0, N) {
            if (graph[i][j]) {
                count[graph[i][j]]++;
                if (max < graph[i][j]) max = graph[i][j];
            }
        }
    }
    sort(count.begin(), count.end(), less<>());
    cout << max - 1 << ENDL;
    for (auto x : count) {
        if (x) cout << x << ENDL;
    }
    return 0;
}