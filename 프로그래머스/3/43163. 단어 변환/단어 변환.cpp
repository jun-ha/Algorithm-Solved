#include <bits/stdc++.h>

using namespace std;

bool isDiffOneWord(string a, string b){
    int count = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i]==b[i]) continue;
        count++;
        if(count > 1) return false;
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    map<string, bool>visited;
    for(string word : words){
        visited[word] = false;
    }
    if(visited.find(target) == visited.end()) return 0;
    queue<pair<string, int>>q;
    q.push({begin, 0});
    while(!q.empty()){
        string tmpString = q.front().first;
        int tmpCount = q.front().second;
        q.pop();
        if(tmpString == target) return tmpCount;
        if(visited[tmpString]) continue;
        visited[tmpString] = true;
        for(auto word : words){
            if(visited[word] == false && isDiffOneWord(tmpString, word)){
                q.push({word, tmpCount+1});
            }
        }
    }
    
    return 0;
}