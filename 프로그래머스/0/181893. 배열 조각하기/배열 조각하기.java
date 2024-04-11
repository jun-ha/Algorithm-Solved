import java.util.*;

class Solution {
    public int[] solution(int[] arr, int[] query) {
        int front = 0;
        int back = arr.length-1;
        boolean isOdd = false;
        
        for(int idx : query){
            if(isOdd){
                front = front + idx;
                isOdd = false;
            }
            else{
                back = front + idx;
                isOdd = true;   
            }
        }

        if(front > back) return new int[0];
        return Arrays.copyOfRange(arr, front, back+1);
    }
}