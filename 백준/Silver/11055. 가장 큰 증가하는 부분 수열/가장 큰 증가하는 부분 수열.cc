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

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int>nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	vector<int>accumulatedSum(1001, -1);
	accumulatedSum[nums[0]] = nums[0];
	accumulatedSum[0] = 0;
	for (int i = 1; i < n; i++) {
		//선택 안한 미래는 걍냅두고
		//선택한다면..
		int tmpMax = -1;
		for (int j = nums[i] - 1; j >= 0; j--) {
			if (accumulatedSum[j] > tmpMax) {
				tmpMax = accumulatedSum[j];
			}
		}
		accumulatedSum[nums[i]] = tmpMax + nums[i];
	}

	int maxValue = 0;
	for (auto x : accumulatedSum) {
		if (x > maxValue) {
			maxValue = x;
		}
	}
	cout << maxValue;
	return 0;
}