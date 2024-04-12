import java.util.*;
class Solution {
    public String solution(String[] participant, String[] completion) {
        Map<String, Integer> players = new HashMap<>();
        Arrays.stream(participant)
            .forEach(s -> players.put(s, players.getOrDefault(s, 0)+1));
        
        for(String complete_player : completion){
            players.compute(complete_player, (k, v) -> v-1);
        }
        
        for(String key : players.keySet()){
            if(players.get(key) == 1) return key;
        }
        
        return "";
    }   
}