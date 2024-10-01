import java.util.*;

class Solution {
    static class Process {
        int location;
        int priority;
        
        public Process(int location, int priority) {
            this.location = location;
            this.priority = priority;
        }
    }
    
    public int solution(int[] priorities, int location) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        Queue<Process> q = new ArrayDeque<>();
        
        for(int i = 0; i < priorities.length; i++) {
            pq.add(priorities[i]);
            q.add(new Process(i, priorities[i]));
        }
        
        int curP = pq.poll();
        int answer = 1;
        while(true) {
            Process next = q.poll();
            if(next.priority == curP) {
                if(next.location == location) return answer;
                answer++;
                curP = pq.poll();
                continue;
            }
            q.add(next);
        }
    }
}