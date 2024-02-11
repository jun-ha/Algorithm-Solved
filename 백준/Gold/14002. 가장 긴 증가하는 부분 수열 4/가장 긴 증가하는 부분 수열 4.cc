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
	vector<int>maxSequence(N, 0);
	int maxSequenceValue = 0;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < N; i++) {
		int tmpNum = nums[i];
		int tmpMax = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (nums[j] < tmpNum && maxSequence[j] > tmpMax) {
				tmpMax = maxSequence[j];
			}
		}
		maxSequence[i] = tmpMax + 1;
		if (maxSequence[i] > maxSequenceValue) maxSequenceValue = maxSequence[i];
	}
	vector<int>path;
	int tmpMax = maxSequenceValue;
	for (int i = N - 1; i >= 0; i--) {
		if (maxSequence[i] == tmpMax) {
			path.push_back(nums[i]);
			tmpMax--;
		}
	}
	cout << maxSequenceValue << ENDL;
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
	return 0;
}