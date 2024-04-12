import java.util.*;
import java.util.stream.*;

class Solution {
    public int solution(int[] numbers, int target) {
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        for(int num : numbers){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int head = q.poll();
                q.add(head+num);
                q.add(head-num);
            }
        }
        return (int)q.stream().filter(i -> i == target).count();
    }
}