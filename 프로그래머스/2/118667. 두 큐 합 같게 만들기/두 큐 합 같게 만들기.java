import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int answer = 0;
        Queue<Integer> q1 = new ArrayDeque<>();
        Queue<Integer> q2 = new ArrayDeque<>();
        long q1Sum = 0;
        long q2Sum = 0;
        for(int n : queue1) {
            q1.add(n);
            q1Sum += n;
        }
        for(int n : queue2) {
            q2.add(n);
            q2Sum += n;
        }
        
        while(q1Sum != q2Sum) {
            if(q1Sum < q2Sum) {
                int poped = q2.peek();
                q2Sum -= poped;
                q1Sum += poped;
                
                q1.add(q2.poll());
                
            } else {
                int poped = q1.peek();
                q1Sum -= poped;
                q2Sum += poped;
                
                q2.add(q1.poll());
            } 
            
            answer++;
            
            if(answer > queue1.length * 3) break;
        }
        
        
        
        if(answer > queue1.length * 3) return -1;
        return answer;
    }
}