import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        int answer = 0;
        int maxS = Integer.MIN_VALUE, minE = Integer.MAX_VALUE;
        
        Arrays.sort(targets, (a, b) -> a[0] == b[0]? a[1] - b[1] : a[0] - b[0]);
        
        
        for(int[] target : targets) {
            int s = target[0];
            int e = target[1];
            
            if(maxS <= s && s < minE) {
                maxS = Math.max(maxS, s);
                minE = Math.min(minE, e);
            } else {
                answer++;
                maxS = s;
                minE = e;
            }
        }
        answer++;
        
        return answer;
    }
}