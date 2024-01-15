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

int vertexNum, edgeNum;
#define INF 1e10

bool solution(vector<tuple<int, int, int>>& pathTable, vector<ll>& shortestPath, int start);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> vertexNum >> edgeNum;
	vector<tuple<int, int, int>>pathTable;
	vector<ll>shortestPath(vertexNum + 1, INF);
	for (int i = 0; i < edgeNum; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		pathTable.push_back({ from, to, weight });
	}
	if (solution(pathTable, shortestPath, 1)) return 0;
	
	for (int i = 2; i <= vertexNum; i++) {
		if (shortestPath[i] >= INF) cout << -1 << ENDL;
		else cout << shortestPath[i] << ENDL;
	}
	return 0;
}

bool solution(vector<tuple<int, int, int>>&pathTable, vector<ll>&shortestPath, int start) {
	bool change;
	shortestPath[start] = 0;
	for (int i = 0; i < vertexNum - 1; i++) {
		change = false;
		for (int j = 0; j < edgeNum; j++) {
			int from, to, weight;
			from = get<0>(pathTable[j]);
			to = get<1>(pathTable[j]);
			weight = get<2>(pathTable[j]);
			if (shortestPath[from] != INF && shortestPath[to] > shortestPath[from] + weight) {
				shortestPath[to] = shortestPath[from] + weight;
				change = true;
			}
		}
		if (change == false) return false;
	}

	for (int j = 0; j < edgeNum; j++) {
		int from, to, weight;
		from = get<0>(pathTable[j]);
		to = get<1>(pathTable[j]);
		weight = get<2>(pathTable[j]);
		if (shortestPath[to] > shortestPath[from] + weight) {
			cout << -1;
			return true;
		}
	}
	return false;
}