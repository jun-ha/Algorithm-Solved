#include <bits/stdc++.h>
using namespace std;
#define MINIMUM_GRAPH_NUM 2
unordered_map<int, pair<set<int>, set<int>>>graph; 
//node number, indegree set, outdegree set
int findExtraNode(){
    for(auto iter = graph.begin(); iter != graph.end(); iter++){
        int nodeNum = iter->first;
        int indegreeNum = iter->second.first.size();
        int outdegreeNum = iter->second.second.size(); 
        if(indegreeNum == 0 && outdegreeNum >= MINIMUM_GRAPH_NUM) {
            return nodeNum;
        }
    }
}
void addOutdegree(int from, int to){
    graph[from].second.insert(to);
}
void addIndegree(int to, int from){
    graph[to].first.insert(from);
}

vector<int> solution(vector<vector<int>> edges) {
    for(auto edge : edges){
        int from = edge[0];
        int to = edge[1];
        addOutdegree(from, to);
        addIndegree(to, from);
    }
    int extraNode = findExtraNode();
    int numOfDonutGraph = 0;
    int numOfStickGraph = 0;
    int numOfEightGraph = 0;
    int totalGraphNum = graph[extraNode].second.size();
    for(auto iter = graph.begin(); iter != graph.end(); iter++){
        int node = iter->first;
        if(node == extraNode) continue;
        int indegreeNum = iter->second.first.size();
        int outdegreeNum = iter->second.second.size();
        if(outdegreeNum == 0) numOfStickGraph++;
        else if(outdegreeNum == 2) numOfEightGraph++;
    }
    numOfDonutGraph = totalGraphNum - numOfEightGraph - numOfStickGraph;
    return {extraNode, numOfDonutGraph, numOfStickGraph, numOfEightGraph};
}