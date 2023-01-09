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

using p = pair<int, int>;
typedef struct _graph {
	int vertexNum;
	vector<vector<p>> adjList;
}Graph;

void GraphInit(Graph* g, int vertexNum);
void GraphInsert(Graph* g, int fromV, int toV, int weight);
void GraphSort(Graph* g);
void GraphPrint(Graph* g);
int DFS(Graph* g, int startV, int weight, vector<int>& check, int* lastV);
int findDiameterOfTree(Graph* g);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int vNum; cin >> vNum;
	Graph g;
	GraphInit(&g, vNum);
	for (int i = 1; i < vNum+1; i++) {
		int vertex; cin >> vertex;
		while (1) {
			int toV, weight;
			cin >> toV;
			if (toV == -1) break;
			cin >> weight;
			GraphInsert(&g, vertex, toV, weight);
		}
	}
	GraphSort(&g);
	cout << findDiameterOfTree(&g);
	return 0;
}
void GraphInit(Graph* g, int vertexNum) {
	vector<vector<p>>v(vertexNum+1);
	g->adjList = v;
	g->vertexNum = vertexNum;
}
void GraphInsert(Graph* g, int fromV, int toV, int weight) {
	g->adjList[fromV].push_back(make_pair(toV, weight));
}
bool comp(p a, p b) {
	return a.first < b.first;
}
void GraphSort(Graph* g) {
	for (int i = 0; i <= g->vertexNum; i++) {
		sort(g->adjList[i].begin(), g->adjList[i].end(), comp);
	}
}
void GraphPrint(Graph* g) {
	for (int i = 0; i <= g->vertexNum; i++) {
		cout << i << ' ';
		for (auto iter = g->adjList[i].begin(); iter != g->adjList[i].end(); iter++) {
			cout << iter->first << ' ' << iter->second << "  ";
		}
		cout << ENDL;
	}
}
int DFS(Graph* g, int startV, int weight, vector<int>& check, int* lastV) {
	if (check[startV]) {
		return 0;
	}
	*lastV = startV;
	check[startV]++;
	int longest = 0;
	for (auto iter = g->adjList[startV].begin(); iter != g->adjList[startV].end(); iter++) {
		int last;
		int length = DFS(g, iter->first, iter->second, check, &last);
		if (longest < length) {
			longest = length;
			*lastV = last;
		}
	}
	return longest + weight;
}
int findDiameterOfTree(Graph* g) {
	int Diameter;
	int lastV1, lastV2;
	vector<int>check1(g->vertexNum+1, 0);
	vector<int>check2(g->vertexNum+1, 0);
	DFS(g, 1, 0, check1, &lastV1);
	Diameter = DFS(g, lastV1, 0, check2, &lastV2);
	return Diameter;
}

