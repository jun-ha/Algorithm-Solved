#include <iostream>
#include <vector>
#include <stack>

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

	stack<int>s;
	stack<int>answer;

	for (int i = nums.size() - 1; i >= 0; i--) {

		while (!s.empty()) {
			if (cntVec[s.top()] <= cntVec[nums[i]]) s.pop();
			else break;
		}

		if (!s.empty()) answer.push(s.top());
		else answer.push(-1);

		s.push(nums[i]);
	}

	while (!answer.empty()) {
		cout << answer.top() << " ";
		answer.pop();
	}

	return 0;
}