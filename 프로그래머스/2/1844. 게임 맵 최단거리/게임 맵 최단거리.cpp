#include <bits/stdc++.h>
using namespace std;

int row, col;

bool rangeCheck(int tmpRow, int tmpCol){
    if(0 <= tmpRow && tmpRow < row && 0 <= tmpCol && tmpCol < col) return true;
    return false;
}

bool roadCheck(int tmpRow, int tmpCol, vector<vector<int>>&maps){
    if(rangeCheck(tmpRow, tmpCol) && maps[tmpRow][tmpCol] == 1) return true;
    return false;
}

int solution(vector<vector<int>> maps)
{
    row = maps.size();
    col = maps[0].size();
    vector<vector<bool>>visited(row, vector<bool>(col, false));
    queue<tuple<int,int,int>>q;
    q.push({0, 0, 1});
    while(!q.empty()){
        int tmpRow = get<0>(q.front());
        int tmpCol = get<1>(q.front());
        int tmpCount = get<2>(q.front());
        if(tmpRow == row-1 && tmpCol == col-1) return tmpCount;
        q.pop();
        if(visited[tmpRow][tmpCol]) continue;
        visited[tmpRow][tmpCol] = true;
        if(roadCheck(tmpRow - 1, tmpCol, maps)) {
            q.push({tmpRow - 1, tmpCol, tmpCount + 1});
        }
        if(roadCheck(tmpRow + 1, tmpCol, maps)) {
            q.push({tmpRow + 1, tmpCol, tmpCount + 1});
        }
        if(roadCheck(tmpRow, tmpCol - 1, maps)) {
            q.push({tmpRow, tmpCol - 1, tmpCount + 1});
        }
        if(roadCheck(tmpRow, tmpCol + 1, maps)) {
            q.push({tmpRow, tmpCol + 1, tmpCount + 1});
        }
    }
    return -1;
}