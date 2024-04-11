import java.util.*;

class Solution {
    public int[] solution(int l, int r) {
        List<Integer> list = new ArrayList<>();
        for(int num = l; num <= r; num++){
            if(isOnlyZeroOrFive(num)) list.add(num);
        }

        return list.isEmpty()? new int[] {-1} : list.stream().mapToInt(i -> i).toArray();
    }
    
    boolean isOnlyZeroOrFive(int num){
        String numStr = Integer.toString(num);
        for(char c : numStr.toCharArray()){
            if(c != '0' && c != '5') return false;
        }
        return true;
    }
}