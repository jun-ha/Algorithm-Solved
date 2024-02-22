#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto x : commands){
        int i = x[0];
        int j = x[1];
        int k = x[2];
        vector<int>tmpArray(array);
        sort(tmpArray.begin()+i-1, tmpArray.begin()+j);
        answer.push_back(tmpArray[i-1+k-1]);
    }
    return answer;
}