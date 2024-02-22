#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(vector<vector<bool>>tree, int n){
    queue<int>q;
    vector<bool>visited(n+1, false);
    q.push(1);
    int count = 0;
    while(!q.empty()){
        int tmpNum = q.front();
        q.pop();
        if(visited[tmpNum]) continue;
        visited[tmpNum] = true;
        count++;
        for(int i = 1; i <= n; i++){
            if(tree[tmpNum][i]) {
                q.push(i);
            }
        }
    }
    return abs(n - 2*count);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 9999999;
    vector<vector<bool>>tree(n+1, vector<bool>(n+1, false));
    for(int i = 0; i < wires.size(); i++){
        int v1 = wires[i][0];
        int v2 = wires[i][1];
        tree[v1][v2] = true;
        tree[v2][v1] = true;
    }
    for(int i = 0; i < wires.size(); i++){
        vector<vector<bool>>tmpTree(tree);
        int eraseV1 = wires[i][0];
        int eraseV2 = wires[i][1];
        tmpTree[eraseV1][eraseV2] = false;
        tmpTree[eraseV2][eraseV1] = false;
        answer = min(answer, bfs(tmpTree, n));
    }
    return answer;
}