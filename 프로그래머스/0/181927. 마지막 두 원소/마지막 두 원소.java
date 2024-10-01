import java.util.*;

class Solution {
    public int[] solution(int[] num_list) {
        int len = num_list.length;
        int[] answer = Arrays.copyOf(num_list, len + 1);
        
        int last = num_list[len - 1];
        int last2 = num_list[len - 2];
        
        if(last > last2) answer[len] = last - last2;
        else answer[len] = last*2;
        
        return answer;
    }
}