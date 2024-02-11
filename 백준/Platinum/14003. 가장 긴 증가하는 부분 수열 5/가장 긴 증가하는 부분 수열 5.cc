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
	vector<int>nums(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	vector<int>idx(N, 0);
	vector<int>LIS;
	LIS.push_back(nums[0]);
	for (int i = 1; i < N; i++) {
		if (nums[i] > LIS.back()) {
			LIS.push_back(nums[i]);
			idx[i] = LIS.size() - 1;
			continue;
		}
		if (nums[i] < LIS.front()) {
			idx[i] = 0;
			LIS[0] = nums[i];
			continue;
		}
		int left = 0;
		int right = LIS.size();
		int mid;
		while (left<=right) {
			mid = (left + right) / 2;
			if (LIS[mid] == nums[i]) break;
			else if (LIS[mid] > nums[i]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		if (LIS[mid] < nums[i]) {
			mid++;
		}
		LIS[mid] = nums[i];
		idx[i] = mid;
	}
	cout << LIS.size() << ENDL;
	int tmpMax = LIS.size()-1;
	stack<int>s;
	for (int i = N - 1; i >= 0; i--) {
		if (idx[i] == tmpMax) {
			s.push(nums[i]);
			tmpMax--;
		}
	}
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();

	}
	return 0;
}