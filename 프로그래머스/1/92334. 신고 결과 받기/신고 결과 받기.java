import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        Map<String, Integer> idxMap = new HashMap<>();
        
        boolean[][] reported = new boolean[id_list.length][id_list.length];
        
        for(int i = 0; i < id_list.length; i++) {
            idxMap.put(id_list[i], i);
        }
        
        for(String r : report) {
            String[] ids = r.split(" ");
            reported[idxMap.get(ids[0])][idxMap.get(ids[1])] = true;
        }
        
        List<Integer> badGuys = new ArrayList<>();
        
        for(int i = 0; i < id_list.length; i++) {
            int count = 0;
            for(int j = 0; j < id_list.length; j++) {
                if(reported[j][i]) count++;
                if(count >= k) {
                    badGuys.add(i);
                    break;
                }
            }
        }
        
        int[] answer = new int[id_list.length];
        
        for(int i = 0; i < id_list.length; i++) {
            for(int b : badGuys) {
                if(reported[i][b]) answer[i]++;
            }
        }
        
        
        return answer;
    }
}