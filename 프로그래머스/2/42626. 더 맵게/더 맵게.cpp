#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int s : scoville) {
        pq.push(s);
    }
    
    int count = 0;
    while(!pq.empty()){
        if(pq.top() >= K) return count;
        
        int s1 = pq.top();
        pq.pop();
        if(pq.empty()) return -1;
        int s2 = pq.top();
        pq.pop();
        
        pq.push(s1 + s2*2);
        count++;
    }
    return -1;
}