#include <iostream>
#include <algorithm>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int nHouse, nMachine; cin >> nHouse >> nMachine;

	vector<int>house(nHouse);
	for (int i = 0; i < nHouse; i++) cin >> house[i];
	sort(house.begin(), house.end());

	int maxLen = house.back() - house.front();
	int front = 1;
	int back = maxLen;
	int answer = 0;
	while (front <= back) {
		int mid = (front + back) / 2;
		int cnt = 1;
		int beforeHousePos = house[0];
		for (int i = 1; i < nHouse; i++) {
			if (house[i] - beforeHousePos >= mid) {
				beforeHousePos = house[i];
				cnt++;
			}
		}
		if (cnt < nMachine) {
			back = mid - 1;
		}
		else {
			front = mid + 1;
			answer = mid;
		}

	}
	cout << answer;
	return 0;
}