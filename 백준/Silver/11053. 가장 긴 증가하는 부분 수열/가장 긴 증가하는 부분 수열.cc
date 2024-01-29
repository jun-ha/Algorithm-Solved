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
	int N;
	cin >> N;
	vector<int>nums(N);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		nums[i] = num;
	}
	vector<int>sequence(1001, 0);

	for (int i = 0; i < N; i++) {
		int num = nums[i];
		int maxSequence = 0;
		for (int j = num - 1; j >= 0; j--) {
			if (sequence[j] > maxSequence) maxSequence = sequence[j];
		}
		sequence[num] = maxSequence + 1;
	}

	int maxSequence = 1;
	for (auto x : sequence) {
		if (x > maxSequence) maxSequence = x;
	}

	cout << maxSequence;
	return 0;
}