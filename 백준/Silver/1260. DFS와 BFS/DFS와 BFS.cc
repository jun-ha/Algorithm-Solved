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

void DFS(vector<vector<int>>& graph, int start, vector<int>& check);
void BFS(vector<vector<int>>& graph, int start, vector<int>& check);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int V, E, Start; cin >> V >> E >> Start;
	vector<vector<int>>graph(V + 1);
	for (int i = 0; i < E; i++) {
		int v1, v2; cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for (int i = 0; i <= V; i++) {
		graph[i].push_back(i);
		sort(graph[i].begin(), graph[i].end());
		graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
	}
	vector<int>checkDFS(V + 1);
	vector<int>checkBFS(V + 1);
	DFS(graph, Start, checkDFS);
	cout << ENDL;
	BFS(graph, Start, checkBFS);
	return 0;
}
void DFS(vector<vector<int>>& graph, int start, vector<int>& check) {
	cout << start << ' ';
	check[start]++;
	vector<int>::iterator iter;
	stack<pair<int, vector<int>::iterator>>s;
	s.push(make_pair(start, graph[start].begin()));
	while (!s.empty()) {
		int iterIDX = s.top().first;
		iter = s.top().second;
		s.pop();
		if (iter != graph[iterIDX].end() - 1) {
			s.push(make_pair(iterIDX, iter + 1));
		}
		if (!check[*iter]) {
			cout << *iter << ' ';
			check[*iter]++;
			s.push(make_pair(*iter, graph[*iter].begin()));
		}
	}
}
void BFS(vector<vector<int>>& graph, int start, vector<int>& check) {
	cout << start << ' ';
	check[start]++;
	vector<int>::iterator iter;
	queue<pair<int, vector<int>::iterator>>q;
	q.push(make_pair(start, graph[start].begin()));
	while (!q.empty()) {
		int iterIDX = q.front().first;
		iter = q.front().second;
		q.pop();
		for (iter = graph[iterIDX].begin(); iter != graph[iterIDX].end(); iter++) {
			if (!check[*iter]) {
				cout << *iter << ' ';
				check[*iter]++;
				q.push(make_pair(*iter, graph[*iter].begin()));
			}
		}
	}
}