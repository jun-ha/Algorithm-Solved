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

void dfs(vector<int>& nums, int idx, int sum, int goal, int& cnt) {
	if (idx == nums.size()) {
		if (sum == goal) cnt++;
		return;
	}

	dfs(nums, idx + 1, sum + nums[idx], goal, cnt);
	dfs(nums, idx + 1, sum, goal, cnt);
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	int count = 1;
	while (T--) {
		int N, K; cin >> N >> K;
		vector<int>nums(N, 0);
		for (int i = 0; i < N; i++) cin >> nums[i];

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			dfs(nums, i + 1, nums[i], K, cnt);
		}

		cout << "#" << count++ << " " << cnt << ENDL;
	}


	return 0;
}