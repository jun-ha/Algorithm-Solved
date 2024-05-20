#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#define ENDL '\n'

using namespace std;
using ll = long long;

#define BOARD_SIZE 9

void printBoard(vector<vector<int>>& board) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			cout << board[i][j] << " ";
		}
		cout << ENDL;
	}
}

bool checkRow(vector<vector<int>>& board, int row, int col) {
	for (int tmpCol = 0; tmpCol < BOARD_SIZE; tmpCol++) {
		if (col == tmpCol) continue;
		if (board[row][col] == board[row][tmpCol]) return false;
	}
	return true;
}

bool checkCol(vector<vector<int>>& board, int row, int col) {
	for (int tmpRow = 0; tmpRow < BOARD_SIZE; tmpRow++) {
		if (row == tmpRow) continue;
		if (board[row][col] == board[tmpRow][col]) return false;
	}
	return true;
}

bool checkSquare(vector<vector<int>>& board, int row, int col) {
	int squareRowStart = row / 3 * 3;
	int squareColStart = col / 3 * 3;
	for (int tmpRow = squareRowStart; tmpRow < squareRowStart + 3; tmpRow++) {
		for (int tmpCol = squareColStart; tmpCol < squareColStart + 3; tmpCol++) {
			if (row == tmpRow && col == tmpCol) continue;
			if (board[row][col] == board[tmpRow][tmpCol]) return false;
		}
	}
	return true;
}

void dfs(vector<vector<int>>& board, vector<pair<int, int>>& emptySpaces, int idx) {
	if (idx == emptySpaces.size()) {
		printBoard(board);
		exit(0);
	}

	int row = emptySpaces[idx].first;
	int col = emptySpaces[idx].second;

	for (int i = 1; i <= BOARD_SIZE; i++) {
		board[row][col] = i;
		if (checkRow(board, row, col) && checkCol(board, row, col) && checkSquare(board, row, col)) {
			dfs(board, emptySpaces, idx + 1);
		}
		board[row][col] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<vector<int>>board(BOARD_SIZE, vector<int>(BOARD_SIZE, 0));
	vector<pair<int, int>>emptySpaces;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) emptySpaces.push_back({ i, j });
		}
	}
	dfs(board, emptySpaces, 0);

	return 0;
}