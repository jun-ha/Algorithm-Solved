#include <iostream>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<int>nums(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	vector<int>accumulatedSequenceSum(1002, -1);
	accumulatedSequenceSum[nums[0]] = 1;
	accumulatedSequenceSum[1001] = 0;
	for (int i = 1; i < N; i++) {
		int maxSequenceValue = -1;
		for (int j = nums[i] + 1; j < 1002; j++) {
			if (accumulatedSequenceSum[j] > maxSequenceValue) {
				maxSequenceValue = accumulatedSequenceSum[j];
			}
		}
		if (accumulatedSequenceSum[nums[i]] < maxSequenceValue + 1) {
			accumulatedSequenceSum[nums[i]] = maxSequenceValue + 1;
		}
	}

	int maxSequenceValue = 0;
	for (auto x : accumulatedSequenceSum) {
		if (x > maxSequenceValue) maxSequenceValue = x;
	}
	cout << maxSequenceValue;
	return 0;
}