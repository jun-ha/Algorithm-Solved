#include <iostream>
#include <queue>
#include <vector>

#define ENDL '\n'

using namespace std;

int col, row;
int tomatoLeft = 0;
void BFS(vector<vector<int>>& box, queue<pair<int, int>>&q);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> col >> row;
	vector<vector<int>>box(row, vector<int>(col, 0));
	queue<pair<int,int>>q;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int num; cin >> num;
			if (!num) {
				tomatoLeft++;
			}
			else if (num == 1) {
				q.push(make_pair(i, j));
			}
			box[i][j] = num;
		}
	}

	int dayCount = 0;
	while (tomatoLeft) {
		int tomatoLeftBefore = tomatoLeft;
		BFS(box, q);
		if (tomatoLeftBefore == tomatoLeft) break;
		dayCount++;
	}
	if (tomatoLeft) cout << -1;
	else cout << dayCount;

	return 0;
}

void makeNearTomatoRipe(vector<vector<int>>& box, queue<pair<int, int>>& q) {
	int tmp_row = q.front().first;
	int tmp_col = q.front().second;
	if (tmp_row - 1 >= 0 && !box[tmp_row - 1][tmp_col]) {
		box[tmp_row - 1][tmp_col] = 1;
		q.push(make_pair(tmp_row - 1, tmp_col));
		tomatoLeft--;
	}
	if (tmp_row + 1 < row && !box[tmp_row + 1][tmp_col]) {
		box[tmp_row + 1][tmp_col] = 1;
		q.push(make_pair(tmp_row + 1, tmp_col));
		tomatoLeft--;
	}
	if (tmp_col - 1 >= 0 && !box[tmp_row][tmp_col - 1]) {
		box[tmp_row][tmp_col - 1] = 1;
		q.push(make_pair(tmp_row, tmp_col - 1));
		tomatoLeft--;
	}
	if (tmp_col + 1 < col && !box[tmp_row][tmp_col + 1]) {
		box[tmp_row][tmp_col + 1] = 1;
		q.push(make_pair(tmp_row, tmp_col + 1));
		tomatoLeft--;
	}
}

void BFS(vector<vector<int>>& box, queue<pair<int, int>>& q) {
	int qsize = q.size();
	for (int i = 0; i < qsize; i++) {
		makeNearTomatoRipe(box, q);
		q.pop();
	}
}
