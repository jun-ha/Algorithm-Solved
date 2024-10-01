import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        Map<String, Integer> map = new HashMap<>();
        for(String[] info : clothes) {
            String kind = info[1];
            map.put(kind, map.getOrDefault(kind, 0) + 1);
        }
        
        return map.values().stream().reduce(1, (a, b) -> a * (b + 1)) - 1;
    }
}