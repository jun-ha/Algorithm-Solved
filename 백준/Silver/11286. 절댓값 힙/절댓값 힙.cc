#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	multimap<int, bool> mp;
	multimap<int, bool>::iterator iter;
	while (T--) {
		int x; cin >> x;
		if (x) {
			if (x > 0) {
				mp.insert({ x, true });
			}
			else {
				mp.insert({ -x, false });
			}
		}
		else {
			if (mp.empty()) {
				cout << 0 << ENDL;
				continue;
			}
			int find = mp.begin()->first;
			bool flag = false;
			for (iter = mp.begin(); iter != mp.end(); iter++) {
				if (iter->first != find) break;
				if (!iter->second) {
					cout << -find << ENDL;
					mp.erase(iter);
					flag = true;
					break;
				}
			}
			if (flag) continue;
			cout << find << ENDL;
			mp.erase(mp.begin());
		}
	}
	return 0;
}