#include <bits/stdc++.h>

using namespace std;

int maxLamb = INT_MIN;

int numOfNode;
vector<int>nodeInfo;
vector<vector<int>>childInfo;
vector<bool>reachAble;
vector<bool>visited;

void addReachAble(int tmpNode){
    for(int child : childInfo[tmpNode]){
        reachAble[child] = true;
    }
}

int collectLambs(int tmpNode, int lambCount){
    addReachAble(tmpNode);
    while(1){
        bool noMoreLamb = true;
        for(int i = 0; i < numOfNode; i++){
            if(reachAble[i] && visited[i] == false && nodeInfo[i] == 0) {
                visited[i] = true;
                addReachAble(i);
                lambCount++;
                noMoreLamb = false;
                break;
            }    
        }
        if(noMoreLamb) break;
    }
    return lambCount;   
}

void dfs(int tmpNode, int lambCount, int wolfCount){
    if(nodeInfo[tmpNode] == 0) lambCount++;
    else wolfCount++;
    
    if(lambCount == wolfCount) return;
    
    vector<bool>beforeReachAble(reachAble);
    vector<bool>beforeVisited(visited);
    
    lambCount = collectLambs(tmpNode, lambCount);
    
    if(maxLamb < lambCount) maxLamb = lambCount;
    
    for(int i = 0; i < numOfNode; i++){
        if(visited[i] == false && reachAble[i]){
            visited[i] = true;
            dfs(i, lambCount, wolfCount);
            visited[i] = false;
        }
    }
    
    reachAble = beforeReachAble;
    visited = beforeVisited;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    numOfNode = info.size();
    nodeInfo = info;
    childInfo.resize(numOfNode);
    reachAble.resize(numOfNode, false);
    visited.resize(numOfNode, false);
    for(int i = 0; i < edges.size(); i++){
        childInfo[edges[i][0]].push_back(edges[i][1]);
    }
    dfs(0, 0, 0);
    return maxLamb;
}