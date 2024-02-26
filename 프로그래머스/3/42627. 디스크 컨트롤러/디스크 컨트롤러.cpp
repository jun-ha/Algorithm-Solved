#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int time = 0;
    int numOfJob = jobs.size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>jobsOrderedByTime;
    for(auto x : jobs){
        int startTime = x[0];
        int processingTime = x[1];
        jobsOrderedByTime.push({startTime, processingTime});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>processes;
    vector<int>elapsedTimes;
    while(!jobsOrderedByTime.empty() || !processes.empty()){
        while(!jobsOrderedByTime.empty() && jobsOrderedByTime.top().first <= time){
            int processingTime = jobsOrderedByTime.top().second;
            int startTime = jobsOrderedByTime.top().first;
            processes.push({processingTime, startTime});
            jobsOrderedByTime.pop();   
        }
        
        
        if(!processes.empty()){
            int processingTime = processes.top().first;
            int startTime = processes.top().second;
            processes.pop();
            time += processingTime;
            elapsedTimes.push_back(time - startTime);
            continue;
        }
        
        time++;
    }
    
    int sum = 0;
    for(auto e : elapsedTimes){
        sum += e;
    }
    
    return sum / numOfJob;
}