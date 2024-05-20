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

int N;
vector<vector<int>>board;
vector<bool>choose;

int minGap = INT_MAX;

int addScore(int score, int idx) {
	for (int i = 0; i < idx; i++) {
		if (choose[i]) {
			score += board[i][idx] + board[idx][i];
		}
	}
	return score;
}

void dfs(int idx, int tmpCount, int score) {

	if (tmpCount == N / 2) {
		int otherTeamScore = 0;
		for (int i = 0; i < choose.size(); i++) {
			if (choose[i] == false) {
				for (int j = 0; j < i; j++) {
					if (choose[j] == false) {
						otherTeamScore += board[i][j] + board[j][i];
					}
				}
			}
		}
		minGap = min(minGap, abs(score - otherTeamScore));
		return;
	}

	if (idx == N) return;

	choose[idx] = true;
	dfs(idx + 1, tmpCount + 1, addScore(score, idx));

	if (idx == 0) return; //backtracking

	choose[idx] = false;
	dfs(idx + 1, tmpCount, score);
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	board.resize(N, vector<int>(N, 0));
	choose.resize(N, false);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	dfs(0, 0, 0);
	cout << minGap;

	return 0;
}