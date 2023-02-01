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

void DFS(vector<vector<int>>& graph, vector<int>& visited, int visit);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int vertex, edge; cin >> vertex >> edge;
	vector<vector<int>>graph(vertex + 1);
	vector<int>visited(vertex + 1, 0);
	for (int i = 0; i < edge; i++) {
		int v1, v2; cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	int count = 0;
	for (int i = 1; i <= vertex; i++) {
		if (!visited[i]) {
			DFS(graph, visited, i);
			count++;
		}
	}

	cout << count;
	return 0;
}
void DFS(vector<vector<int>>& graph, vector<int>& visited, int visit) {
	if (visited[visit]++)return;
	for (auto x : graph[visit]) {
		DFS(graph, visited, x);
	}
}
