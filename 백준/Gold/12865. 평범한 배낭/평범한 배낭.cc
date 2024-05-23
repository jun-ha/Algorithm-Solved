#include <iostream>
#include <algorithm>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int numOfItems, bagCapacity; cin >> numOfItems >> bagCapacity;
	vector<pair<int, int>>itemInfo(numOfItems+1);
	for (int i = 1; i <= numOfItems; i++) {
		int weight, value; cin >> weight >> value;
		itemInfo[i] = { weight, value };
	}

	vector<vector<int>>dp(numOfItems+1, vector<int>(bagCapacity+1, 0));
	for (int item = 1; item <= numOfItems; item++) {
		int tmpWeight = itemInfo[item].first;
		int tmpValue = itemInfo[item].second;
		for (int weight = 1; weight <= bagCapacity; weight++) {
			if (tmpWeight > weight) {
				dp[item][weight] = dp[item - 1][weight];
			}
			else {
				dp[item][weight] = max(dp[item - 1][weight], dp[item-1][weight-tmpWeight] + tmpValue);
			}
		}
	}
	cout << dp[numOfItems][bagCapacity];
	return 0;
}