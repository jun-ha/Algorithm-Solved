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

void dfs(int N, int M, int now, vector<int>&v) {

	if (v.size() == M) {
		for (int num : v) {
			cout << num << " ";
		}
		cout << ENDL;
		return;
	}
	if (now > N) return;

	v.push_back(now);
	dfs(N, M, now + 1, v);
	v.erase(v.end() - 1);
	dfs(N, M, now + 1, v);
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	vector<int>v;
	dfs(N, M, 1, v);

	return 0;
}