#include <iostream>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int>nums(N, 0);
	vector<int>cntVec(1000001, 0);
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		nums[i] = num;
		cntVec[num]++;
	}

	vector<pair<int, int>>answerVec(N, { 0,0 });
	for (int i = answerVec.size() - 1; i >= 0; i--) {
		int tmpCnt = cntVec[nums[i]];
		int idx = i + 1;
		bool find = false;
		while (idx < answerVec.size()) {
			if (cntVec[nums[idx]] < tmpCnt) {
				idx = answerVec[idx].second;
				continue;
			}

			if (cntVec[nums[idx]] > tmpCnt) {
				answerVec[i] = {nums[idx], idx};
			}
			else {
				answerVec[i] = answerVec[idx];
			}
			find = true;
			break;
		}

		if (!find) answerVec[i] = { -1, -1 };
	}

	for (pair<int, int>p : answerVec) {
		cout << p.first << " ";
	}


	return 0;
}