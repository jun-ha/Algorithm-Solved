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
void bfs(int start, int destination);
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int subin, brother; cin >> subin >> brother;
	if (subin == brother) {
		cout << 0 << ENDL << subin;
		return 0;
	}
	bfs(subin, brother);
	return 0;
}
void bfs(int start, int destination) {
	queue<tuple<int, int, int>>q; //pos, before pos, count
	vector<int>visited(100001, -1);
	q.push({ start, start, 0 });
	while (!q.empty()) {
		int tmpPos = get<0>(q.front());
		int beforePos = get<1>(q.front());
		int tmpCount = get<2>(q.front());
		q.pop();
		if (visited[tmpPos] != -1) continue;
		visited[tmpPos] = beforePos;
		if (tmpPos == destination) {
			cout << tmpCount << ENDL;
			break;
		}

		if (tmpPos < destination) {
			q.push({ tmpPos + 1, tmpPos, tmpCount + 1 });
			if (tmpPos - 1 >= 0) {
				q.push({ tmpPos - 1, tmpPos, tmpCount + 1 });
			}
			if(tmpPos*2 <= 100000) q.push({ tmpPos*2, tmpPos, tmpCount + 1 });
		}
		else {
			q.push({ tmpPos - 1, tmpPos, tmpCount + 1 });
		}

	}
	int tmpIDX = destination;
	stack<int>path;
	path.push(destination);
	while (visited[tmpIDX] != start) {
		path.push(visited[tmpIDX]);
		tmpIDX = visited[tmpIDX];
	}
	path.push(start);
	while (!path.empty()) {
		cout << path.top() << " ";
		path.pop();
	}
}