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
using ll = long long;
bool BFS(queue<int>& q);
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	queue<int>q;
	q.push(N);
	int count = 0;
	while (BFS(q)) count++;
	cout << count;
	return 0;
}
bool BFS(queue<int>& q) {
	int len = q.size();
	for (int i = 0; i < len; i++) {
		int k = q.front();
		q.pop();
		if (k == 1) return false;
		if (!(k % 3) && k / 3 >= 1) q.push(k / 3);
		if (!(k % 2) && k/2>=1) q.push(k / 2);
		q.push(k - 1);
	}
	return true;
}