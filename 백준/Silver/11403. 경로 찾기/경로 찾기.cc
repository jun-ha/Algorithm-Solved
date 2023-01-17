#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define ENDL '\n'

using namespace std;
using ll = long long;

int DFS(vector<vector<int>>& Graph, vector<int>& visited, int v1, int v2);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<vector<int>>Graph(N, vector<int>(N, 0));
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cin >> Graph[row][col];
		}
	}
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			vector<int>visited(N, 0);
			cout << DFS(Graph, visited, row, col) << ' ';
		}
		cout << ENDL;
	}
	return 0;
}
int DFS(vector<vector<int>>& Graph, vector<int>& visited, int v1, int v2) {
	if (visited[v1]) return 0;
	else visited[v1] = 1;

	if (Graph[v1][v2]) return 1;

	for (int i = 0; i < Graph[v1].size(); i++) {
		if (Graph[v1][i]) {
			if (DFS(Graph, visited, i, v2)) {
				return 1;
			}
		}
	}
	return 0;
}