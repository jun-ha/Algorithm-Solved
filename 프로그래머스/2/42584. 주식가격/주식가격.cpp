#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    int numOfShare = prices.size();
    priority_queue<pair<int,int>>pq;
    vector<int>elapsedTime(numOfShare, 0);
    int idx = 0;
    while(idx < numOfShare){
        while(!pq.empty()){
            if(pq.top().first > prices[idx]) {
                elapsedTime[pq.top().second] = idx - pq.top().second;
                pq.pop();
                continue;
            }
            break;
        }
        pq.push({prices[idx], idx});
        idx++;
    }
    
    idx--;
    for(int i = 0; i < numOfShare; i++){
        if(elapsedTime[i] == 0){
            elapsedTime[i] += idx - i;
        }
    }
    return elapsedTime;
}