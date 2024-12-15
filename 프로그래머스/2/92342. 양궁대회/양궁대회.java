import java.util.*;

class Solution {
    int n;
    int[] enemyArrows;
    int[] answer = null;
    
    boolean[] result = new boolean[10]; //win or lose
    
    int maxScoreGap = Integer.MIN_VALUE;
    
    int[] getPriorArray(int[] a, int[] b) {
        if(a == null) return b;
        if(b == null) return a;
        
        for(int i = 10; i >= 0; i--) {
            if(a[i] == b[i]) continue;
            
            return a[i] > b[i]? a : b;
        }
        return a;
    }
    
    void dfs(int idx) {
        if(idx == 10) {
            int enemyPoint = 0;
            int myPoint = 0;
            int leftArrows = n;
            int[] myArrows = new int[11];
        
            for(int i = 0; i < 10; i++) {
                int point = 10 - i;

                if(!result[i]) {
                    if(enemyArrows[i] > 0) enemyPoint += point;
                    continue;
                }

                int arrowToWin = enemyArrows[i] + 1;
                leftArrows -= arrowToWin;

                if(leftArrows < 0) return; //impossible case

                myPoint += point;
                myArrows[i] = arrowToWin;
            }
            
            if(leftArrows > 0) {
                myArrows[10] = leftArrows; //increase priority
            }

            int scoreGap = myPoint - enemyPoint;
            if(scoreGap <= 0) return; //losing game
            if(scoreGap < maxScoreGap) return; //worthless
            
            if(scoreGap > maxScoreGap) answer = myArrows;
            if(scoreGap == maxScoreGap) answer = getPriorArray(answer, myArrows);
            
            maxScoreGap = scoreGap;
            return;
        }

        result[idx] = true;
        dfs(idx + 1);
        result[idx] = false;
        dfs(idx + 1);
    }
    
    public int[] solution(int n, int[] info) {
        this.n = n;
        this.enemyArrows = info;
        
        dfs(0);
        
        if(answer == null) {
            answer = new int[]{-1};
        }
        
        return answer;
    }
}