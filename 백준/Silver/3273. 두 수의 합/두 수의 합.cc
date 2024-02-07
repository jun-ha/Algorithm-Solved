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
	int n;
	cin >> n;
	vector<int>nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int x;
	cin >> x;
	sort(nums.begin(), nums.end());
	int front = 0, back = n - 1;
	int count = 0;
	while (front < back) {
		if (nums[front] + nums[back] == x) {
			count++;
			front++;
			back--;
		}
		else if (nums[front] + nums[back] < x) {
			front++;
		}
		else {
			back--;
		}
	}
	cout << count;
	return 0;
}