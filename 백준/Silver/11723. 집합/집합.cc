#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	set<int>s;
	set<int> empty;
	set<int>all;
	for (int i = 1; i <= 20; i++) {
		all.insert(i);
	}
	int M; cin >> M;
	while (M--) {
		string mode; int num;
		cin >> mode;
		if (mode == "add") {
			cin >> num;
			s.insert(num);
		}
		else if (mode == "remove") {
			cin >> num;
			if(s.find(num) != s.end()) s.erase(s.find(num));
		}
		else if (mode == "check") {
			cin >> num;
			if (s.find(num) != s.end()) cout << "1\n";
			else cout << "0\n";
		}
		else if (mode == "toggle") {
			cin >> num;
			if (s.find(num) != s.end()) s.erase(s.find(num));
			else s.insert(num);
		}
		else if (mode == "all") {
			s = all;
		}
		else {
			s = empty;
		}
	}


	return 0;
}