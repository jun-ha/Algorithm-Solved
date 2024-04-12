import java.util.stream.*;

class Solution {
    public int[] solution(int[] arr, int[][] queries) {
        for(int[] query : queries){
            int s = query[0], e = query[1], k = query[2];
            IntStream.range(s, e+1).filter(i -> i % k == 0).forEach(i -> arr[i]++);
        }
        return arr;   
    }
}