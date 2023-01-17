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
	int N, M; cin >> N >> M;
	map<string, string>m;
	for (int i = 0; i < N; i++) {
		pair<string, string>cite;
		cin >> cite.first >> cite.second;
		m.insert(cite);
	}
	while (M--) {
		string cite;
		cin >> cite;
		cout << m.find(cite)->second << ENDL;
	}


	return 0;
}