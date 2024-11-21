import java.util.*;

class Solution {
    int[][] land;
    
    List<Integer> oilMass = new ArrayList<>();
    
    int[] dRow = new int[]{1, -1 , 0, 0};
    int[] dCol = new int[]{0, 0, 1, -1};
    
    boolean isValidRange(int r, int c) {
        return 0 <= r && r < land.length && 0 <= c && c < land[0].length;
    }
    
    public void checkAdjOils() {
        int massId = -1;
        boolean[][] visited = new boolean[land.length][land[0].length];
        
        for(int i = 0; i < land.length; i++) {
            for(int j = 0; j < land[0].length; j++) {
                if(land[i][j] == 0 || visited[i][j]) continue;
                
                int count = 0;
                Queue<int[]>q = new ArrayDeque<>();
                q.add(new int[]{i, j});
                
                while(!q.isEmpty()) {
                    int[] tmp = q.poll();
                    int r = tmp[0];
                    int c = tmp[1];
                    
                    if(visited[r][c]) continue;
                    visited[r][c] = true;
                    land[r][c] = massId;
                    
                    count++;
                    
                    for(int k = 0; k < 4; k++) {
                        int nr = r + dRow[k];
                        int nc = c + dCol[k];
                        if(isValidRange(nr, nc) && land[nr][nc] != 0 && !visited[nr][nc] ) {
                            q.add(new int[]{nr, nc});
                        }
                    }
                }
                oilMass.add(count);
                massId--;
                
            }
        }
    }
    
    public int solution(int[][] land) {
        this.land = land;
        checkAdjOils();
        
        int answer = Integer.MIN_VALUE;
        for(int col = 0; col < land[0].length; col++) {
            boolean[] visited = new boolean[oilMass.size()];
            int count = 0;
            for(int row = 0; row < land.length; row++) {
                if(land[row][col] == 0) continue;
                
                int massId = land[row][col];
                int massIdx = -massId - 1;
                if(visited[massIdx]) continue;
                visited[massIdx] = true;
                
                count += oilMass.get(massIdx);
            }
            
            answer = Math.max(answer, count);
        }
        
        return answer;        
    }
}