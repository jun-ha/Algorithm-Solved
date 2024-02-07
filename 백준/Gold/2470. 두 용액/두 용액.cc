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
	vector<int>values(N);
	for (int i = 0; i < N; i++) {
		cin >> values[i];
	}
	sort(values.begin(), values.end());
	int front = 0, back = N - 1;
	pair<int, int>solution = make_pair(values[front], values[back]);
	int min = abs(values[front] + values[back]);
	while (front < back) {
		int tmpSum = values[front] + values[back];
		int tmpABS = abs(values[front] + values[back]);
		if (tmpSum == 0) {
			cout << values[front] << " " << values[back];
			return 0;
		}
		else if (tmpSum < 0) {
			if (tmpABS < min) {
				min = tmpABS;
				solution = make_pair(values[front], values[back]);
			}
			front++;
		}
		else {
			if (tmpABS < min) {
				min = tmpABS;
				solution = solution = make_pair(values[front], values[back]);
			}
			back--;
		}
	}
	cout << solution.first << " " << solution.second;

	return 0;
}