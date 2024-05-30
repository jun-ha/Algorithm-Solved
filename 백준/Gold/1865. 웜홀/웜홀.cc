#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int numOfNode, numOfRoad, numOfWormhole;
		cin >> numOfNode >> numOfRoad >> numOfWormhole;
		//vector<vector<int>>routes(numOfNode + 1, vector<int>(numOfNode + 1, INT_MAX/2-1));
		int routes[501][501];
		fill(routes[0], routes[501], INT_MAX / 2 - 1);

		for (int i = 0; i < numOfRoad; i++) {
			int node1, node2, cost;
			cin >> node1 >> node2 >> cost;
			routes[node1][node2] = min(routes[node1][node2], cost);
			routes[node2][node1] = min(routes[node2][node1], cost);
		}

		for (int i = 0; i < numOfWormhole; i++) {
			int from, to, cost;
			cin >> from >> to >> cost;
			routes[from][to] = min(routes[from][to], -cost);
		}

		for (int wayPoint = 1; wayPoint <= numOfNode; wayPoint++) {
			for (int from = 1; from <= numOfNode; from++) {
				if (from == wayPoint) continue;
				for (int to = 1; to <= numOfNode; to++) {
					if (to == from || to == wayPoint) continue;
					routes[from][to] = min(routes[from][to], routes[from][wayPoint] + routes[wayPoint][to]);
				}
			}
		}

		bool find = false;
		for (int start = 1; start <= numOfNode; start++) {
			for (int wayPoint = 1; wayPoint <= numOfNode; wayPoint++) {
				if (routes[start][wayPoint] + routes[wayPoint][start] < 0) {
					find = true;
					break;
				}
			}
			if (find) break;
		}

		if (find) cout << "YES";
		else cout << "NO";

		cout << ENDL;
	}


	return 0;
}