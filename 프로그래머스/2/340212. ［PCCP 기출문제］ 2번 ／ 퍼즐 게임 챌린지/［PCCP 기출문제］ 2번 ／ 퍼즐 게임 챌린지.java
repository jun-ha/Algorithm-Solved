import java.util.*;

class Solution {    
    int[] diffs;
    int[] times;
    long limit;
    
    boolean isPossibleIn(int level) {
        int len = diffs.length;
        long time = 0;
        for(int i = 0; i < len; i++) {
            if(diffs[i] <= level) {
                time += times[i];
            } else {
                time += (times[i] + times[i-1]) * (diffs[i] - level) + times[i];
            }
        }
        
        return time <= limit;
    }
    
    public int solution(int[] diffs, int[] times, long limit) {
        this.diffs = diffs;
        this.times = times;
        this.limit = limit;
        int maxLevel = Arrays.stream(diffs).max().orElseThrow();
        
        int left = 1;
        int right = maxLevel;
        
        int answer = 0;
        while(left <= right) {
            int mid = (left + right) / 2;
            
            if(isPossibleIn(mid)) {
                right = mid - 1;
                answer = mid;
            } else {
                left = mid + 1;
            }
        }
        
        
        return answer;
    }
}