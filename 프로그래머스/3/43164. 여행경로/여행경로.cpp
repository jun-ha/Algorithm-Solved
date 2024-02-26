#include <bits/stdc++.h>
using namespace std;

vector<string> DFS(string departure, map<string, vector<string>>m, vector<string>path, int leftTicket){
    if(leftTicket == 0) return path;
    if(m[departure].empty()) return vector<string>();
    
    for(int i = 0; i < m[departure].size(); i++){
        map<string, vector<string>>newMap(m);
        vector<string>newPath(path);
        string arrival = newMap[departure][i];
        newMap[departure].erase(newMap[departure].begin() + i);
        newPath.push_back(arrival);
        vector<string> result = DFS(arrival, newMap, newPath, leftTicket - 1);
        if(!result.empty()) return result;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    int numOfTicket = tickets.size();
    map<string, vector<string>>m;
    for(auto ticket : tickets){
        string departure = ticket[0];
        string arrival = ticket[1];
        m[departure].push_back(arrival);
    }
    for(auto iter = m.begin(); iter!=m.end(); iter++){
        sort((*iter).second.begin(), (*iter).second.end());
    }
    vector<string>path = {"ICN"};
    return DFS("ICN", m, path, numOfTicket);
}