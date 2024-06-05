#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T-->0) {
		int numOfBuildings, numOfRules, target;
		cin >> numOfBuildings >> numOfRules;

		vector<int>buildTime(numOfBuildings + 1);
		for (int i = 1; i <= numOfBuildings; i++) cin >> buildTime[i];

		vector<set<int>>preconditionToBuild(numOfBuildings + 1);
		for (int i = 0; i < numOfRules; i++) {
			int need, obj; cin >> need >> obj;
			preconditionToBuild[obj].insert(need);
		}

		cin >> target;

		int time = 0;
		set<int>finishBuilding;
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>processing;

		for (int i = 1; i <= numOfBuildings; i++) {
			if (preconditionToBuild[i].empty()) processing.push({buildTime[i], i});
		}

		while (1) {
			auto [buildingTime, finishBuilding] = processing.top();
			processing.pop();

			time += buildingTime;
			if (finishBuilding == target) {
				cout << time << ENDL;
				break;
			}

			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>nextProcessing;
			while (!processing.empty()) {
				nextProcessing.push({ processing.top().first - buildingTime, processing.top().second });
				processing.pop();
			}
			processing = nextProcessing;

			for (int i = 1; i <= numOfBuildings; i++) {
				bool leftOne = false;
				if (preconditionToBuild[i].size() == 1) leftOne = true;

				preconditionToBuild[i].erase(finishBuilding);
				if (leftOne && preconditionToBuild[i].empty()) {
					processing.push({ buildTime[i], i });
				}
			}
		}
	}

	return 0;
}