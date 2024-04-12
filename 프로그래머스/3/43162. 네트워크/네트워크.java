import java.util.*;

class Solution {
    boolean[] visited;
    
    public int solution(int n, int[][] computers) {
        int count = 0;
        visited = new boolean[n];
        
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            Queue<Integer> q = new LinkedList<>();
            q.add(i);
            while(!q.isEmpty()){
                int tmp = q.poll();
                if(visited[tmp]) continue;
                visited[tmp] = true;
                for(int j = 0; j < n; j++){
                    if(computers[tmp][j] == 1){
                        q.add(j);
                    }
                }
            }
            count++;
        }
        return count;
    }
}