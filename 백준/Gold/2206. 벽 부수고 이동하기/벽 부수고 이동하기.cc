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
#define ENDL '\n'
#define WALL true
#define PATH false
#define hasBrokenWall true
#define unBrokenWall false
#define ROW true
#define COL false
using namespace std;
using ll = long long;

enum wallKind {
	UP_WALL,
	DOWN_WALL,
	LEFT_WALL,
	RIGHT_WALL
};

int graphRow, graphCol;
int BIG_NUM = 999999;
void bfs(vector<vector<bool>>& graph, vector<vector<pair<int, int>>>& cost);
bool isValidIDX(int idx, bool row_or_col);
bool isBreakableWall(vector<vector<bool>>& graph, int row, int col, wallKind wall, vector<pair<int, int>>& possiblePathes);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> graphRow >> graphCol;
	if (graphRow == 1 && graphCol == 1) {
		cout << 1;
		return 0;
	}
	vector<vector<bool>>graph(graphRow, vector<bool>(graphCol));
	vector<vector<pair<int, int>>>cost(graphRow, vector<pair<int, int>>(graphCol, make_pair(BIG_NUM, BIG_NUM)));

	for (int i = 0; i < graphRow; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < graphCol; j++) {
			if (line[j] - '0') graph[i][j] = WALL;
			else graph[i][j] = PATH;
		}
	}

	bfs(graph, cost);
	int shortest = min(cost[graphRow - 1][graphCol - 1].first, cost[graphRow - 1][graphCol - 1].second);
	if (shortest == BIG_NUM) shortest = -1;
	cout << shortest;


	return 0;
}
void bfs(vector<vector<bool>>& graph, vector<vector<pair<int, int>>>& cost) {
	queue < tuple<int, int, int, bool> > q; //#1 row, #2 col, #3 cost, #4 state(has broken wall?)
	q.push(make_tuple(0, 0, 1, unBrokenWall));
	while (!q.empty()) {
		int row = get<0>(q.front());
		int col = get<1>(q.front());
		int tmpCost = get<2>(q.front());
		int state = get<3>(q.front());
		q.pop();

		if (state == hasBrokenWall) {
			if (isValidIDX(row - 1, ROW) && graph[row -1][col] == PATH) {
				if (tmpCost + 1 < cost[row - 1][col].first && tmpCost + 1 < cost[row - 1][col].second) {
					q.push(make_tuple(row - 1, col, tmpCost + 1, hasBrokenWall));
					cost[row - 1][col].second = tmpCost + 1;
				}
			}
			if (isValidIDX(row + 1, ROW) && graph[row + 1][col] == PATH) {
				if (tmpCost + 1 < cost[row + 1][col].first && tmpCost + 1 < cost[row + 1][col].second) {
					q.push(make_tuple(row + 1, col, tmpCost + 1, hasBrokenWall));
					cost[row + 1][col].second = tmpCost + 1;
				}
			}
			if (isValidIDX(col - 1, COL) && graph[row][col - 1] == PATH) {
				if (tmpCost + 1 < cost[row][col - 1].first && tmpCost + 1 < cost[row][col - 1].second) {
					q.push(make_tuple(row, col - 1, tmpCost + 1, hasBrokenWall));
					cost[row][col - 1].second = tmpCost + 1;
				}
			}
			if (isValidIDX(col + 1, COL) && graph[row][col + 1] == PATH) {
				if (tmpCost + 1 < cost[row][col + 1].first && tmpCost + 1 < cost[row][col + 1].second) {
					q.push(make_tuple(row, col + 1, tmpCost + 1, hasBrokenWall));
					cost[row][col + 1].second = tmpCost + 1;
				}
			}
		}

		if (state == unBrokenWall) {
			if (isValidIDX(row - 1, ROW)) {
				vector<pair<int, int>>possiblePathes;
				if (graph[row - 1][col] == WALL) {
					if (isBreakableWall(graph, row, col, UP_WALL, possiblePathes)) {
						for (auto x : possiblePathes) { //break the wall
							int tmpRow = x.first;
							int tmpCol = x.second;
							if (tmpCost + 2 < cost[tmpRow][tmpCol].first && tmpCost + 2 < cost[tmpRow][tmpCol].second) {
								q.push(make_tuple(tmpRow, tmpCol, tmpCost + 2, hasBrokenWall));
								cost[tmpRow][tmpCol].second = tmpCost + 2;
							}
						}
					}
				}
				if (graph[row - 1][col] == PATH) {
					if (tmpCost + 1 < cost[row - 1][col].first) {
						q.push(make_tuple(row - 1, col, tmpCost + 1, unBrokenWall));
						cost[row - 1][col].first = tmpCost + 1;
					}
				}
			}
			if (isValidIDX(row + 1, ROW)) {
				vector<pair<int, int>>possiblePathes;
				if (graph[row + 1][col] == WALL) {
					if (isBreakableWall(graph, row, col, DOWN_WALL, possiblePathes)) {
						for (auto x : possiblePathes) { //break the wall
							int tmpRow = x.first;
							int tmpCol = x.second;
							if (tmpCost + 2 < cost[tmpRow][tmpCol].first && tmpCost + 2 < cost[tmpRow][tmpCol].second) {
								q.push(make_tuple(tmpRow, tmpCol, tmpCost + 2, hasBrokenWall));
								cost[tmpRow][tmpCol].second = tmpCost + 2;
							}
						}
					}
				}
				if (graph[row + 1][col] == PATH) {
					if (tmpCost + 1 < cost[row + 1][col].first) {
						q.push(make_tuple(row + 1, col, tmpCost + 1, unBrokenWall));
						cost[row + 1][col].first = tmpCost + 1;
					}
				}
			}
			if (isValidIDX(col - 1, COL)) {
				vector<pair<int, int>>possiblePathes;
				if (graph[row][col - 1] == WALL) {
					if (isBreakableWall(graph, row, col, LEFT_WALL, possiblePathes)) {
						for (auto x : possiblePathes) { //break the wall
							int tmpRow = x.first;
							int tmpCol = x.second;
							if (tmpCost + 2 < cost[tmpRow][tmpCol].first && tmpCost + 2 < cost[tmpRow][tmpCol].second) {
								q.push(make_tuple(tmpRow, tmpCol, tmpCost + 2, hasBrokenWall));
								cost[tmpRow][tmpCol].second = tmpCost + 2;
							}
						}
					}
				}
				if (graph[row][col - 1] == PATH) {
					if (tmpCost + 1 < cost[row][col - 1].first) {
						q.push(make_tuple(row, col - 1, tmpCost + 1, unBrokenWall));
						cost[row][col - 1].first = tmpCost + 1;
					}
				}
			}
			if (isValidIDX(col + 1, COL)) {
				vector<pair<int, int>>possiblePathes;
				if (graph[row][col + 1] == WALL) {
					if (isBreakableWall(graph, row, col, RIGHT_WALL, possiblePathes)) {
						for (auto x : possiblePathes) { //break the wall
							int tmpRow = x.first;
							int tmpCol = x.second;
							if (tmpCost + 2 < cost[tmpRow][tmpCol].first && tmpCost + 2 < cost[tmpRow][tmpCol].second) {
								q.push(make_tuple(tmpRow, tmpCol, tmpCost + 2, hasBrokenWall));
								cost[tmpRow][tmpCol].second = tmpCost + 2;
							}
						}
					}
				}
				if (graph[row][col + 1] == PATH) {
					if (tmpCost + 1 < cost[row][col + 1].first) {
						q.push(make_tuple(row, col + 1, tmpCost + 1, unBrokenWall));
						cost[row][col + 1].first = tmpCost + 1;
					}
				}
			}
		}
	}
}
bool isValidIDX(int idx, bool row_or_col) {
	if (row_or_col == ROW) {
		if (0 <= idx && idx < graphRow) return true;
	}
	if (row_or_col == COL) {
		if (0 <= idx && idx < graphCol) return true;
	}
	return false;
}
bool isBreakableWall(vector<vector<bool>>& graph, int row, int col, wallKind wall, vector<pair<int, int>>& possiblePathes) {
	if (wall == UP_WALL) {
		if (isValidIDX(row - 2, ROW) && graph[row - 2][col] == PATH) {
			possiblePathes.push_back(make_pair(row - 2, col));
			return true;
		}
			
		if (isValidIDX(row - 1, ROW) && isValidIDX(col - 1, COL) && graph[row - 1][col - 1] == PATH) {
			possiblePathes.push_back(make_pair(row - 1, col - 1));
			return true;
		}
		if (isValidIDX(row - 1, ROW) && isValidIDX(col + 1, COL) && graph[row - 1][col + 1] == PATH) {
			possiblePathes.push_back(make_pair(row - 1, col + 1));
			return true;
		}
	}
	if (wall == DOWN_WALL) {
		if (isValidIDX(row + 2, ROW) && graph[row + 2][col] == PATH) {
			possiblePathes.push_back(make_pair(row + 2, col));
			return true;
		}
		if (isValidIDX(row + 1, ROW) && isValidIDX(col - 1, COL) && graph[row + 1][col - 1] == PATH) {
			possiblePathes.push_back(make_pair(row + 1, col - 1));
			return true;
		}
		if (isValidIDX(row + 1, ROW) && isValidIDX(col + 1, COL) && graph[row + 1][col + 1] == PATH) {
			possiblePathes.push_back(make_pair(row + 1, col + 1));
			return true;
		}
	}
	if (wall == LEFT_WALL) {
		if (isValidIDX(col - 2, COL) && graph[row][col - 2] == PATH) {
			possiblePathes.push_back(make_pair(row, col - 2));
			return true;
		}
		if (isValidIDX(col - 1, COL) && isValidIDX(row - 1, ROW) && graph[row - 1][col - 1] == PATH) {
			possiblePathes.push_back(make_pair(row - 1, col - 1));
			return true;
		}
		if (isValidIDX(col - 1, COL) && isValidIDX(row + 1, ROW) && graph[row + 1][col - 1] == PATH) {
			possiblePathes.push_back(make_pair(row  + 1, col - 1));
			return true;
		}
	}
	if (wall == RIGHT_WALL) {
		if (isValidIDX(col + 2, COL) && graph[row][col + 2] == PATH) {
			possiblePathes.push_back(make_pair(row, col + 2));
			return true;
		}
		if (isValidIDX(col + 1, COL) && isValidIDX(row - 1, ROW) && graph[row - 1][col + 1] == PATH) {
			possiblePathes.push_back(make_pair(row - 1, col + 1));
			return true;
		}
		if (isValidIDX(col + 1, COL) && isValidIDX(row + 1, ROW) && graph[row + 1][col + 1] == PATH) {
			possiblePathes.push_back(make_pair(row + 1, col + 1));
			return true;
		}
	}
	return false;
}
