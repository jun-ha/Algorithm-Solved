#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<int>q;
    q.push(0);
    for(int idx = 0; idx < numbers.size(); idx++){
        queue<int>tmpQueue;
        while(!q.empty()){
            int tmpSum = q.front();
            tmpQueue.push(tmpSum + numbers[idx]);
            tmpQueue.push(tmpSum - numbers[idx]);
            q.pop();    
        }
        q = tmpQueue;   
    }
    
    while(!q.empty()){
        if(q.front() == target) answer++;
        q.pop();
    }
    
    return answer;
}