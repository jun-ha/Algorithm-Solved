#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    vector<int>priorityCount(10, 0);
    vector<bool>complete(priorities.size(), false);
    for(int priority : priorities){
        priorityCount[priority]++;
    }
    
    int idx = 0;
    int processCount = 0;
    while(1){
        if(idx >= priorities.size()) idx = 0;
        if(complete[idx]) {
            idx++;
            continue;
        }
        int tmpPriority = priorities[idx];
        bool findBiggerPriority = false;
        for(int p = 9; p > tmpPriority; p--){
            if(priorityCount[p]){
                idx++;
                findBiggerPriority = true;
                break;
            }
        }
        if(findBiggerPriority) continue;
        
        complete[idx] = true;
        priorityCount[tmpPriority]--;
        processCount++;
        if(idx == location) return processCount;
    }
    return -1;
}