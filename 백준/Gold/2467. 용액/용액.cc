#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int>acid;
	vector<int>alkaline;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		if (num > 0) acid.push_back(num);
		else alkaline.push_back(num);
	}

	int minSum = INT_MAX;
	pair<int, int>answer;

	if (acid.size() >= 2) {
		minSum = acid[0] + acid[1];
		answer = { acid[0], acid[1] };
	}

	if (alkaline.size() >= 2) {
		int sum = alkaline[alkaline.size() - 1] + alkaline[alkaline.size() - 2];
		if (minSum > abs(sum)) {
			minSum = abs(sum);
			answer = { alkaline[alkaline.size() - 2] , alkaline[alkaline.size() - 1] };
		}
	}

	if (acid.empty() || alkaline.empty()) {
		cout << answer.first << " " << answer.second;
		return 0;
	}

	for (int i = 0; i < acid.size(); i++) {
		int tmp = acid[i];
		if (alkaline.back() < -tmp) {
			if (minSum > abs(tmp + alkaline.back())) {
				minSum = abs(tmp + alkaline.back());
				answer = { alkaline.back(), tmp};
			}
			continue;
		}
		else if (-tmp < alkaline.front()) {
			if (minSum > abs(tmp + alkaline.front())) {
				minSum = abs(tmp + alkaline.front());
				answer = { alkaline.front(), tmp };
			}
			continue;
		}


		int idx = lower_bound(alkaline.begin(), alkaline.end(), -tmp) - alkaline.begin();
		if (alkaline[idx] == -tmp) {
			cout << alkaline[idx] << " " << tmp;
			return 0;
		}
		if (minSum > abs(tmp + alkaline[idx])) {
			minSum = abs(tmp + alkaline[idx]);
			answer = { alkaline[idx], tmp };
		}

		idx--;

		if (minSum > abs(tmp + alkaline[idx])) {
			minSum = abs(tmp + alkaline[idx]);
			answer = { alkaline[idx], tmp };
		}
	}

	cout << answer.first << " " << answer.second;

	return 0;
}