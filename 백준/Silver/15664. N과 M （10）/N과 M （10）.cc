#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define ENDL '\n'

using namespace std;
using ll = long long;

int N, M;
queue<vector<int>>q;
vector<int>nums;
vector<pair<int, int>>sortedNums;

void rec(int idx, int remaining, vector<int>tmpVector);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());
	int beforeNum = nums[0];
	int sameCount = 1;
	for (int i = 1; i < N; i++) {
		if (nums[i] == beforeNum) {
			sameCount++;
		}
		else {
			sortedNums.push_back({ beforeNum, sameCount });
			beforeNum = nums[i];
			sameCount = 1;
		}
	}
	sortedNums.push_back({ beforeNum, sameCount });
	rec(0, M, vector<int>());

	while (!q.empty()) {
		for (auto x : q.front()) {
			cout << x << " ";
		}
		cout << ENDL;
		q.pop();
	}

	return 0;
}
void rec(int idx, int remaining, vector<int>tmpVector) {
	if (idx >= sortedNums.size() && remaining > 0) return;
	if (remaining == 0) {
		q.push(tmpVector);
		return;
	}

	int tmpNum = sortedNums[idx].first;
	int tmpNumCount = sortedNums[idx].second;

	while (tmpNumCount > remaining) tmpNumCount--;

	while (tmpNumCount != -1) {
		vector<int>newVector(tmpVector);
		for (int i = 0; i < tmpNumCount; i++) {
			newVector.push_back(tmpNum);
		}
		rec(idx + 1, remaining - tmpNumCount, newVector);
		tmpNumCount--;
	}

}