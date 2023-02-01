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

int virus_count = 0;
void DFS(vector<vector<int>>& graph, vector<int>& visited, int visit);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int computer, edge; cin >> computer >> edge;
	vector<vector<int>>graph(101);
	for (int i = 0; i < edge; i++) {
		int v1, v2; cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	vector<int>visited(101, 0);
	DFS(graph, visited, 1);
	cout << virus_count-1;
	return 0;
}
void DFS(vector<vector<int>>& graph, vector<int>& visited, int visit) {
	if (visited[visit]++) return;
	virus_count++;
	for (auto x : graph[visit])
	{
		DFS(graph, visited, x);
	}
}