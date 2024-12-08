import java.util.*;

class Solution {
    boolean check(Map<String, Integer> want, Map<String, Integer> have) {
        for(Map.Entry<String, Integer> e : want.entrySet()) {
            if(have.getOrDefault(e.getKey(), 0) < e.getValue()) {
                return false;
            }
        }
        return true;
    }
    
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        
        Map<String, Integer> wantMap = new HashMap<>();
        for(int i = 0; i < want.length; i++) {
            wantMap.put(want[i], number[i]);
        }
        
        Map<String, Integer> tmp = new HashMap<>();
        for(int i = 0; i < 10; i++) {
            tmp.put(discount[i], tmp.getOrDefault(discount[i], 0) + 1);
        }
        
        
        for(int i = 0; i < discount.length - 10; i++) {
            if(check(wantMap, tmp)) answer++;
            
            int count = tmp.get(discount[i]);
            if(count >= 2) {
                tmp.put(discount[i], count - 1);
            } else {
                tmp.remove(discount[i]);    
            }
            
            tmp.put(discount[i + 10], tmp.getOrDefault(discount[i + 10], 0) + 1);
        }
        if(check(wantMap, tmp)) answer++;
        return answer;
    }
}