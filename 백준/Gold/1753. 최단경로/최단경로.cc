#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define ENDL '\n'

using namespace std;
int V, E;
#define INF 999999999

void Dijkstra(vector<vector<pair<int, int>>>& path_table, vector<bool>& visited, vector<int>& shortest_table, int start);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int start;
	cin >> V >> E;
	cin >> start;
	vector<vector<pair<int, int>>>path_table(V+1, vector<pair<int,int>>());
	vector<bool>visited(V + 1, false);
	vector<int>shortest_table(V + 1, INF);
	shortest_table[start] = 0;
	for (int i = 0; i < E; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		path_table[from].push_back(make_pair(to, weight));
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
void Dijkstra(vector<vector<pair<int, int>>>& path_table, vector<bool>& visited, vector<int>& shortest_table, int start) {
	priority_queue<pair<int, int>>pq;
	pq.push(make_pair(0, start));
	int visitCount = 0;
	while (visitCount < V && !pq.empty()) {
		int nextIDX = pq.top().second;
		int nextIDXLen = -pq.top().first;
		pq.pop();
		if (visited[nextIDX] == true) continue;
		visited[nextIDX] = true;
		for (auto x : path_table[nextIDX]) {
			int next2IDX = x.first;
			int next2IDXLen = x.second;
			if (visited[next2IDX] == true) continue;
			if (shortest_table[next2IDX] > next2IDXLen + nextIDXLen) {
				shortest_table[next2IDX] = next2IDXLen + nextIDXLen;
				pq.push(make_pair(-(next2IDXLen + nextIDXLen), next2IDX));
			}
		}
	}
}