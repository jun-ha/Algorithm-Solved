#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define ENDL '\n'

using namespace std;
using ll = long long;

int dRow[4] = { -1, 1, 0, 0 };
int dCol[4] = { 0, 0, -1, 1 };

#define WALL '*'
#define EMPTY '.'
#define TREASURE '$'

int boardRow, boardCol;
char board[102][102];
int answerCnt = 0;

bool isValidRange(int row, int col) {
	if (0 <= row && row < boardRow && 0 <= col && col < boardCol) return true;
	return false;
}

bool isEdge(int row, int col) {
	if (row == 0 || row == boardRow - 1) return true;
	if (col == 0 || col == boardCol - 1) return true;
	return false;
}

bool isKey(char c) {
	if ('a' <= c && c <= 'z') return true;
	return false;
}

bool isDoor(char c) {
	if ('A' <= c && c <= 'Z') return true;
	return false;
}

void openTheDoor(char key, vector<pair<int,int>>&entrances) {
	char door = toupper(key);
	for (int i = 0; i < boardRow; i++) {
		for (int j = 0; j < boardCol; j++) {
			if (board[i][j] == door) {
				board[i][j] = EMPTY;
				if (isEdge(i, j)) entrances.push_back({ i, j });
			}
		}
	}
}

void initBoard(vector<pair<int,int>>& entrances) {
	answerCnt = 0;
	string keys ="";
	cin >> boardRow >> boardCol;
	for (int i = 0; i < boardRow; i++) {
		for (int j = 0; j < boardCol; j++) {
			char c; cin >> c;
			board[i][j] = c;

			if (isEdge(i, j)) {
				if (board[i][j] == EMPTY) {
					entrances.push_back({ i, j });
				}
				if (board[i][j] == TREASURE) {
					answerCnt++;
					board[i][j] = EMPTY;
					entrances.push_back({ i, j });
				}
				if (isKey(board[i][j])) {
					keys += board[i][j];
					board[i][j] = EMPTY;
					entrances.push_back({ i, j });
				}
			}
		}
	}
	for (char key : keys) {
		openTheDoor(key, entrances);
	}
	string keyInPocket;
	cin >> keyInPocket;
	for (char key : keyInPocket) {
		if (key == '0') break;
		openTheDoor(key, entrances);
	}
}

bool gamePlay(vector<pair<int, int>>& entrances, queue<pair<int,int>>&doorQueue, vector<vector<bool>>& visited) {
	bool isGameContinuable = false;
	
	queue<pair<int, int>>emptyQueue;
	for (pair<int, int> entrance : entrances) {
		emptyQueue.push(entrance);
	}

	while (!emptyQueue.empty() || !doorQueue.empty()) {
		
		if (emptyQueue.empty()) {
			queue<pair<int, int>>nextDoorQueue;

			while (!doorQueue.empty()) {
				auto [row, col] = doorQueue.front();
				doorQueue.pop();
				if (board[row][col] == EMPTY) {
					emptyQueue.push({ row, col });
				}
				else {
					nextDoorQueue.push({ row, col });
				}
			}

			doorQueue = nextDoorQueue;
			if (emptyQueue.empty()) break;
		}

		auto [row, col] = emptyQueue.front();
		emptyQueue.pop();

		if (visited[row][col]) continue;
		visited[row][col] = true;

		char tmp = board[row][col];

		if (isDoor(tmp)) {
			visited[row][col] = false;
			doorQueue.push({ row, col });
			continue;
		}

		if (isKey(tmp)) {
			int before = entrances.size();
			openTheDoor(tmp, entrances);

			if (entrances.size() > before) {
				isGameContinuable = true;
			}
		}

		if (tmp == TREASURE) {
			board[row][col] = EMPTY;
			answerCnt++;
		}

		for (int i = 0; i < 4; i++) {
			int nextRow = row + dRow[i];
			int nextCol = col + dCol[i];
			if (isValidRange(nextRow, nextCol) && board[nextRow][nextCol] != WALL && visited[nextRow][nextCol] == false) {
				emptyQueue.push( {nextRow, nextCol});
			}
		}
	}
	return isGameContinuable;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T-->0) {
		vector<pair<int, int>>entrances;
		queue<pair<int, int>>doorQueue;

		initBoard(entrances);
		vector<vector<bool>>visited(boardRow, vector<bool>(boardCol, false));

		while (gamePlay(entrances, doorQueue, visited));

		cout << answerCnt << ENDL;
	}
	return 0;
}