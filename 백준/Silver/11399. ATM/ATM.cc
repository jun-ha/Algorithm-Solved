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
	int N; cin >> N;

	vector<int>v;
	for (int i = 0; i < N; i++) {
		int time; cin >> time;
		v.push_back(time);
	}
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 1; i < N; i++) {
		v[i] = v[i] + v[i - 1];
	}
	for (int i = 0; i < N; i++) {
		sum += v[i];
	}
	cout << sum;

	return 0;
}