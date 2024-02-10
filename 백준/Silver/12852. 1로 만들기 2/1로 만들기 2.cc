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
	int N; cin >> N;
	queue<tuple<int, int, vector<int>>>q;
	q.push({ 0, N, {N} });
	vector<bool>visited(N + 1, false);
	while (!q.empty()) {
		int tmpCount = get<0>(q.front());
		int tmpNum = get<1>(q.front());
		vector<int>tmpPath(get<2>(q.front()));
		q.pop();
		if (visited[tmpNum]) continue;
		visited[tmpNum] = true;
		if (tmpNum == 1) {
			cout << tmpCount << ENDL;
			for (auto x : tmpPath) {
				cout << x << " ";
			}
			return 0;
		}

		vector<int>path1(tmpPath);
		path1.push_back(tmpNum - 1);
		q.push({ tmpCount + 1, tmpNum - 1, path1 });
		
		if (tmpNum % 2 == 0) {
			vector<int>path2(tmpPath);
			path2.push_back(tmpNum / 2);
			q.push({ tmpCount + 1, tmpNum / 2, path2 });
		}
		if (tmpNum % 3 == 0) {
			vector<int>path3(tmpPath);
			path3.push_back(tmpNum / 3);
			q.push({ tmpCount + 1, tmpNum / 3, path3 });
		}
	}

	return 0;
}