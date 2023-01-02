#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <set>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		multiset<int> min;
		multiset<int, greater<int>>max;
		multiset<int>::iterator minIter;
		multiset<int, greater<int>>::iterator maxIter;
		int K; cin >> K;
		char order;
		int num;
		while (K--) {
			cin >> order >> num;
			if (order == 'I') {
				min.insert(num);
				max.insert(num);
			}
			else {
				if (min.empty()) continue;
				if (num == 1) {
					maxIter = max.begin();
					min.erase(min.find(*maxIter));
					max.erase(max.begin());
				}
				else {
					minIter = min.begin();
					max.erase(max.find(*minIter));
					min.erase(min.begin());
				}
			}
		}
		if (min.empty()) {
			cout << "EMPTY" << ENDL;
		}
		else {
			cout << *max.begin() << ' ' << *min.begin() << ENDL;
		}
	}


	return 0;
}