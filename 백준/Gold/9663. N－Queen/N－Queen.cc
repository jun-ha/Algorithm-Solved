#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#define ENDL '\n'

using namespace std;
using ll = long long;

int cnt = 0; 
void dfs(vector<int>& chessBoard, int tmpCol) {
	if (tmpCol == chessBoard.size()) {
		cnt++;
		return;
	}

	for(int i = 0; i < chessBoard.size(); i++){
		bool isAvailable = true;
		for (int col = 0; col < tmpCol; col++) {
			if (chessBoard[col] == i || abs(tmpCol - col) == abs(chessBoard[col] - i)) {
				isAvailable = false;
				break;
			}
		}
		if (isAvailable) {
			chessBoard[tmpCol] = i;
			dfs(chessBoard, tmpCol + 1);
		}
	}

}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	vector<int>chessBoard(N, 0);
	dfs(chessBoard, 0);
	cout << cnt;

	return 0;
}