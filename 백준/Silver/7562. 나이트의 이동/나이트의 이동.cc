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

int N;

void night_move_and_check_visit(vector<vector<int>>& graph, queue<pair<pair<int, int>, int>>& q, int count, int row, int col) {
	if (0 <= row && row < N && 0 <= col && col < N && graph[row][col] == 0) {
		graph[row][col] = 1;
		q.push(make_pair(make_pair(row, col), count + 1));
	}
}

int bfs(vector<vector<int>>& graph, int startRow, int startCol, int destRow, int destCol) {
	int shortest = 99999;
	queue< pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(startRow, startCol), 0));
	while (!q.empty()) {
		pair<int, int> idx = q.front().first;
		int count = q.front().second;
		q.pop();
		int row = idx.first;
		int col = idx.second;
		if (row == destRow && col == destCol) {
			graph[row][col] = 1;
			if (count < shortest) shortest = count;
			continue;
		}
		night_move_and_check_visit(graph, q, count, row - 2, col - 1);
		night_move_and_check_visit(graph, q, count, row - 2, col + 1);
		night_move_and_check_visit(graph, q, count, row - 1, col - 2);
		night_move_and_check_visit(graph, q, count, row - 1, col + 2);
		night_move_and_check_visit(graph, q, count, row + 1, col - 2);
		night_move_and_check_visit(graph, q, count, row + 1, col + 2);
		night_move_and_check_visit(graph, q, count, row + 2, col - 1);
		night_move_and_check_visit(graph, q, count, row + 2, col + 1);
	}	

	return shortest;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<vector<int>> graph(N, vector<int>(N, 0));
		int startRow, startCol, destRow, destCol;
		cin >> startRow >> startCol >> destRow >> destCol;
		cout << bfs(graph, startRow, startCol, destRow, destCol) << ENDL;
	}
	
	return 0;
}