import java.util.*;

class Solution {
    private Map<Integer, Set<Integer>> map = new HashMap<>();
    
    public int solution(int N, int number) {
        if(N == number) return 1;
        map.put(1, new HashSet<>());
        map.get(1).add(N);
        
        for(int k = 2; k <= 8; k++) {
            map.put(k, new HashSet<>());
            Set<Integer> setK = map.get(k);
            
            for(int p = k - 1; p >= k / 2; p--) {
                int q = k - p; // p + q = k, p >= q
                
                for(int val1 : map.get(p)) {
                    for(int val2 : map.get(q)) {
                        setK.add(val1 + val2);
                        setK.add(val1 - val2);
                        setK.add(val2 - val1);
                        setK.add(val1 * val2);
                        if(val2 != 0) setK.add(val1 / val2);
                        if(val1 != 0) setK.add(val2 / val1);
                    }
                }
                setK.add(Integer.parseInt(String.valueOf(N).repeat(k)));
                if(setK.contains(number)) return k;
            }
        }
        
        return -1;
    }
}