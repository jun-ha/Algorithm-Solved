#include <iostream>
#include <algorithm>
#include <vector>

#define ENDL '\n'

using namespace std;
using ll = long long;

#define INF 1e10

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int vertexNum, edgeNum;

	cin >> vertexNum >> edgeNum;
	vector<vector<ll>>matrix(vertexNum+1, vector<ll>(vertexNum+1, INF));

	for (int i = 0; i < edgeNum; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		if (cost < matrix[from][to]) {
			matrix[from][to] = cost;
		}
	}
	for (int i = 1; i <= vertexNum; i++) {
		for (int j = 1; j <= vertexNum; j++) {
			if (i == j) matrix[i][j] = 0;
		}
	}
	for (int k = 1; k <= vertexNum; k++) {
		for (int i = 1; i <= vertexNum; i++) {
			for (int j = 1; j <= vertexNum; j++) {
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}

	for (int i = 1; i <= vertexNum; i++) {
		for (int j = 1; j <= vertexNum; j++) {
			if (matrix[i][j] >= INF) cout << 0 << " ";
			else cout << matrix[i][j] << " ";
		}
		cout << ENDL;
	}
	return 0;
}