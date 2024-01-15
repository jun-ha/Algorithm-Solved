#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ENDL '\n'

using namespace std;
using ll = long long;

int vertexNum, edgeNum;
#define INF 1e10
ll solution(vector<vector<ll>>& matrix, int start);
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> vertexNum >> edgeNum;
	vector<vector<ll>>matrix(vertexNum+1, vector<ll>(vertexNum+1, INF));

	for (int i = 0; i < edgeNum; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		matrix[from][to] = cost;
	}
	
	for (int k = 1; k <= vertexNum; k++) {
		for (int i = 1; i <= vertexNum; i++) {
			for (int j = 1; j <= vertexNum; j++) {
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}
	
	ll shortestCycle = INF;
	for (int i = 1; i <= vertexNum; i++) {
		shortestCycle = min(shortestCycle, solution(matrix, i));
	}
	if (shortestCycle >= INF) cout << -1;
	else cout << shortestCycle;

	return 0;
}
ll solution(vector<vector<ll>>& matrix, int start) {
	priority_queue<pair<int,int>>q;
	vector<bool>visited(vertexNum + 1, false);
	for (int i = 1; i <= vertexNum; i++) {
		if (matrix[start][i] <= INF) {
			if(i==start) q.push({ 0, i });
			else q.push({ -matrix[start][i], i });
		}
	}
	while (!q.empty()) {
		int idx = q.top().second;
		int cost = -q.top().first;
		q.pop();
		if (visited[idx] == true) continue;
		visited[idx] = true;
		if (matrix[idx][start] + cost <= INF) {
			return matrix[idx][start] + cost;
		}
		for (int i = 1; i <= vertexNum; i++) {
			if (matrix[idx][i] <= INF) q.push({ -(cost + matrix[idx][i]), i });
		}
	}
	return INF;
}