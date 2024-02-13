#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <set>
#define ENDL '\n'

using namespace std;
using ll = long long;
void bfs(int start, int destination);
int D(int num);
int S(int num);
int L(int num);
int R(int num);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int start, destination;
		cin >> start >> destination;
		bfs(start, destination);
	}
	return 0;
}
void bfs(int start, int destination) {
	queue<tuple<int, char, int>>q;
	vector<pair<char, int>>visited(10000, {' ', -1});
	q.push({start, '*', start});
	while (!q.empty()) {
		int tmpNum = get<0>(q.front());
		char beforeCommand = get<1>(q.front());
		int beforeNum = get<2>(q.front());
		q.pop();
		if (visited[tmpNum].first != ' ') continue;
		visited[tmpNum].first = beforeCommand;
		visited[tmpNum].second = beforeNum;
		if (tmpNum == destination) break;
		q.push({ D(tmpNum), 'D', tmpNum });
		q.push({ S(tmpNum), 'S', tmpNum });
		q.push({ L(tmpNum), 'L', tmpNum });
		q.push({ R(tmpNum), 'R', tmpNum });
	}
	string answer = "";
	int tmpIdx = destination;
	while (visited[tmpIdx].first != '*') {
		answer += visited[tmpIdx].first;
		tmpIdx = visited[tmpIdx].second;
	}
	reverse(answer.begin(), answer.end());
	cout << answer << ENDL;
}
int D(int num) {
	return (2 * num) % 10000;
}
int S(int num) {
	return num == 0 ? 9999 : num-1;
}
int L(int num) {
	int d1 = num / 1000;
	int d2 = (num / 100) % 10;
	int d3 = (num / 10) % 10;
	int d4 = num % 10;
	return d2 * 1000 + d3 * 100 + d4 * 10 + d1;
}
int R(int num) {
	int d1 = num / 1000;
	int d2 = (num / 100) % 10;
	int d3 = (num / 10) % 10;
	int d4 = num % 10;
	return d4 * 1000 + d1 * 100 + d2 * 10 + d3;
}