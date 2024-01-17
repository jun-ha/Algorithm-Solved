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
	int T;
	cin >> T;
	vector<int>nums(1000001, 0);
	nums[1] = 1;
	nums[2] = 2;
	nums[3] = 4;
	nums[4] = 7;

	for (int i = 5; i <= 1000000; i++) {
		nums[i] = (((nums[i - 1] + nums[i - 2]) %1000000009) + nums[i - 3]) % 1000000009;
	}
	while (T--) {
		int n;
		cin >> n;
		cout << nums[n] << ENDL;
	}


	return 0;
}