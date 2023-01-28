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
	set<string>aa;
	set<string>bb;
	int a, b; cin >> a >> b;
	for (int i = 0; i < a; i++) {
		string str; cin >> str;
		aa.insert(str);
	}
	for (int i = 0; i < b; i ++) {
		string str; cin >> str;
		bb.insert(str);
	}
	int count = 0;
	vector<string>output;
	int k = a < b ? a : b;
	if (k == a) {
		for (auto x : aa) {
			if (bb.find(x) != bb.end()) {
				output.push_back(x);
				count++;
			}
		}
	}
	else {
		for (auto x : bb) {
			if (aa.find(x) != aa.end()) {
				output.push_back(x);
				count++;
			}
		}
	}
	cout << count << ENDL;
	for (auto x : output) {
		cout << x << ENDL;
	}

	return 0;
}