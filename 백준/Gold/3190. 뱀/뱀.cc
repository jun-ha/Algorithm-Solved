#include <iostream>
#include <vector>
#include <queue>
#define ENDL '\n'

using namespace std;
using ll = long long;

enum BoardStatus {
	EMPTY,
	SNAKE,
	APPLE
};

enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

int boardSize, numOfApple, numOfChangeDir;
int elapsedTime = 0;
int snakeDirection = RIGHT;
int snakeHeadRow = 1, snakeHeadCol = 1;
int nextHeadRow, nextHeadCol;
queue<pair<int, int>> SnakeRouteInfo;
queue<pair<int, char>> DirectionChangeInfo;

void GamePlay(vector<vector<int>>&Board);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> boardSize >> numOfApple;
	vector<vector<int>>Board(boardSize + 1, vector<int>(boardSize + 1));
	for (int i = 0; i < numOfApple; i++) {
		int row, col;
		cin >> row >> col;
		Board[row][col] = APPLE;
	}
	cin >> numOfChangeDir;
	for (int i = 0; i < numOfChangeDir; i++) {
		int second;
		char dir;
		cin >> second >> dir;
		DirectionChangeInfo.push({ second, dir });
	}
	Board[1][1] = SNAKE;
	GamePlay(Board);

	return 0;
}
void ChangeDirection(char dir) {
	switch (snakeDirection) {
	case UP:
		if (dir == 'L') snakeDirection = LEFT;
		if (dir == 'D') snakeDirection = RIGHT;
		break;
	case DOWN:
		if (dir == 'L') snakeDirection = RIGHT;
		if (dir == 'D') snakeDirection = LEFT;
		break;
	case LEFT:
		if (dir == 'L') snakeDirection = DOWN;
		if (dir == 'D') snakeDirection = UP;
		break;
	case RIGHT:
		if (dir == 'L') snakeDirection = UP;
		if (dir == 'D') snakeDirection = DOWN;
	}
}
bool rangeCheck(int row, int col) {
	if (1 <= row && row <= boardSize && 1 <= col && col <= boardSize) return true;
	else return false;
}
bool checkToMove(vector<vector<int>>& Board) {
	nextHeadRow = snakeHeadRow;
	nextHeadCol = snakeHeadCol;
	switch (snakeDirection) {
	case UP:
		nextHeadRow--;
		break;
	case DOWN:
		nextHeadRow++;
		break;
	case LEFT:
		nextHeadCol--;
		break;
	case RIGHT:
		nextHeadCol++;
	}

	if (rangeCheck(nextHeadRow, nextHeadCol) && Board[nextHeadRow][nextHeadCol] != SNAKE) {
		return true;
	}
	else {
		return false;
	}
}
bool move(vector<vector<int>>& Board) {
	if (checkToMove(Board)) {
		SnakeRouteInfo.push({ snakeHeadRow, snakeHeadCol });
		snakeHeadRow = nextHeadRow;
		snakeHeadCol = nextHeadCol;

		if (Board[snakeHeadRow][snakeHeadCol] != APPLE) { //if APPLE - DO NOTHING
			int snakeTailRow = SnakeRouteInfo.front().first;
			int snakeTailCol = SnakeRouteInfo.front().second;
			Board[snakeTailRow][snakeTailCol] = EMPTY;
			SnakeRouteInfo.pop();
		}
		
		Board[snakeHeadRow][snakeHeadCol] = SNAKE;
		return true;
	}
	return false;
}
void GamePlay(vector<vector<int>>& Board) {
	while (move(Board)) {
		elapsedTime++;
		if (!DirectionChangeInfo.empty() && DirectionChangeInfo.front().first == elapsedTime) {
			ChangeDirection(DirectionChangeInfo.front().second);
			DirectionChangeInfo.pop();
		}
	}
	cout << elapsedTime + 1;
}