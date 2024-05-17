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

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	int count = 1;
	while (T--) {
		int numOfPeople, howMuchTime, howManyBread;
		cin >> numOfPeople >> howMuchTime >> howManyBread;
		vector<int>arrivedWhen(numOfPeople, 0);
		for (int i = 0; i < numOfPeople; i++) {
			cin >> arrivedWhen[i];
		}
		sort(arrivedWhen.begin(), arrivedWhen.end());

		int time = 0;
		int maxTime = arrivedWhen.back();
		int arriveIdx = 0;
		int supply = 0;
		bool fail = false;
		while (time <= maxTime) {
			if (time != 0 && time % howMuchTime == 0) supply += howManyBread;

			if (arrivedWhen[arriveIdx] == time) {
				int numOfPeopleArrived = 1;
				while (arriveIdx + 1 < numOfPeople && arrivedWhen[arriveIdx + 1] == time) {
					arriveIdx++;
					numOfPeopleArrived++;
				}
				arriveIdx++;
				if (supply < numOfPeopleArrived) {
					fail = true;
					break;
				}
				supply -= numOfPeopleArrived;
			}
			
			time++;
		}

		if(fail) cout << "#" << count++ << " " << "Impossible" << ENDL;
		else cout << "#" << count++ << " " << "Possible" << ENDL;

		
	}


	return 0;
}