#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ENDL '\n'

#define INF 9999999

using namespace std;

void Dijkstra(vector<vector<pair<int, int>>>& pathTable, vector<int>& shortestPath, int start);

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	int vertexNum, edgeNum, destCandidateSiteNum;
	int start, mustV1, mustV2;
	while (T--) {
		cin >> vertexNum >> edgeNum >> destCandidateSiteNum;
		cin >> start >> mustV1 >> mustV2;
		vector<vector<pair<int, int>>>pathTable(vertexNum + 1, vector<pair<int, int>>());
		vector<int>shortestPathOfStart(vertexNum + 1, INF);
		vector<int>shortestPathOfMustV1(vertexNum + 1, INF);
		vector<int>shortestPathOfMustV2(vertexNum + 1, INF);
		vector<int>destCandidateSites;
		int mustPathLen;
		for (int i = 0; i < edgeNum; i++) {
			int v1, v2, weight;
			cin >> v1 >> v2 >> weight;
			pathTable[v1].push_back({ v2, weight });
			pathTable[v2].push_back({ v1, weight });
			if (v1 == mustV1 || v1 == mustV2) {
				if (v2 == mustV1 || v2 == mustV2) {
					mustPathLen = weight;
				}
			}
		}
		for (int i = 0; i < destCandidateSiteNum; i++) {
			int site;
			cin >> site;
			destCandidateSites.push_back(site);
		}
		sort(destCandidateSites.begin(), destCandidateSites.end());
		Dijkstra(pathTable, shortestPathOfStart, start);
		Dijkstra(pathTable, shortestPathOfMustV1, mustV1);
		Dijkstra(pathTable, shortestPathOfMustV2, mustV2);
	
		for (auto x : destCandidateSites) {
			if (shortestPathOfStart[x] >= INF) continue;
			if (shortestPathOfStart[x] == shortestPathOfStart[mustV1] + mustPathLen + shortestPathOfMustV2[x]) {
				cout << x << " ";
			}
			else if (shortestPathOfStart[x] == shortestPathOfStart[mustV2] + mustPathLen + shortestPathOfMustV1[x]) {
				cout << x << " ";
			}
		}
		cout << ENDL;
	}


	return 0;
}
void Dijkstra(vector<vector<pair<int, int>>>& pathTable, vector<int>& shortestPath, int start) {
	priority_queue<pair<int, int>>pq;
	vector<bool>visited(shortestPath.size(), false);
	pq.push({0, start});
	shortestPath[start] = 0;
	while (!pq.empty()) {
		int nextIDX = pq.top().second;
		int nextIDXLen = -pq.top().first;
		pq.pop();
		if (visited[nextIDX] == true) continue;
		visited[nextIDX] = true;
		for (auto x : pathTable[nextIDX]) {
			int next2IDX = x.first;
			int next2IDXLen = x.second;
			if (visited[next2IDX] == true) continue;
			if (shortestPath[next2IDX] > nextIDXLen + next2IDXLen) {			
				shortestPath[next2IDX] = nextIDXLen + next2IDXLen;
				pq.push({ -(nextIDXLen + next2IDXLen), next2IDX });
			}
		}
	}
}