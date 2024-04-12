import java.util.*;
class Solution {
    int mapRow;
    int mapCol;
    int[][] map;
    
    boolean isDestination(int row, int col){
        if(row == mapRow-1 && col == mapCol-1) return true;
        return false;
    }
    
    boolean canMove(int row, int col){
        if(rangeCheck(row, col) && map[row][col] == 1) return true;
        return false;
    }
    
    boolean rangeCheck(int row, int col){
        if(0 <= row && row < mapRow && 0 <= col && col < mapCol) return true;
        return false;
    }
    
    class Pos{
        int row;
        int col;
        int count;
        Pos(int row, int col, int count){
            this.row = row;
            this.col = col;
            this.count = count;
        }
    }
    
    public int solution(int[][] maps) {
        map = maps;
        mapRow = maps.length;
        mapCol = maps[0].length;
        boolean[][] visited = new boolean[mapRow][mapCol];
        
        Queue<Pos> q = new LinkedList<>();
        q.add(new Pos(0, 0, 1));
        
        while(!q.isEmpty()){
            Pos tmp = q.poll();
            int row = tmp.row, col = tmp.col, count = tmp.count;
            
            if(visited[tmp.row][tmp.col]) continue;
            visited[tmp.row][tmp.col] = true;
            
            if(isDestination(row, col)) return count;
            
            if(canMove(row-1, col)) q.add(new Pos(row-1, col, count+1));
            if(canMove(row+1, col)) q.add(new Pos(row+1, col, count+1));
            if(canMove(row, col-1)) q.add(new Pos(row, col-1, count+1));
            if(canMove(row, col+1)) q.add(new Pos(row, col+1, count+1));
        }
        return -1;
    }
}