import java.util.*;

class Solution {
    public int solution(int[] arr) {
        int[] before = arr.clone();
        int count = 0;
        while(true){
            int[] next = before.clone();
            for(int i = 0; i < next.length; i++){
                if(next[i] >= 50 && next[i] % 2 == 0) next[i] /= 2;
                if(next[i] < 50 && next[i] % 2 != 0) next[i] = next[i]*2+1;
            }
            if(Arrays.equals(before, next)) return count;
            before = next;
            count++;
        }
    }
}