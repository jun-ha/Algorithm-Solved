#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#define ENDL '\n'

using namespace std;
using ll = long long;

int numOfNode, numOfRoute, destination;

void dijkstra(vector<vector<pair<int, int>>>&routes, vector<int>& shortestPath) {
	priority_queue<pair<int, int>>pq;
	vector<bool>visited(numOfNode + 1, false);
	pq.push({ 0, destination });

	while (!pq.empty()) {
		auto [cost, node] = pq.top();
		cost *= -1;
		pq.pop();

		if (visited[node]) continue;
		visited[node] = true;

		for (auto [nextNode, nextCost] : routes[node]) {
			int wayPointCost = cost + nextCost;
			if (shortestPath[nextNode] > wayPointCost) {
				shortestPath[nextNode] = wayPointCost;
				pq.push({ -wayPointCost, nextNode });
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> numOfNode >> numOfRoute >> destination;
	vector<vector<pair<int, int>>>routes(numOfNode + 1);
	vector<vector<pair<int, int>>>reverseRoutes(numOfNode + 1);

	for (int i = 0; i < numOfRoute; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		routes[from].push_back({ to, cost });
		reverseRoutes[to].push_back({ from, cost });
	}

	vector<int>shortestPathToDest(numOfNode+1, INT_MAX);
	vector<int>shortestPathFromDest(numOfNode + 1, INT_MAX);

	dijkstra(routes, shortestPathFromDest);
	dijkstra(reverseRoutes, shortestPathToDest);
	
	int maxValue = INT_MIN;
	for (int i = 1; i <= numOfNode; i++) {
		if (i == destination) continue;
		maxValue = max(maxValue, shortestPathFromDest[i] + shortestPathToDest[i]);
	}

	cout << maxValue;
	return 0;
}