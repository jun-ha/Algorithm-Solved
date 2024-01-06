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

string output = "YES";

#define UNVISITED 0
#define RED 1
#define BLUE 2

void bfs(vector<vector<int>>& graph, vector<int>& visited, int nodeNum);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K;
	cin >> K;
	while (K--) {
		int V, E;
		cin >> V >> E;
		int count = 0;
		vector<vector<int>>graph(V+1, vector<int>());
		vector<int>visited(V+1, UNVISITED);
		for (int i = 0; i < E; i++) {
			int v1, v2;
			cin >> v1 >> v2;
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}
		for (int i = 1; i <= V; i++) {
			bfs(graph, visited, i);
			if (output == "NO") break;
		}
		cout << output << ENDL;
		output = "YES";
	}

	return 0;
}
void bfs(vector<vector<int>>& graph, vector<int>& visited, int nodeNum) {
	if (visited[nodeNum] == UNVISITED) {
		visited[nodeNum] = RED;
	}
	queue<int> q;
	q.push(nodeNum);
	while (!q.empty()) {
		int tmpNodeNum = q.front();
		int tmpColor = visited[tmpNodeNum];
		q.pop();
		int sameColor, difColor;
		if (tmpColor == RED) {
			sameColor = RED;
			difColor = BLUE;
		}
		if (tmpColor == BLUE) {
			sameColor = BLUE;
			difColor = RED;
		}

		for (auto x : graph[tmpNodeNum]) {
			if (visited[x] == UNVISITED) {
				visited[x] = difColor;
				q.push(x);
			}
			if (visited[x] == sameColor) {
				output = "NO";
				return;
			}
		}
	}
}