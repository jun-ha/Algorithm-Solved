#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(s < n) return {-1};
    int benchmark = s/n;
    vector<int>answer(n, benchmark);
    int left = s - benchmark*n;
    int idx = n-1;
    for(int i = 0; i < left; i++){
        answer[idx]++;
        idx--;
        if(idx == -1) idx = n-1;
    }
    return answer;
}