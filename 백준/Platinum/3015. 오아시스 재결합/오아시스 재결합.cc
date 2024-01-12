#include <iostream>
#include <vector>
#include <stack>

#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	stack<pair<int, int>>s;
	int height;
	ll count = 0;
	ll sameCount = 0;
	for (int i = 0; i < N; i++) {
		int height;
		cin >> height;
		if (s.empty()) {
			s.push({ height, 1 });
			continue;
		}
		if (height > s.top().first) { //INCREASE
			while (!s.empty() && s.top().first < height) {
				count += s.top().second;
				s.pop();
			}
			int sameCount = 0;
			while (!s.empty() && s.top().first == height) {
				count += s.top().second;
				sameCount += s.top().second;
				s.pop();
			}
			if (!s.empty()) count++;
			if (sameCount != 0) {
				s.push({ height, sameCount + 1 });
				continue;
			}
		}
		else if(height < s.top().first) { //DECREASE
			count++;
		}
		else { //SAME
			int sameCount = 0;
			while (!s.empty() && s.top().first == height) {
				count += s.top().second;
				sameCount += s.top().second;
				s.pop();
			}
			if (!s.empty()) count++;
			s.push({ height, sameCount + 1 });
			continue;
		}
		s.push({ height , 1 });
	}
	cout << count;

	return 0;
}
