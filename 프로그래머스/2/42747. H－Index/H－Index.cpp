#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int maxH = citations.back();
    int idx = citations.size() - 1;
    int overCount = 1;
    while(maxH){
        if(citations[idx - 1] == maxH) {
            idx--;
            overCount++;
            continue;
        }
        if(overCount >= maxH) return maxH;
        maxH--;
    }
    
}