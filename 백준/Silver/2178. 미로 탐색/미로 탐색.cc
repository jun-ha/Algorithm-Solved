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

int N, M;
int shortest = 99999;

void bfs(vector<vector<int>>& graph, int destRow, int destCol) {
	queue< pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(0, 0), 1));
	while (!q.empty()) {
		pair<int, int> idx = q.front().first;
		int count = q.front().second;
		q.pop();
		int row = idx.first;
		int col = idx.second;
		if (row == destRow-1 && col == destCol-1) {
			graph[row][col] = 1;
			if (count < shortest) shortest = count;
			continue;
		}
		if (row - 1 >= 0 && graph[row - 1][col] != 0) {
			graph[row - 1][col] = 0;
			q.push(make_pair(make_pair(row - 1, col), count + 1));
		}
		if (col - 1 >= 0 && graph[row][col-1] != 0) {
			graph[row][col-1] = 0;
			q.push(make_pair(make_pair(row, col-1), count + 1));
		}
		if (row + 1 < N && graph[row + 1][col] != 0) {
			graph[row + 1][col] = 0;
			q.push(make_pair(make_pair(row + 1, col), count + 1));
		}
		if (col + 1 < M && graph[row][col + 1] != 0) {
			graph[row][col + 1] = 0;
			q.push(make_pair(make_pair(row, col + 1), count + 1));
		}

	}



}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	vector<vector<int>> graph(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			graph[i][j] = line[j] - '0';
		}
		
	}
	bfs(graph, N, M);
	cout << shortest;
	return 0;
}