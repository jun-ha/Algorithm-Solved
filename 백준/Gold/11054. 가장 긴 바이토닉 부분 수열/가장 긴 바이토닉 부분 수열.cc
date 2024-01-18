#include <iostream>
#include <algorithm>
#include <vector>

#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<int>nums(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	vector<int>upwardAccumulatedSequenceSum(1002, -1);
	vector<int>downwardAccumulatedSequenceSum(1002, -1);
	upwardAccumulatedSequenceSum[nums[0]] = 1;
	upwardAccumulatedSequenceSum[0] = 0;
	downwardAccumulatedSequenceSum[nums[0]] = 1;
	downwardAccumulatedSequenceSum[1001] = 0;

	for (int i = 1; i < N; i++) {
		//find upward
		int maxUpwardSequence = -1;
		for (int j = nums[i] - 1; j >= 0; j--) {
			if (upwardAccumulatedSequenceSum[j] > maxUpwardSequence) {
				maxUpwardSequence = upwardAccumulatedSequenceSum[j];
			}
		}
		upwardAccumulatedSequenceSum[nums[i]] = maxUpwardSequence + 1;
		//find downward
		int maxDownwardSequence = -1;
		for (int j = nums[i] + 1; j <= 1001; j++) {
			if (downwardAccumulatedSequenceSum[j] > maxDownwardSequence) {
				maxDownwardSequence = downwardAccumulatedSequenceSum[j];
			}
		}
		
		downwardAccumulatedSequenceSum[nums[i]] = max(maxUpwardSequence, maxDownwardSequence) + 1;
	}
	int maxValue = 0;
	for (auto x : upwardAccumulatedSequenceSum) {
		if (maxValue < x) maxValue = x;
	}
	for (auto x : downwardAccumulatedSequenceSum) {
		if (maxValue < x) maxValue = x;
	}
	cout << maxValue;
	return 0;
}