#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<int>v(N+1,0);
	v[0] = 0;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		v[i] = v[i - 1] + num;
	}
	while (M--) {
		int i, j; cin >> i >> j;
		if (i==1) {
			cout << v[j] << ENDL;
		}
		else {
			cout << v[j] - v[i - 1] << ENDL;

		}
	}
	return 0;
}