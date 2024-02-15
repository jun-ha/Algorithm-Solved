#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#define ENDL '\n'
#define INF 999999999

using namespace std;
using ll = long long;
int numOfCity, numOfBus, start, destination;
vector<vector<pair<int, int>>>busRoutes;
vector<int>path;

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
	priority_queue<pair<int, int>>pq;
	vector<bool>visited(numOfCity + 1, false);
	vector<int>beforeCityNum(numOfCity + 1, -1);
	pq.push({0, start});
	while (!pq.empty()) {
		int costOfwayPoint = -pq.top().first;
		int wayPoint = pq.top().second;
		pq.pop();
		if (visited[wayPoint]) continue;
		visited[wayPoint] = true;
		for (auto x : busRoutes[wayPoint]) {
			int destination = x.first;
			int costOfDestination = x.second;
			if (costOfwayPoint + costOfDestination < path[destination]) {
				path[destination] = costOfwayPoint + costOfDestination;
				pq.push({ -(costOfwayPoint + costOfDestination), destination });
				beforeCityNum[destination] = wayPoint;
			}
		}
	}
	cout << path[destination] << ENDL;
	stack<int>route;
	route.push(destination);

	int tmpIdx = destination;
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