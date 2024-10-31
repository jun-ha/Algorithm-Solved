import java.util.*;

class Solution {
    
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        ArrayList<Integer>[] adjs = new ArrayList[n + 1];
        for(int i = 0; i < adjs.length; i++) {
            adjs[i] = new ArrayList<>();
        }
        
        for(int[] road : roads) {
            adjs[road[0]].add(road[1]);
            adjs[road[1]].add(road[0]);
        }
        
        int[] shortestFromDest = new int[n + 1];
        Arrays.fill(shortestFromDest, -1);
        
        Queue<int[]> q = new ArrayDeque<>(); //node, step
        q.add(new int[]{destination, 0});
        boolean[] visited = new boolean[n + 1];
        
        while(!q.isEmpty()) {
            int[] tmp = q.poll();
            int node = tmp[0];
            int step = tmp[1];
            
            if(visited[node]) continue;
            visited[node] = true;
            shortestFromDest[node] = step;
            
            for(int adj : adjs[node]) {
                if(visited[adj]) continue;
                q.add(new int[]{adj, step + 1});
            }
        }
        
        int[] answer = new int[sources.length];
        int idx = 0;
        for(int pos : sources) {
            answer[idx++] = shortestFromDest[pos];
        }
        
        return answer;
    }
}