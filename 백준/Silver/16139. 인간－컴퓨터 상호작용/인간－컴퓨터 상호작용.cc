#include <iostream>
#include <vector>
#include <string>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string original; cin >> original;
	vector<vector<int>>accumulated(original.length(), vector<int>('z' - 'a' + 1, 0));
	accumulated[0][original[0] - 'a']++;
	for (int i = 1; i < original.length(); i++) {
		accumulated[i].assign(accumulated[i - 1].begin(), accumulated[i - 1].end());
		accumulated[i][original[i] - 'a']++;
	}
	int q; cin >> q;
	while (q--) {
		char find;
		int start, end;
		cin >> find >> start >> end;

		if (start == 0) cout << accumulated[end][find - 'a'] << ENDL;
		else cout << accumulated[end][find - 'a'] - accumulated[start - 1][find - 'a'] << ENDL;
	}

	return 0;
}