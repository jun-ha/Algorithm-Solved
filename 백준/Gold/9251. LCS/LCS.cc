#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str1, str2;
	cin >> str1 >> str2;
	vector<vector<int>>dp(str1.length() + 1, vector<int>(str2.length() + 1, 0));
	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i-1] != str2[j-1]) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
	}
	cout << dp[str1.length()][str2.length()];


	return 0;
}