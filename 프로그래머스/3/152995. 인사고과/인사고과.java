import java.util.*;

class Solution {
    public int solution(int[][] scores) {
        int[] wanho = scores[0];
        Arrays.sort(scores, (a, b) ->
                   a[0] != b[0] ? Integer.compare(b[0], a[0]) : Integer.compare(b[1], a[1]));
        
        List<int[]> rankable = new ArrayList<>();
        
        TreeSet<Integer> biggerSet = new TreeSet<>();
        Set<Integer> sameSet = new HashSet<>();
        
        int before = -1;
        for(int i = 0; i < scores.length; i++) {
            int a = scores[i][0];
            int b = scores[i][1];
            
            if(before != a) {
                before = a;
                sameSet.forEach(n -> biggerSet.add(n));
                sameSet = new HashSet<>();
            } 
            sameSet.add(b);
            
            if(biggerSet.higher(b) != null) {
                if(scores[i].equals(wanho)) return -1;
                continue;
            }
            rankable.add(scores[i]);
        }
        
        rankable.sort((arr1, arr2) -> 
                      Integer.compare(arr2[0] + arr2[1], arr1[0] + arr1[1]));
        
        int rank = 1;
        before = -1;
        for(int i = 0; i < rankable.size(); i++) {
            int[] tmp = rankable.get(i);
            if(before != tmp[0] + tmp[1]) {
                before = tmp[0] + tmp[1];
                rank = i + 1;
            }
            
            if(tmp.equals(wanho)) return rank;
        }        
        
        return 0;
    }
}