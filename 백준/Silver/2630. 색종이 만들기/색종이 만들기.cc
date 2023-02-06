#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <queue>
#define ENDL '\n'

using namespace std;
using ll = long long;

void seperatePaper(vector<vector<bool>>& paper, int srow, int scol, int n, int& white, int& blue);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<vector<bool>>paper(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num; cin >> num;
			if (num) paper[i].push_back(true);
			else paper[i].push_back(false);
		}
	}
	int white = 0, blue = 0;
	seperatePaper(paper, 0, 0, N, white, blue);
	cout << white << ENDL << blue;
	return 0;
}
void seperatePaper(vector<vector<bool>>& paper, int srow, int scol, int n, int& white, int& blue){
	bool sameCheck = paper[srow][scol];
	for (int i = srow; i < srow+n; i++) {
		for (int j = scol; j < scol + n; j++) {
			if (paper[i][j] != sameCheck) {
				seperatePaper(paper, srow, scol, n / 2, white, blue);
				seperatePaper(paper, srow+n/2, scol, n / 2, white, blue);
				seperatePaper(paper, srow, scol+n/2, n / 2, white, blue);
				seperatePaper(paper, srow+n/2, scol+n/2, n / 2, white, blue);
				return;
			}
		}
	}
	if (sameCheck) {
		blue++;
		return;
	}
	white++;
}