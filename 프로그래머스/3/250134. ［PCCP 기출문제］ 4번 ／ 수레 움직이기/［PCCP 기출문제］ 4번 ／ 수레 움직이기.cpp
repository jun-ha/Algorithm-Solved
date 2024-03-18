#include <bits/stdc++.h>
using namespace std;
int mazeRow, mazeCol;
int redStartRow, redStartCol, blueStartRow, blueStartCol;
int redDestinationRow, redDestinationCol, blueDestinationRow, blueDestinationCol;
enum boardStatus{
    EMPTY = 0,
    RED_START,
    BLUE_START,
    RED_DESTINATION,
    BLUE_DESTINATION,
    WALL
};

enum move{
    UP = 0,
    DOWN,
    LEFT,
    RIGHT
};

bool rangeCheck(int row, int col){
    if(0 <= row && row < mazeRow && 0 <= col && col < mazeCol) return true;
    return false;
}

bool crash(int redRow, int redCol, int blueRow, int blueCol){
    if(redRow == blueRow && redCol == blueCol) return true;
    return false;
}

bool canMove(int row, int col, vector<vector<int>>&maze){
    if(rangeCheck(row, col) && maze[row][col] != WALL) return true;
    return false;
}

int getNextRow(int row, int col, int move){
    switch(move){
        case UP:
            return row-1;
        case DOWN:
            return row+1;
        case LEFT:
        case RIGHT:
            return row;
    }
}
int getNextCol(int row, int col, int move){
    switch(move){
        case LEFT:
            return col-1;
        case RIGHT:
            return col+1;
        case UP:
        case DOWN:
            return col;
    }
}
bool redArrived(int row, int col){
    if(row == redDestinationRow && col == redDestinationCol) return true;
    return false;
}
bool blueArrived(int row, int col){
    if(row == blueDestinationRow && col == blueDestinationCol) return true;
    return false;
}

int solution(vector<vector<int>> maze) {
    mazeRow = maze.size();
    mazeCol = maze[0].size();
    vector<vector<bool>>redVisited(mazeRow, vector<bool>(mazeCol, false));
    vector<vector<bool>>blueVisited(mazeRow, vector<bool>(mazeCol, false));
    for(int row = 0; row < mazeRow; row++){
        for(int col = 0; col < mazeCol; col++){
            if(maze[row][col] == RED_START){
                redStartRow = row;
                redStartCol = col;
            } 
            if(maze[row][col] == BLUE_START){
                blueStartRow = row;
                blueStartCol = col;
            } 
            if(maze[row][col] == RED_DESTINATION){
                redDestinationRow = row;
                redDestinationCol = col;
            } 
            if(maze[row][col] == BLUE_DESTINATION){
                blueDestinationRow = row;
                blueDestinationCol = col;
            } 
        }
    }
    
    queue<tuple<int, int, int, int, int, vector<vector<bool>>, vector<vector<bool>>>>q;
    q.push({redStartRow, redStartCol, blueStartRow, blueStartCol, 0, redVisited, blueVisited});
    
    while(!q.empty()){
        auto [redRow, redCol, blueRow, blueCol, turn, redVisited, blueVisited] = q.front();
        q.pop();
        
        if(crash(redRow, redCol, blueRow, blueCol)) continue;
        if(redVisited[redRow][redCol] && !redArrived(redRow, redCol)) continue;
        if(blueVisited[blueRow][blueCol] && !blueArrived(blueRow, blueCol)) continue;
        redVisited[redRow][redCol] = true;
        blueVisited[blueRow][blueCol] = true;
        if(redArrived(redRow, redCol) && blueArrived(blueRow, blueCol)) return turn;
        
        for(int redMove = UP; redMove <= RIGHT; redMove++){
            int redNextRow;
            int redNextCol;
            if(redArrived(redRow, redCol)){
                redNextRow = redRow;
                redNextCol = redCol;
            } 
            else{
                redNextRow = getNextRow(redRow, redCol, redMove);
                redNextCol = getNextCol(redRow, redCol, redMove);
                if(canMove(redNextRow, redNextCol, maze) == false) continue;
            }
            
            for(int blueMove = UP; blueMove <= RIGHT; blueMove++){
                int blueNextRow;
                int blueNextCol;
                if(blueArrived(blueRow, blueCol)){
                    blueNextRow = blueRow;
                    blueNextCol = blueCol;
                }
                else{
                    blueNextRow = getNextRow(blueRow, blueCol, blueMove);
                    blueNextCol = getNextCol(blueRow, blueCol, blueMove);
                    if(canMove(blueNextRow, blueNextCol, maze) == false) continue;   
                }
            
                if(crash(redNextRow, redNextCol, blueRow, blueCol) && crash(redRow, redCol, blueNextRow, blueNextCol)){
                    continue;
                }
                q.push({redNextRow, redNextCol, blueNextRow, blueNextCol, turn+1, redVisited, blueVisited});
            }
        }
        
        
    }
    
    return 0;
}