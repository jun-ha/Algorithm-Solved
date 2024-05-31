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
	int N; cin >> N;
	vector<pair<ll, ll>>positions;
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		positions.push_back({ x, y });
	}
	positions.push_back(positions[0]);
	
	double area = 0;
	for (int i = 0; i < positions.size() - 1; i++) {
		area += positions[i].first * positions[i + 1].second;
		area -= positions[i].second * positions[i + 1].first;
	}
	area /= 2;
	area = fabs(area);
	cout << fixed;
	cout.precision(1);
	cout << area;

	return 0;
}