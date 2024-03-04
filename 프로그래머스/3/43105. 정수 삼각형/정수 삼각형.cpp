#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> triangle) {
    for(int i = 1; i < triangle.size(); i++){
        triangle[i][0] += triangle[i-1][0];
        for(int j = 1; j < triangle[i].size() - 1; j++){
            triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);   
        }
        triangle[i][triangle[i].size()-1] += triangle[i-1][triangle[i-1].size()-1];
    }
    int maxValue = -1;
    for(int value : triangle.back()){
        if(value > maxValue) maxValue = value;
    }
    return maxValue;
}