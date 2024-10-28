class Solution {
    public long solution(int[] sequence) {
        int[] posStart = new int[sequence.length];
        int[] negStart = new int[sequence.length];
        
        int idx = 0;
        int tmp = 1;
        for(int n : sequence) {
            posStart[idx] = n * tmp;
            negStart[idx] = n * tmp * -1;
            idx++;
            tmp *= -1;
        }
        
        long maxValue = 0L;
        
        long sum1 = 0L;
        long sum2 = 0L;
        for(int i = 0; i < sequence.length; i++) {
            sum1 += posStart[i];
            sum2 += negStart[i];
            
            if(sum1 < 0) sum1 = 0;
            if(sum2 < 0) sum2 = 0;
            
            maxValue = Math.max(sum1, maxValue);
            maxValue = Math.max(sum2, maxValue);
        }
        
        return maxValue;
    }
}