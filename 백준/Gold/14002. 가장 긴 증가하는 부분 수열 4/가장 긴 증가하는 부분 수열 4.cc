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
	int N; cin >> N;
	vector<int>nums(N, 0);
	vector<int>maxSequence(N, 0);
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
	}
	int maxValue = 0;
	vector<int>path;
	for (auto x : maxSequence) {
		if (x > maxValue) maxValue = x;
	}
	int tmpMax = maxValue;
	for (int i = N - 1; i >= 0; i--) {
		if (maxSequence[i] == tmpMax) {
			path.push_back(nums[i]);
			tmpMax--;
		}
	}
	reverse(path.begin(), path.end());
	cout << maxValue << ENDL;
	for (auto x : path) {
		cout << x << " ";
	}
	


	return 0;
}