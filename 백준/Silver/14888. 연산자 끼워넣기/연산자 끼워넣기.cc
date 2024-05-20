#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#define ENDL '\n'

using namespace std;
using ll = long long;

vector<int>nums;
vector<int>ops(4, 0);

int maxValue = INT_MIN;
int minValue = INT_MAX;

int calculate(int num1, int num2, int op) {
	switch (op) {
	case 0:
		return num1 + num2;
	case 1:
		return num1 - num2;
	case 2:
		return num1 * num2;
	case 3:
		return num1 / num2;
	}
}

void dfs(int result, int idx) {
	if (idx == nums.size()) {
		if (result > maxValue) maxValue = result;
		if (result < minValue) minValue = result;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (ops[i]) {
			if (i == 3 && nums[idx] == 0) continue;
			ops[i]--;
			dfs(calculate(result, nums[idx], i), idx + 1);
			ops[i]++;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	nums.resize(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> ops[i];
	}
	dfs(nums[0], 1);
	cout << maxValue << ENDL << minValue;
	return 0;
}