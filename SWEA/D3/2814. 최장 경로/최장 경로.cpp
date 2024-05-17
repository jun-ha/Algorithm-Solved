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

int dfs_to_find_longest(vector<vector<bool>>& route, vector<bool>& visited, int startIdx, int length) {
	int longest = length;
	for (int i = 1; i < route.size(); i++) {
		if (route[startIdx][i] && visited[i] == false) {
			visited[i] = true;
			longest = max(longest, dfs_to_find_longest(route, visited, i, length+1));
			visited[i] = false;
		}
	}
	return longest;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	int count = 1;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<vector<bool>>route(N+1, vector<bool>(N+1, false));
		vector<bool>visited(N+1, false);
		for (int i = 0; i < M; i++) {
			int n1, n2;
			cin >> n1 >> n2;
			route[n1][n2] = true;
			route[n2][n1] = true;
		}
		int longest = -1;
		for (int i = 1; i <= N; i++) {
			visited[i] = true;
			longest = max(longest, dfs_to_find_longest(route, visited, i, 1));
			visited[i] = false;
		}



		cout << "#" << count++ << " " << longest<< ENDL;
	}


	return 0;
}