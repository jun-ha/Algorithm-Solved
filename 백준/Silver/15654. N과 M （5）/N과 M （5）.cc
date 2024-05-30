#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ENDL '\n'

using namespace std;
using ll = long long;

struct Compare {
	bool operator() (vector<int>&a, vector<int>& b) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i]) continue;
			return a > b;
		}
	}
};

priority_queue<vector<int>, vector<vector<int>>, Compare>pq;

void dfs(vector<int>&nums, vector<bool>& choose, int idx, int tmpCnt, int maxCnt) {
	if (tmpCnt == maxCnt) {
		vector<int>tmpNums;
		for (int i = 0; i < choose.size(); i++) {
			if (choose[i]) tmpNums.push_back(nums[i]);
		}
		
		do {
			vector<int>tmp(tmpNums);
			pq.push(tmp);
		} while (next_permutation(tmpNums.begin(), tmpNums.end()));

		return;
	}
	if (idx == nums.size()) return;

	choose[idx] = true;
	dfs(nums, choose, idx + 1, tmpCnt + 1, maxCnt);
	choose[idx] = false;
	dfs(nums, choose, idx + 1, tmpCnt, maxCnt);
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<int>nums(N);
	for (int i = 0; i < N; i++) cin >> nums[i];
	sort(nums.begin(), nums.end());

	vector<bool>choose(N, false);

	dfs(nums, choose, 0, 0, M);

	while (!pq.empty()) {
		vector<int>a = pq.top();
		pq.pop();
		for (int num : a) {
			cout << num << " ";
		}
		cout << ENDL;
	}

	return 0;
}