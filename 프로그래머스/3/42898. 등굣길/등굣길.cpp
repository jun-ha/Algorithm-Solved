#include <bits/stdc++.h>
#define PUDDLE 0
using namespace std;

int solution(int col, int row, vector<vector<int>> puddles) {
    vector<vector<int>>routes(row, vector<int>(col, -1));
    for(auto puddle : puddles){
        if(puddle.size() == 2){
            routes[puddle[1]-1][puddle[0]-1] = PUDDLE;   
        }
    }
    routes[0][0] = 1;
    for(int i = 1; i < row; i++){
        if(routes[i][0] == PUDDLE) continue;
        routes[i][0] = routes[i-1][0];
    }
    for(int j = 1; j < col; j++){
        if(routes[0][j] == PUDDLE) continue;
        routes[0][j] = routes[0][j-1];
    }
    
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(routes[i][j] == PUDDLE) continue;
            routes[i][j] = ((routes[i-1][j] % 1000000007) + (routes[i][j-1] % 1000000007)) % 1000000007;
        }
    }

    return routes[row-1][col-1];
}