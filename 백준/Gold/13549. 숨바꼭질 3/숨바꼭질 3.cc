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

int solution(int N, int K);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K;
	cin >> N >> K;
	if (N >= K) {
		cout << N - K;
		return 0;
	}
	cout << solution(N, K);


	return 0;
}
int solution(int N, int K) {
	priority_queue<pair<int, int>> pq;
	vector<bool>visited(100001, false);
	pq.push(make_pair(0, N));
	while (1) {
		int step = -pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		if (visited[pos] == true) continue;
		visited[pos] = true;
		if (pos == K) return step;
		if (pos > K) {
			pq.push(make_pair(-(step + pos - K), K));
			continue;
		}
		if (pos - 1 >= 0) pq.push(make_pair(-(step + 1), pos - 1));
		pq.push(make_pair(-(step + 1), pos + 1));
		if(pos*2 <= 100000)pq.push(make_pair(-(step), pos * 2));
	}
}