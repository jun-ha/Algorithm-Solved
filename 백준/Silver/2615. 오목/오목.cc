#include <iostream>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

#define BOARD_SIZE 20
int board[BOARD_SIZE][BOARD_SIZE];

int dRow[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dCol[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

enum direction {
	LEFT = 0,
	LEFT_UP,
	UP,
	UP_RIGHT,
	RIGHT,
	RIGHT_DOWN,
	DOWN,
	DOWN_LEFT
};

bool rangeCheck(int row, int col) {
	if (1 <= row && row < BOARD_SIZE && 1 <= col && col < BOARD_SIZE) return true;
	return false;
}

void isGameOver(int row, int col, int blackOrWhite, int direction) {
	int cnt = 1;
	int startRow = row;
	int startCol = col;
	while (cnt <= 6) {
		row = row + dRow[direction];
		col = col + dCol[direction];
		if (rangeCheck(row, col) && board[row][col] == blackOrWhite) cnt++;
		else break;
	}
	if (cnt == 5) {
		cout << blackOrWhite << ENDL;
		if (direction == DOWN_LEFT) cout << row - 1 << " " << col + 1;
		else cout << startRow << " " << startCol;
		exit(0);
	}
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int row = 1; row < BOARD_SIZE; row++) {
		for (int col = 1; col < BOARD_SIZE; col++) {
			cin >> board[row][col];
		}
	}

	for (int row = 1; row < BOARD_SIZE; row++) {
		for (int col = 1; col < BOARD_SIZE; col++) {
			int tmpColor = board[row][col];
			if (tmpColor == 0) continue;
			if (row == 4 && col == 10) {
				int a = 3;
			}

			for (int dir = RIGHT; dir <= DOWN_LEFT; dir++) {
				int nextRow = row + dRow[dir];
				int nextCol = col + dCol[dir];
				int beforeRow = row - dRow[dir];
				int beforeCol = col - dCol[dir];
				if (rangeCheck(nextRow, nextCol) && board[nextRow][nextCol] == tmpColor) {
					if ((rangeCheck(beforeRow, beforeCol) == false) || (rangeCheck(beforeRow, beforeCol) && board[beforeRow][beforeCol] != tmpColor)) {
						isGameOver(row, col, tmpColor, dir);
					}
				}
			}
		}
	}
	cout << 0;
	return 0;
}