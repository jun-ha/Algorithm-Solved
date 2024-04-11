import java.util.*;
import java.util.stream.*;

class Solution {
    public int[] solution(int[] arr, int k) {
        TreeSet<Integer> s = new TreeSet<>();
        int[] answer = new int[k];
        int idx = 0;
        for(int num : arr){
            if(idx == k) break;
            if(!s.contains(num)){
                answer[idx++] = num;
                s.add(num);
            }
        }
        for(; idx < k; idx++){
            answer[idx] = -1;
        }
        return answer;
    }
}