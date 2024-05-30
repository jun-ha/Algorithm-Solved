#include <iostream>
#include <algorithm>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

#define MAX_NUM 10000

int N, M;
vector<int>nums;
vector<bool>choose;
vector<int>ans;

void dfs(int idx) {
	if (idx == M) {
		for (int c : ans) cout << c << " ";
		cout << ENDL;
		return;
	}

	vector<bool>selected(MAX_NUM+1, false);

	for (int i = 0; i < N; i++) {
		if (choose[i] == false) {
			if (selected[nums[i]]) continue;
			selected[nums[i]] = true;

			choose[i] = true;
			ans[idx] = nums[i];
			dfs(idx + 1);
			choose[i] = false;
		}
	}

}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	nums.resize(N);
	choose.resize(N, false);
	ans.resize(M);
	for (int i = 0; i < N; i++) cin >> nums[i];
	sort(nums.begin(), nums.end());
	dfs(0);
	return 0;
}