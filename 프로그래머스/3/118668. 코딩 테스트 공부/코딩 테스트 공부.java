import java.util.*;

class Solution {
    int[][] dp;
    
    boolean isValidRange(int r, int c) {
        return 0 <= r && r <= dp.length && 0 <= c && c <= dp[0].length;
    }
    
    List<int[]> getSolvable(int alp, int cop, int[][] problems) {
        List<int[]> lst = new ArrayList<>();
        
        for(int[] p : problems) {
            if(alp >= p[0] && cop >= p[1]) {
                lst.add(p);
            }
        }
        return lst;
    }
    
    public int solution(int alp, int cop, int[][] problems) {
        int aMax = -1, cMax = -1;
        for(int[] p : problems) {
            aMax = Math.max(aMax, p[0]);
            cMax = Math.max(cMax, p[1]);
        }
        
        dp = new int[aMax + 1][cMax + 1];
        for(int i = 0; i <= aMax; i++) {
            Arrays.fill(dp[i], 999999999);    
        }
        
        int startR = alp < aMax ? alp : aMax;
        int startC = cop < cMax ? cop : cMax;
        
        dp[startR][startC] = 0;
        
        for(int r = startR; r <= aMax; r++) {
            for(int c = startC; c <= cMax; c++) {
                
                if(isValidRange(r - 1, c)) {
                    dp[r][c] = Math.min(dp[r][c], dp[r - 1][c] + 1);    
                }
                if(isValidRange(r, c - 1)) {
                    dp[r][c] = Math.min(dp[r][c], dp[r][c - 1] + 1);    
                }
                
                if(r == startR && c == startC) dp[r][c] = 0;
                
                List<int[]> solvable = getSolvable(r > alp ? r : alp, c > cop ? c : cop, problems);
                for(int[] p : solvable) {
                    int aReward = p[2];
                    int cReward = p[3];
                    int cost = p[4];
                    
                    int nextR = r + aReward > aMax ? aMax : r + aReward;
                    int nextC = c + cReward > cMax ? cMax : c + cReward;
                    
                    dp[nextR][nextC] = Math.min(dp[nextR][nextC], dp[r][c] + cost);
                }
                
            }
        }
        
        return dp[aMax][cMax];
    }
}