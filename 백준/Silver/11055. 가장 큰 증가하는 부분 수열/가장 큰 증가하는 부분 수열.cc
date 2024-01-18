#include <iostream>
#include <vector>

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
	vector<int>accumulatedSum(1001, -1); //인덱스는 최댓값, 값은 최대누적합
	accumulatedSum[nums[0]] = nums[0];
	accumulatedSum[0] = 0;
	for (int i = 1; i < n; i++) {
		//현재 수를 선택한다면
		//최댓값이 현재값보다 작은 경우들 중 가장 누적합이 큰 경우를 찾는다.
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