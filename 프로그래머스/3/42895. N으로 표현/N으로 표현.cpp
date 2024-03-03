#include <bits/stdc++.h>
using namespace std;

int solution(int N, int number) {
    string continuous_5 = "";
    vector<vector<int>>nums(9);
    for(int i = 1; i <= 8; i++){
        continuous_5 += to_string(N);
        if(stoi(continuous_5) == number) return i;
        nums[i].push_back(stoi(continuous_5));
        
        for(int p = 1; p <= i/2; p++){
            for(int q : nums[p]){
                for(int r : nums[i-p]){
                    if(q+r == number || q*r == number) return i;
                    nums[i].push_back(q+r);
                    nums[i].push_back(q*r);
                }
            }
        }
        for(int p = 1; p < i; p++){
            for(int q : nums[p]){
                for(int r : nums[i-p]){
                    if(q != r) {
                        if(q-r == number) return i;
                        nums[i].push_back(q-r);
                    }
                    if(r != 0) {
                        if(q/r == number) return i;
                        nums[i].push_back(q/r);
                    }
                }
            }
        } 
    }
    return -1;
}