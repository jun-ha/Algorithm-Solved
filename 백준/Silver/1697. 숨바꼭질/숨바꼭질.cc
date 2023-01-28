#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <queue>
#define ENDL '\n'

using namespace std;
int Subin, Brother;
int visited[100005] = { 0, };
bool BFS(queue<int>& q);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> Subin >> Brother;
	int count = 0;
	queue<int>q;
	q.push(Subin);
	visited[Subin]++;
	while (BFS(q)) count++;
	cout << count;
	return 0;
}
bool BFS(queue<int>& q) {
	int len = q.size();
	for (int i = 0; i < len; i++) {
		int tmp = q.front();
		q.pop();
		if (tmp == Brother) return false;
		if (tmp > Brother) {
			if (!(visited[tmp - 1]++)) {
				q.push(tmp - 1);
			}
		}
		else {
			if (tmp -1 >= 0 && !(visited[tmp - 1]++)) {
				q.push(tmp - 1);
			}
			if (!(visited[tmp + 1]++)) {
				q.push(tmp + 1);
			}
			if (tmp * 2 <= 100000 && !(visited[tmp * 2]++)) {
				q.push(tmp * 2);
			}
		}

	}
	return true;
}