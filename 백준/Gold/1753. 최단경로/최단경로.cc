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
int V, E;
#define INF 999999999

void Dijkstra(vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>>& path_table, vector<bool>& visited, vector<int>& shortest_table, int start);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int start;
	cin >> V >> E;
	cin >> start;
	vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>>path_table(V+1);
	vector<bool>visited(V + 1, false);
	vector<int>shortest_table(V + 1, INF);
	shortest_table[start] = 0;
	for (int i = 0; i < E; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		path_table[from].push(make_pair(weight, to));
		if (from == start && weight < shortest_table[to]) shortest_table[to] = weight;
	}
	Dijkstra(path_table, visited, shortest_table, start);
	int noZero = 0;
	for (auto x : shortest_table) {
		if (!noZero++) continue;
		if (x == INF) cout << "INF" << ENDL;
		else cout << x << ENDL;
	}
	
	return 0;
}
void Dijkstra(vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>>& path_table, vector<bool>&visited, vector<int>&shortest_table, int start) {
	visited[start] = true;
	int visitCount = 0;
	while (visitCount < V && !path_table[start].empty()) {
		int nextIDX = path_table[start].top().second;
		int nextIDXLen = path_table[start].top().first;
		path_table[start].pop();
		if (visited[nextIDX] == true) continue;
		visited[nextIDX] = true;
		visitCount++;
		while (!path_table[nextIDX].empty()) {
			int next2IDX = path_table[nextIDX].top().second;
			int next2IDXLen = path_table[nextIDX].top().first;
			path_table[nextIDX].pop();
			if (visited[next2IDX] == true) continue;
			if (shortest_table[next2IDX] > nextIDXLen + next2IDXLen) {
				shortest_table[next2IDX] = nextIDXLen + next2IDXLen;
				path_table[start].push(make_pair(nextIDXLen + next2IDXLen, next2IDX));
			}
		}
	}
}