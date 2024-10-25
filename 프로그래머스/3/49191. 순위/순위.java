import java.util.*;

class Boxer {
    Set<Integer> better = new HashSet<>();
    Set<Integer> worse = new HashSet<>();
}

class Ranking {
    Boxer[] boxers;
    
    Ranking(int n) {
        boxers = new Boxer[n + 1];
        for(int i = 0; i <= n; i++) {
            boxers[i] = new Boxer();
        }
    }
    
    void setResult(int winner, int loser) {
        boxers[winner].worse.add(loser);
        boxers[loser].better.add(winner);
    }
    
    int solution() {
        int answer = 0;
        for(int i = 1; i < boxers.length; i++) {
            Set<Integer> visited = new HashSet<>();
            
            Queue<Integer> winners = new ArrayDeque<>();
            boolean[] winnerVisited = new boolean[boxers.length];
            winners.add(i);
            while(!winners.isEmpty()) {
                int tmp = winners.poll();
                if(winnerVisited[tmp]) continue;
                visited.add(tmp);
                winnerVisited[tmp] = true;
                for(int w : boxers[tmp].better) {
                    winners.add(w);
                }
            }
            
            Queue<Integer> losers = new ArrayDeque<>();
            boolean[] loserVisited = new boolean[boxers.length];
            losers.add(i);
            while(!losers.isEmpty()) {
                int tmp = losers.poll();
                if(loserVisited[tmp]) continue;
                visited.add(tmp);
                loserVisited[tmp] = true;
                for(int l : boxers[tmp].worse) {
                    losers.add(l);
                }
            }
            
            if(visited.size() == boxers.length - 1) answer++;
        }
        
        return answer;
    }
}

class Solution {
    public int solution(int n, int[][] results) {
        Ranking ranking = new Ranking(n);
        
        for(int[] result : results) {
            ranking.setResult(result[0], result[1]);
        }
        
        return ranking.solution();
    }
}