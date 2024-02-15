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
#define INF 999999999

using namespace std;
using ll = long long;
int numOfCity, numOfBus, start, destination;
vector<vector<pair<int, int>>>busRoutes;
vector<ll>path;

void solution();

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> numOfCity >> numOfBus;
	busRoutes.resize(numOfCity + 1);
	path.resize(numOfCity + 1, INF);
	for (int i = 0; i < numOfBus; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		busRoutes[from].push_back({ to, cost });
	}
	cin >> start >> destination;
	solution();
	return 0;
}
void solution() {
	priority_queue<pair<ll, int>>pq;
	vector<bool>visited(numOfCity + 1, false);
	vector<int>beforeCityNum(numOfCity + 1, -1);
	pq.push({0, start});
	while (!pq.empty()) {
		ll costOfwayPoint = -pq.top().first;
		int wayPoint = pq.top().second;
		pq.pop();
		if (visited[wayPoint]) continue;
		visited[wayPoint] = true;
		for (auto x : busRoutes[wayPoint]) {
			int destination = x.first;
			ll costOfDestination = x.second;
			if (costOfwayPoint + costOfDestination < path[destination]) {
				path[destination] = costOfwayPoint + costOfDestination;
				pq.push({ -(costOfwayPoint + costOfDestination), destination });
				beforeCityNum[destination] = wayPoint;
			}
		}
	}
	cout << path[destination] << ENDL;
	int tmpIdx = destination;
	stack<int>route;
	route.push(destination);
	/*while (beforeCityNum[tmpIdx] != -1) {
		route.push(beforeCityNum[tmpIdx]);
		tmpIdx = beforeCityNum[tmpIdx];
	}*/
	while (tmpIdx != start) {
		route.push(beforeCityNum[tmpIdx]);
		tmpIdx = beforeCityNum[tmpIdx];
	}
	cout << route.size() << ENDL;
	while (!route.empty()) {
		cout << route.top() << " ";
		route.pop();
	}

}