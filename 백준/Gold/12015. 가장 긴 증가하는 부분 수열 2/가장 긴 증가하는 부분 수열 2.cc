#include <iostream>
#include <algorithm>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int>nums(N, 0);
	for (int i = 0; i < N; i++) cin >> nums[i];

	vector<int>LIS;
	LIS.push_back(nums[0]);
	for (int i = 0; i < N; i++) {
		if (LIS.back() < nums[i]) {
			LIS.push_back(nums[i]);
			continue;
		}

		int lessIdx = lower_bound(LIS.begin(), LIS.end(), nums[i]) - LIS.begin();
		LIS[lessIdx] = nums[i];
	}
	cout << LIS.size();
	return 0;
}