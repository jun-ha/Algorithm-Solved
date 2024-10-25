import java.util.*;

class Node {
    Set<Integer> adjNodes = new TreeSet<>();
    
    void setAdj(int adj) {
        adjNodes.add(adj);
    }
}

class Graph {
    Node[] nodes;
    boolean[] visited;
    
    Graph(int n) {
        nodes = new Node[n + 1];
        for(int i = 1; i <= n; i++) {
            nodes[i] = new Node();
        }
    }
    
    void setAdj(int n1, int n2) {
        nodes[n1].setAdj(n2);
        nodes[n2].setAdj(n1);
    }
    
    class Step {
        int node;
        int count;
        Step(int node, int count) {
            this.node = node;
            this.count = count;
        }
    }
    
    int solution(int start) {
        visited = new boolean[nodes.length + 1];
         
        int answer = 0;
        int maxStep = -1;
        
        Queue<Step> q = new ArrayDeque<>();
        q.add(new Step(start, 0));
        
        while(!q.isEmpty()) {
            Step step = q.poll();
            if(visited[step.node]) continue;
            visited[step.node] = true;
            
            if(step.count == maxStep) answer++;
            if(step.count > maxStep) {
                maxStep = step.count;
                answer = 1;
            }
            
            for(int adj : nodes[step.node].adjNodes) {
                q.add(new Step(adj, step.count+1));
            } 
        }
        
        return answer;
    }
}


class Solution {
    public int solution(int n, int[][] edge) {
        int answer = 0;
        Graph graph = new Graph(n);
        for(int[] info : edge) {
            graph.setAdj(info[0], info[1]);
        }
        return graph.solution(1);
    }
}