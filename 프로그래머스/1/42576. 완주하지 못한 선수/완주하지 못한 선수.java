import java.util.*;
class Solution {
    public String solution(String[] participant, String[] completion) {
        Map<String, Integer> players = new HashMap<>();
        Arrays.stream(participant).forEach(s -> {
            if(players.containsKey(s)){
                players.put(s, players.get(s)+1);
            }
            else players.put(s, 1); });
        
        for(String complete_player : completion){
            players.compute(complete_player, (k, v) -> v-1);
        }
        
        for(Map.Entry<String, Integer> entry : players.entrySet()){
            if(entry.getValue() == 1) return entry.getKey();
        }
        return "";
    }   
}