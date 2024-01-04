#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define ENDL '\n'

using namespace std;
using ll = long long;

void bfs(vector<int>& board, vector<int>& cost) {
	int minCount = 9999;
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0)); //갈곳을 집어넣는다...
	while (!q.empty()) {
		int idx = q.front().first;
		int count = q.front().second;
		q.pop();
		if (board[idx] > 0) { //도달한 곳이 사다리 혹은 뱀이면
			if (cost[board[idx]] < count) continue;
			q.push(make_pair(board[idx], count));
			cost[board[idx]] = count;
			continue;
		}
		
		//사다리가 아니면 주사위를 굴린다.
		if (idx + 6 >= 100) { //도달했다는뜻..
			if (count + 1 < cost[100]) cost[100] = count + 1;
			continue;
		}
		if (count + 1 < cost[idx+1]) {
			q.push(make_pair(idx + 1, count + 1));
			cost[idx + 1] = count + 1;
		}
		if (count + 1 < cost[idx + 2]) {
			q.push(make_pair(idx + 2, count + 1));
			cost[idx + 2] = count + 1;
		}
		if (count + 1 < cost[idx + 3]) {
			q.push(make_pair(idx + 3, count + 1));
			cost[idx + 3] = count + 1;
		}
		if (count + 1 < cost[idx + 4]) {
			q.push(make_pair(idx + 4, count + 1));
			cost[idx + 4] = count + 1;
		}
		if (count + 1 < cost[idx + 5]) {
			q.push(make_pair(idx + 5, count + 1));
			cost[idx + 5] = count + 1;
		}
		if (count + 1 < cost[idx + 6]) {
			q.push(make_pair(idx + 6, count + 1));
			cost[idx + 6] = count + 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> board(101, 0);
	vector<int> cost(101, 999);
	int ladderNum, snakeNum;
	cin >> ladderNum >> snakeNum;
	for (int i = 0; i < ladderNum + snakeNum; i++) {
		int from, to;
		cin >> from >> to;
		board[from] = to;
	}
	bfs(board, cost);
	cout << cost[100];

	return 0;
}