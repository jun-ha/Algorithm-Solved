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

int numOfCity, numOfBus;
vector<vector<int>>busRoutes;
vector<vector<vector<int>>>path;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> numOfCity >> numOfBus;
	busRoutes.resize(numOfCity + 1, vector<int>(numOfCity + 1, INF));
	path.resize(numOfCity + 1, vector<vector<int>>(numOfCity + 1, vector<int>()));
	for (int i = 0; i < numOfBus; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		if (busRoutes[from][to] > cost) {
			busRoutes[from][to] = cost;
			path[from][to].clear();
			path[from][to].push_back(from);
			path[from][to].push_back(to);
		}
	}
	
	for (int wayPoint = 1; wayPoint <= numOfCity; wayPoint++) {
		for (int from = 1; from <= numOfCity; from++) {
			if (from == wayPoint) continue;
			for (int to = 1; to <= numOfCity; to++) {
				if (to == wayPoint) continue;
				if (to == from) continue;
				int directCost = busRoutes[from][to];
				int wayPointCost = busRoutes[from][wayPoint] + busRoutes[wayPoint][to];
				if (wayPointCost < directCost) {
					busRoutes[from][to] = wayPointCost;
					vector<int>newPath(path[from][wayPoint]);
					int len = path[wayPoint][to].size();
					for (int i = 1; i < len; i++) {
						newPath.push_back(path[wayPoint][to][i]);
					}
					path[from][to] = newPath;
				}
			}
		}
	}

	for (int i = 1; i <= numOfCity; i++) {
		for (int j = 1; j <= numOfCity; j++) {
			if (busRoutes[i][j] == INF) cout << 0 << " ";
			else cout << busRoutes[i][j] << " ";
		}
		cout << ENDL;
	}
	for (int i = 1; i <= numOfCity; i++) {
		for (int j = 1; j <= numOfCity; j++) {
			if (i == j || busRoutes[i][j] == INF) {
				cout << 0 << ENDL;
			}
			else {
				cout << path[i][j].size() << " ";
				for (auto x : path[i][j]) {
					cout << x << " ";
				}
				cout << ENDL;
			}
		}
	}

	return 0;
}