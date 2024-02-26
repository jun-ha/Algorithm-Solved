#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int>answer;
    vector<int>leftDays(progresses.size(), 0);
    vector<bool>finished(progresses.size(), false);
    for(int i = 0; i < progresses.size(); i++){
        leftDays[i] = (100-progresses[i]) / speeds[i];
        if((100-progresses[i]) % speeds[i]) leftDays[i]++;
    }
    for(int i = 0; i < leftDays.size(); i++){
        if(finished[i]) continue;
        finished[i] = true;
        int count = 1; 
        for(int j = i + 1; j < leftDays.size(); j++){
            if(finished[j]==false && leftDays[i] >= leftDays[j]){
                finished[j] = true;
                count++;
            }
            else break;
        }
        answer.push_back(count);
    }
    
    return answer;
}