#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s < n) {
        answer.push_back(-1);
        return answer;
    }
    int benchmark = s/n;
    int sum = 0;
    for(int i = 0; i < n; i++){
        answer.push_back(benchmark);
        sum += benchmark;
    }
    int left = s - sum;
    if(left > 0){
        int idx = 0;
        for(int i = 0; i < left; i++){
            answer[idx]++;
            idx++;
            if(idx >= n) idx = 0;
        }
    }
    sort(answer.begin(), answer.end());
    
    
    
    
    return answer;
}