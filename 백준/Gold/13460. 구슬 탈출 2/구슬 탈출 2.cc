#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define ENDL '\n'

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

using namespace std;
using ll = long long;

int fieldRow, fieldCol, redRow, redCol, blueRow, blueCol, holeRow, holeCol;

tuple<int, int, int, int> makeFieldMoveInfo(vector<vector<char>>& field, int tmpRow, int tmpCol);
int bfs(vector<vector<char>>& field, vector <vector<tuple<int, int, int, int>>>&fieldMoveInfo);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> fieldRow >> fieldCol;
	vector<vector<char>>field(fieldRow, vector<char>(fieldCol));
	for (int i = 0; i < fieldRow; i++) {
		for (int j = 0; j < fieldCol; j++) {
			char cell;
			cin >> cell;
			if (cell == 'R') {
				redRow = i;
				redCol = j;
				field[i][j] = '.';
				continue;
			}
			if (cell == 'B') {
				blueRow = i;
				blueCol = j;
				field[i][j] = '.';
				continue;
			}
			if (cell == 'O') {
				holeRow = i;
				holeCol = j;
			}
			field[i][j] = cell;
		}
	}
	vector <vector<tuple<int, int, int, int>>>fieldMoveInfo(fieldRow, vector<tuple<int, int, int, int>>(fieldCol));
	for (int i = 0; i < fieldRow; i++) {
		for (int j = 0; j < fieldCol; j++) {
			fieldMoveInfo[i][j] = makeFieldMoveInfo(field, i, j);
		}
	}
	cout << bfs(field, fieldMoveInfo);

	return 0;
}

tuple<int, int, int, int> makeFieldMoveInfo(vector<vector<char>>& field, int tmpRow, int tmpCol) {
	if (field[tmpRow][tmpCol] != '#') {
		int up = tmpRow;
		int down = tmpRow;
		int left = tmpCol;
		int right = tmpCol;
		while (field[up - 1][tmpCol] != '#') {
			up--;
			if (field[up][tmpCol] == 'O') break;
		}
		while (field[down + 1][tmpCol] != '#') {
			down++;
			if (field[down][tmpCol] == 'O') break;
		}
		while (field[tmpRow][left - 1] != '#') {
			left--;
			if (field[tmpRow][left] == 'O') break;
		}
		while (field[tmpRow][right + 1] != '#') {
			right++;
			if (field[tmpRow][right] == 'O') break;
		}
		return { up, down, left, right };
	}
	return { -1, -1, -1, -1 };
}

bool holeCheck(int tmpRow, int tmpCol) {
	if (tmpRow == holeRow && tmpCol == holeCol) return true;
	return false;
}

int bfs(vector<vector<char>>& field, vector <vector<tuple<int, int, int, int>>>&fieldMoveInfo) {
	queue<tuple<int, int, int, int, int>>q; //redRow, redCol, blueRow, blueCol, count
	q.push({ redRow, redCol, blueRow, blueCol, 0 });
	while (!q.empty()) {
		int tmpRedRow = get<0>(q.front());
		int tmpRedCol = get<1>(q.front());
		int tmpBlueRow = get<2>(q.front());
		int tmpBlueCol = get<3>(q.front());
		int tmpCount = get<4>(q.front());
		q.pop();
		if (tmpCount > 10) continue;
		if (tmpBlueRow == holeRow && tmpBlueCol == holeCol) continue;
		if (tmpRedRow == holeRow && tmpRedCol == holeCol) return tmpCount;

		int redUp = get<0>(fieldMoveInfo[tmpRedRow][tmpRedCol]);
		int redDown = get<1>(fieldMoveInfo[tmpRedRow][tmpRedCol]);
		int redLeft = get<2>(fieldMoveInfo[tmpRedRow][tmpRedCol]);
		int redRight = get<3>(fieldMoveInfo[tmpRedRow][tmpRedCol]);
		int blueUp = get<0>(fieldMoveInfo[tmpBlueRow][tmpBlueCol]);
		int blueDown = get<1>(fieldMoveInfo[tmpBlueRow][tmpBlueCol]);
		int blueLeft = get<2>(fieldMoveInfo[tmpBlueRow][tmpBlueCol]);
		int blueRight = get<3>(fieldMoveInfo[tmpBlueRow][tmpBlueCol]);

		bool upDownPrecedence = (tmpRedCol == tmpBlueCol);
		bool leftRightPrecedence = (tmpRedRow == tmpBlueRow);

		if (redUp != tmpRedRow || blueUp != tmpBlueRow) { 
			if (upDownPrecedence && redUp == blueUp && !holeCheck(blueUp, tmpBlueCol)) {
				if (tmpRedRow < tmpBlueRow) blueUp++;
				else redUp++;
			}
			q.push({ redUp, tmpRedCol, blueUp, tmpBlueCol, tmpCount + 1 });
		}
		if (redDown != tmpRedRow || blueDown != tmpBlueRow) { 
			if (upDownPrecedence && redDown == blueDown && !holeCheck(blueDown, tmpBlueCol)) {
				if (tmpRedRow < tmpBlueRow) redDown--;
				else blueDown--;
			}
			q.push({ redDown, tmpRedCol, blueDown, tmpBlueCol, tmpCount + 1 });
		}
		if (redLeft != tmpRedCol || blueLeft != tmpBlueCol) { 
			if (leftRightPrecedence && redLeft == blueLeft && !holeCheck(tmpBlueRow, blueLeft)) {
				if (tmpRedCol < tmpBlueCol) blueLeft++;
				else redLeft++;
			}
			q.push({ tmpRedRow, redLeft, tmpBlueRow, blueLeft, tmpCount + 1 });
		}
		if (redRight != tmpRedCol || blueRight != tmpBlueCol) { 
			if (leftRightPrecedence && redRight == blueRight && !holeCheck(tmpBlueRow, blueRight)) {
				if (tmpRedCol < tmpBlueCol) redRight--;
				else blueRight--;
			}
			q.push({ tmpRedRow, redRight, tmpBlueRow, blueRight, tmpCount + 1 });
		}
	}
	return -1;
}