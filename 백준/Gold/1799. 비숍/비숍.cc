#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

int boardRow, boardCol;
int originalBoard[11][11];

bool isValidRange(int row, int col) {
	if (0 <= row && row < boardRow && 0 <= col && col < boardCol) return true;
	return false;
}

void eraseReachable(vector<vector<int>>&board, int row, int col, int& leftAvailableCount) {
	board[row][col] = 0;
	leftAvailableCount--;

	int tmpRow1 = row-1;
	int tmpCol1 = col+1;

	int tmpRow2 = row+1;
	int tmpCol2 = col+1;
	while (isValidRange(tmpRow1, tmpCol1)) {
		if (board[tmpRow1][tmpCol1] == 1) leftAvailableCount--;
		board[tmpRow1][tmpCol1]--;
		tmpRow1--; tmpCol1++;
	}
	while (isValidRange(tmpRow2, tmpCol2)) {
		if (board[tmpRow2][tmpCol2] == 1) leftAvailableCount--;
		board[tmpRow2][tmpCol2]--;
		tmpRow2++; tmpCol2++;
	}
}

void retrieveRechable(vector<vector<int>>& board, int row, int col, int& leftAvailableCount) {
	board[row][col] = 1;
	leftAvailableCount++;

	int tmpRow1 = row-1;
	int tmpCol1 = col+1;

	int tmpRow2 = row+1;
	int tmpCol2 = col+1;
	while (isValidRange(tmpRow1, tmpCol1)) {
		if (originalBoard[tmpRow1][tmpCol1] == 1) {
			if (board[tmpRow1][tmpCol1] == 0) leftAvailableCount++;
			board[tmpRow1][tmpCol1]++;
		}
		tmpRow1--; tmpCol1++;
	}
	while (isValidRange(tmpRow2, tmpCol2)) {
		if (originalBoard[tmpRow2][tmpCol2] == 1) {
			if (board[tmpRow2][tmpCol2] == 0) leftAvailableCount++;
			board[tmpRow2][tmpCol2]++;
		}
		tmpRow2++; tmpCol2++;
	}

}

void dfs(vector<vector<int>>& board, int row, int col, int cnt, int leftAvailableCount, int& maxValue) {
	
	if (col == boardCol) {
		maxValue = max(maxValue, cnt);
		return;
	}

	if (row == boardRow) {
		dfs(board, 0, col + 1, cnt, leftAvailableCount, maxValue);
		return;
	}

	if (board[row][col] <= 0) {
		dfs(board, row+1, col, cnt, leftAvailableCount, maxValue);
	}
	else {
		eraseReachable(board, row, col, leftAvailableCount);

		if(cnt+1+leftAvailableCount > maxValue) dfs(board, row+1, col, cnt + 1, leftAvailableCount, maxValue);

		retrieveRechable(board, row, col, leftAvailableCount);

		if(cnt+leftAvailableCount > maxValue) dfs(board, row+1, col, cnt, leftAvailableCount, maxValue);
	}
}


int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	boardRow = N; boardCol = N;

	int blackAvailable = 0;
	int whiteAvailable = 0;
	int blackMax = INT_MIN;
	int whiteMax = INT_MIN;
	vector<vector<int>>blackBoard(boardRow, vector<int>(boardCol));
	vector<vector<int>>whiteBoard(boardRow, vector<int>(boardCol));

	bool isBlackFirst = true;
	bool isBlackTurn = true;
	for (int i = 0; i < N; i++) {
		if (isBlackFirst) {
			isBlackTurn = true;
			isBlackFirst = false;
		}
		else {
			isBlackTurn = false;
			isBlackFirst = true;
		}

		for (int j = 0; j < N; j++) {
			cin >> originalBoard[i][j];
			if (isBlackTurn) {
				blackBoard[i][j] = originalBoard[i][j];
				whiteBoard[i][j] = 0;
				if (blackBoard[i][j] == 1) blackAvailable++;
				isBlackTurn = false;
			}
			else {
				whiteBoard[i][j] = originalBoard[i][j];
				blackBoard[i][j] = 0;
				if (whiteBoard[i][j] == 1) whiteAvailable++;
				isBlackTurn = true;
			}
		}
	}
	dfs(blackBoard, 0, 0, 0, blackAvailable, blackMax);
	dfs(whiteBoard, 0, 0, 0, whiteAvailable, whiteMax);
	cout << blackMax+whiteMax;
	return 0;
}