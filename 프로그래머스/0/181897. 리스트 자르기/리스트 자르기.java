import java.util.*;
class Solution {
    public int[] solution(int n, int[] slicer, int[] num_list) {
        int a = slicer[0], b = slicer[1], c = slicer[2];
        switch(n){
            case 1:
                return Arrays.copyOfRange(num_list, 0, b+1);
            case 2:
                return Arrays.copyOfRange(num_list, a, num_list.length);
            case 3:
                return Arrays.copyOfRange(num_list, a, b+1);
            case 4:
                {
                    ArrayList<Integer> list = new ArrayList<>();
                    for(int i = a; i <= b; i += c){
                        list.add(num_list[i]);
                    }
                    return list.stream().mapToInt(i -> i).toArray();
                }
        }
        
        
        return new int[0];
    }
}