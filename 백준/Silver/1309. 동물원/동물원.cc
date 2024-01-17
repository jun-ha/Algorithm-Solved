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
	vector<pair<int, int>>nums(N+1, {0,0});
	nums[0] = { 0, 1 };

	for (int i = 1; i <= N; i++) {
		nums[i].second = (nums[i - 1].first + nums[i - 1].second)%9901;
		nums[i].first = (nums[i - 1].first + nums[i - 1].second * 2)%9901;
	}
	cout << (nums[N].first+nums[N].second) % 9901;
	return 0;
}