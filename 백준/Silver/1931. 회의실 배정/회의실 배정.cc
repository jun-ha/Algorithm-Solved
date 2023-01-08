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

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	pair<int, int>p;
	int N; cin >> N;
	vector<pair<int, int>>v;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		p.first = start;
		p.second = end;
		v.push_back(p);
	}
	sort(v.begin(), v.end(), comp);
	int tmpEnd = -1;
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (v[i].first >= tmpEnd) {
			count++;
			tmpEnd = v[i].second;
		}
	}
	cout << count;
	return 0;
}