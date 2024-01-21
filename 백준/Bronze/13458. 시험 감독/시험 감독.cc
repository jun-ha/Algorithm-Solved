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
	vector<int>candidate(N);
	for (int i = 0; i < N; i++) {
		cin >> candidate[i];
	}
	int mainProctor, subProctor;
	cin >> mainProctor >> subProctor;

	ll sum = N;
	for (auto x : candidate) {
		int last = x - mainProctor;
		if (last > 0) {
			int needSub = last / subProctor;
			if (subProctor * needSub < last) needSub++;
			sum += needSub;
		}
	}
	cout << sum;


	return 0;
}