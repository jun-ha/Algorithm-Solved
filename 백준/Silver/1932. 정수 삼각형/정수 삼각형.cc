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
	vector<vector<int>>triangle(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int num;
			cin >> num;
			triangle[i].push_back(num);
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				triangle[i][j] += triangle[i - 1][j];
			}
			else if (j == i) {
				triangle[i][j] += triangle[i - 1][j - 1];
			}
			else {
				triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
			}
		}
	}
	int maxValue = 0;
	for (auto x : triangle[n - 1]) {
		if (x > maxValue) maxValue = x;
	}
	cout << maxValue;


	return 0;
}