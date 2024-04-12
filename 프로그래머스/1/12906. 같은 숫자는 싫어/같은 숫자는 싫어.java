import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        ArrayList<Integer> list = new ArrayList<>();
        int before = arr[0];
        list.add(before);
        for(int num : arr){
            if(num == before) continue;
            before = num;
            list.add(before);
        }
        return list.stream().mapToInt(i->i).toArray();
    }
}