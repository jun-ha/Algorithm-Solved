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

int unripeCount = 0;
int containerRow, containerCol, containerHeight;
int bfs(vector<vector<vector<int>>>& container);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> containerCol >> containerRow >> containerHeight;
	vector<vector<vector<int>>>container(containerHeight, vector<vector<int>>(containerRow, vector<int>(containerCol, 0)));
	for (int i = 0; i < containerHeight; i++) {
		for (int j = 0; j < containerRow; j++) {
			for (int p = 0; p < containerCol; p++) {
				int num;
				cin >> num;
				container[i][j][p] = num;
				if (num == 0) unripeCount++;
			}
		}
	}
	cout << bfs(container);
	

	return 0;
}
int bfs(vector<vector<vector<int>>>& container) {
	queue<pair<tuple<int, int, int>, int>>q;
	int maxDay = -999;
	for (int h = 0; h < containerHeight; h++) {
		for (int r = 0; r < containerRow; r++) {
			for (int c = 0; c < containerCol; c++) {
				if (container[h][r][c] == 1) {
					q.push(make_pair(make_tuple(h, r, c), 0));
				}
			}
		}
	}
	while (!q.empty()) {
		pair<tuple<int, int, int>, int> element = q.front();
		q.pop();
		int height = get<0>(element.first);
		int row = get<1>(element.first);
		int col = get<2>(element.first);
		int day = element.second;
		if (maxDay < day) maxDay = day;

		if (height - 1 >= 0 && container[height - 1][row][col] == 0) {
			container[height - 1][row][col] = 1;
			q.push(make_pair(make_tuple(height - 1, row, col), day + 1));
			unripeCount--;
		}
		if (height + 1 < containerHeight && container[height + 1][row][col] == 0) {
			container[height + 1][row][col] = 1;
			q.push(make_pair(make_tuple(height + 1, row, col), day + 1));
			unripeCount--;
		}
		if (row - 1 >= 0 && container[height][row-1][col] == 0) {
			container[height][row-1][col] = 1;
			q.push(make_pair(make_tuple(height, row-1, col), day + 1));
			unripeCount--;
		}
		if (row + 1 < containerRow && container[height][row+1][col] == 0) {
			container[height][row+1][col] = 1;
			q.push(make_pair(make_tuple(height, row+1, col), day + 1));
			unripeCount--;
		}
		if (col - 1 >= 0 && container[height][row][col-1] == 0) {
			container[height][row][col-1] = 1;
			q.push(make_pair(make_tuple(height, row, col-1), day + 1));
			unripeCount--;
		}
		if (col + 1 < containerCol && container[height][row][col + 1] == 0) {
			container[height][row][col + 1] = 1;
			q.push(make_pair(make_tuple(height, row, col+1), day + 1));
			unripeCount--;
		}
	}
	if (unripeCount != 0) {
		return -1;
	}
	return maxDay;
}