import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        ArrayList<Integer> list = new ArrayList<>();
        for(int i = 0; i < arr.length; i++){
            if(list.isEmpty()) list.add(arr[i]);
            else if(list.get(list.size()-1) < arr[i]) list.add(arr[i]);
            else {
                list.remove(list.size()-1);
                i--;
            }
        }
        return list.stream().mapToInt(i -> i).toArray();
    }
}