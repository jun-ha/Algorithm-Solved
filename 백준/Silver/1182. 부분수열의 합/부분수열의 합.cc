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

int cnt = 0;
int N, S;
void dfs(vector<int>& nums, int idx, int sum) {
	if (idx == N) {
		if (sum == S) cnt++;
		return;
	}

	dfs(nums, idx + 1, sum + nums[idx]);
	dfs(nums, idx + 1, sum);
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> S;
	vector<int>nums(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < N; i++) {
		dfs(nums, i+1, nums[i]);
	}

	cout << cnt;
	return 0;
}