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
#include <unordered_set>
#include <climits>
#define ENDL '\n'

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	int count = 1;
	while (T--) {
		int N; cin >> N;
		vector<int>scores(N, 0);
		vector<bool>visited(10001, false);
		vector<int>possibleScores;

		for (int i = 0; i < N; i++) {
			cin >> scores[i];
		}

		visited[0] = true;
		possibleScores.push_back(0);

		for (int score : scores) {
			int tmpSize = possibleScores.size();
			for (int i = 0; i < tmpSize; i++) {
				int nextScore = score + possibleScores[i];
				if (visited[nextScore] == false) {
					visited[nextScore] = true;
					possibleScores.push_back(nextScore);
				}
			}
		}
		cout << "#" << count++ << " " << possibleScores.size() << ENDL;
	}
	return 0;
}