#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(reserve.begin(), reserve.end());
    vector<bool>student(n+1, true);
    vector<bool>reserveButLost(n+1, false);
    for(int l : lost){
        student[l] = false;
        cout << l << endl;
    }
    for(int r : reserve){
        if(student[r] == false){
            student[r] = true;
            reserveButLost[r] = true;   
        }
    }
    for(int r : reserve){
        if(reserveButLost[r]) continue;
        if(1 < r && student[r-1] == false) {
            student[r-1] = true;
            continue;
        }
        if(r < 30 && student[r+1] == false) {
            student[r+1] = true;
            continue;
        }
    }
    int answer = 0;
    for(bool has : student){
        if(has) answer++;
    }
    answer--; //for index 0
    
    return answer;
}