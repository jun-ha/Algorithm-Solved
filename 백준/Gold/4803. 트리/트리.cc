#define _CRT_SECURE_NO_WARNINGS
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

typedef struct _graph {
	int vertexNum;
	vector<vector<int>> adjList;
}Graph;

void GraphInit(Graph* g, int vertexNum);
void GraphInsert(Graph* g, int fromV, int toV);
void DFS(Graph* g, int startV, vector<int>& visited, vector<int>& parent, bool* checkTree);
int howManyTrees(Graph* g);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int vNum, eNum;
	int count = 1;

	while (cin >> vNum >> eNum) {
		if (!vNum && !eNum)return 0;
		Graph g;
		GraphInit(&g, vNum);
		for (int i = 0; i < eNum; i++) {
			int v1, v2;
			cin >> v1 >> v2;
			GraphInsert(&g, v1, v2);
			GraphInsert(&g, v2, v1);
		}
		switch (int num = howManyTrees(&g)) {
		case 0: 
			cout << "Case " << count++ << ": No trees.\n";
			break;
		case 1:
			cout << "Case " << count++ << ": There is one tree.\n";
			break;
		default:
			cout << "Case " << count++ << ": A forest of " << num << " trees.\n";
		}
	}
	return 0;
}
void GraphInit(Graph* g, int vertexNum) {
	vector<vector<int>>v(vertexNum + 1);
	g->adjList = v;
	g->vertexNum = vertexNum;
}
void GraphInsert(Graph* g, int fromV, int toV) {
	g->adjList[fromV].push_back(toV);
}

void DFS(Graph* g, int startV, vector<int>& visited, vector<int>& parent, bool* checkTree) {
	if (visited[startV]) {
		if (parent[startV] != startV) {
			*checkTree = false;
		} 
		return;
	}
	visited[startV]++;
	for (auto iter = g->adjList[startV].begin(); iter != g->adjList[startV].end(); iter++) {
		if(*iter == startV) *checkTree = false;
		if (*iter == parent[startV]) continue;
		if (!parent[*iter]) {
			parent[*iter] = startV;
		}
		DFS(g, *iter, visited, parent, checkTree);
	}
	return;
}
int howManyTrees(Graph* g) {
	int treeCount = 0;
	vector<int>visited(g->vertexNum + 1, 0);
	vector<int>parent(g->vertexNum+1, 0);
	bool check = true;
	parent[1] = 1;
	for (int i = 1; i <= g->vertexNum; i++) {
		if (!(visited[i])) {
			bool checkTree = true;
			if (g->adjList[i].size() == 0) {
				treeCount++;
				continue;
			}
			DFS(g, i, visited, parent, &checkTree);
			if (checkTree) {
				treeCount++;
			}
			check = true;
		}
	}
	return treeCount;
}
