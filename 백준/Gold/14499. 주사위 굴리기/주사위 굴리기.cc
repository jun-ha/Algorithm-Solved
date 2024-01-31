#include <iostream>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

enum Direction {
	EAST = 1,
	WEST,
	NORTH,
	SOUTH,
};

enum diceDirection {
	FORWARD,
	BACK,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

vector<vector<int>>Board;
int boardRow, boardCol, diceRow, diceCol, nextDiceRow, nextDiceCol, commandNum;
vector<int>dice(6, 0); 
void GamePlay(vector<int>&commands);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> boardRow >> boardCol >> diceRow >> diceCol >> commandNum;
	Board.resize(boardRow, vector<int>(boardCol, 0));
	vector<int>commands(commandNum);
	for (int i = 0; i < boardRow; i++) {
		for (int j = 0; j < boardCol; j++) {
			cin >> Board[i][j];
		}
	}
	for (int i = 0; i < commandNum; i++) {
		cin >> commands[i];
	}
	GamePlay(commands);
	return 0;
}
bool rangeCheck(int row, int col) {
	if (0 <= row && row < boardRow && 0 <= col && col < boardCol) return true;
	else return false;
}
bool checkToMove(int command) {
	nextDiceRow = diceRow;
	nextDiceCol = diceCol;
	switch (command) {
	case EAST:
		nextDiceCol++;
		break;
	case WEST:
		nextDiceCol--;
		break;
	case NORTH:
		nextDiceRow--;
		break;
	case SOUTH:
		nextDiceRow++;
	}
	if (rangeCheck(nextDiceRow, nextDiceCol)) return true;
	return false;
}
bool boardHasNumber(int row, int col) {
	if (Board[row][col] != 0) return true;
	else return false;
}
void moveDice(int command) {
	vector<int>tmpDice(dice);
	switch (command) {
	case EAST:
		dice[LEFT] = tmpDice[DOWN];
		dice[RIGHT] = tmpDice[UP];
		dice[UP] = tmpDice[LEFT];
		dice[DOWN] = tmpDice[RIGHT];
		break;
	case WEST:
		dice[LEFT] = tmpDice[UP];
		dice[RIGHT] = tmpDice[DOWN];
		dice[UP] = tmpDice[RIGHT];
		dice[DOWN] = tmpDice[LEFT];
		break;
	case NORTH:
		dice[FORWARD] = tmpDice[UP];
		dice[BACK] = tmpDice[DOWN];
		dice[UP] = tmpDice[BACK];
		dice[DOWN] = tmpDice[FORWARD];
		break;
	case SOUTH:
		dice[FORWARD] = tmpDice[DOWN];
		dice[BACK] = tmpDice[UP];
		dice[UP] = tmpDice[FORWARD];
		dice[DOWN] = tmpDice[BACK];
		break;
	}
	if (boardHasNumber(nextDiceRow, nextDiceCol)) {
		dice[DOWN] = Board[nextDiceRow][nextDiceCol];
		Board[nextDiceRow][nextDiceCol] = 0;
	}
	else {
		Board[nextDiceRow][nextDiceCol] = dice[DOWN];
	}
	diceRow = nextDiceRow;
	diceCol = nextDiceCol;
}
void GamePlay(vector<int>& commands) {
	for (auto command : commands) {
		if (checkToMove(command)) {
			moveDice(command);
			cout << dice[UP] << ENDL;
		}
	}
}
