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

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<int>nums(N, 0);
	int num;
	cin >> num;
	nums[0] = num % M;
	for (int i = 1; i < N; i++) {
		int num;
		cin >> num;
		nums[i] = ((num % M) + nums[i - 1]) % M;
	}
	vector<int>mods(M, 0);
	ll answer = 0;
	for (int i = 0; i < N; i++) {
		if (nums[i] == 0) answer++;
		if (mods[nums[i]] > 0) answer += mods[nums[i]];
		mods[nums[i]]++;
	}
	cout << answer << ENDL;
	return 0;
}