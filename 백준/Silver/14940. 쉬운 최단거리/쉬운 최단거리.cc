#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <set>
#define ENDL '\n'

using namespace std;
using ll = long long;

void bfs(vector<vector<int>>& graph, int graphRow, int graphCol, int startRow, int startCol);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int row, col;
	cin >> row >> col;
	int destRow, destCol;
	vector<vector<int>>graph(row, vector<int>(col, 0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int num;
			cin >> num;
			graph[i][j] = num;
			if (num == 2) {
				destRow = i;
				destCol = j;
			}
		}
	}
	bfs(graph, row, col, destRow, destCol);
	for (auto x : graph) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << ENDL;
	}

	return 0;
}
void bfs(vector<vector<int>>& graph, int graphRow, int graphCol, int startRow, int startCol) {
	queue<tuple<int, int, int>> q;
	q.push({ startRow, startCol, 0 });
	vector<vector<bool>>visited(graphRow, vector<bool>(graphCol, false));
	while (!q.empty()) {
		int tmpRow = get<0>(q.front());
		int tmpCol = get<1>(q.front());
		int tmpCost = get<2>(q.front());
		q.pop();
		if (visited[tmpRow][tmpCol] == true) continue;
		visited[tmpRow][tmpCol] = true;
		graph[tmpRow][tmpCol] = tmpCost;
		if (tmpRow - 1 >= 0 && graph[tmpRow - 1][tmpCol] != 0) {
			q.push({ tmpRow - 1, tmpCol, tmpCost + 1 });
		}
		if (tmpRow + 1 < graphRow && graph[tmpRow + 1][tmpCol] != 0) {
			q.push({ tmpRow + 1, tmpCol, tmpCost + 1 });
		}
		if (tmpCol - 1 >= 0 && graph[tmpRow][tmpCol - 1] != 0) {
			q.push({ tmpRow, tmpCol - 1, tmpCost + 1 });
		}
		if (tmpCol + 1 < graphCol && graph[tmpRow][tmpCol + 1] != 0) {
			q.push({ tmpRow, tmpCol + 1, tmpCost + 1 });
		}

	}
	for (int i = 0; i < graphRow; i++) {
		for (int j = 0; j < graphCol; j++) {
			if (visited[i][j] == false && graph[i][j] != 0) {
				graph[i][j] = -1;
			}
		}
	}

}