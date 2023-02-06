#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <queue>
#define ENDL '\n'

using namespace std;
using ll = long long;

void BFS(vector<vector<int>>& field, int srow, int scol);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int row, col, cabbage; cin >> col >> row >> cabbage;
		vector<vector<int>>field(row, vector<int>(col, 0));
		queue<pair<int, int>>q;
		for (int i = 0; i < cabbage; i++) {
			int row, col; cin >> col >> row;
			q.push(make_pair(row, col));
			field[row][col] = 1;
		}
		int worm = 0;
		while (!q.empty()) {
			int srow = q.front().first;
			int scol = q.front().second;
			if (field[srow][scol] == 1) worm++;
			BFS(field, srow, scol);
			q.pop();
		}
		cout << worm << ENDL;
	}
	return 0;
}
void BFS(vector<vector<int>>& field, int srow, int scol) {
	if (field[srow][scol] == 0) return;
	if (field[srow][scol] == 2) return;
	field[srow][scol] = 2;

	if (srow - 1 >= 0) BFS(field, srow - 1, scol);
	if (srow + 1 < field.size()) BFS(field, srow + 1, scol);
	if (scol - 1 >= 0) BFS(field, srow, scol - 1);
	if (scol + 1 < field[0].size()) BFS(field, srow, scol + 1);
}

