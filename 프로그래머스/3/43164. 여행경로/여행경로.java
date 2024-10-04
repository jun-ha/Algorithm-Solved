import java.util.*;

class Solution {
    Map<String, Map<String, Integer>> graph = new HashMap<>();
    int ticketLeft;
    
    //List<String> route = new ArrayList<>();
    Stack<String> route = new Stack<>();
    
    void dfs(String departure) {
        if(ticketLeft == 0) return;
        
        Map<String, Integer> near = graph.get(departure);
        if(near == null) return;
        
        for(Map.Entry<String, Integer> entry : near.entrySet()) {
            String to = entry.getKey();
            int left = entry.getValue();
            
            if(left == 0) continue;
            
            entry.setValue(left - 1);
            ticketLeft--;
            //route.add(to);
            route.push(to);
            dfs(to);
            
            if(ticketLeft == 0) return;
            
            entry.setValue(left + 1);
            ticketLeft++;
            //route.remove(to);
            route.pop();
        }
        
        
        
    }
    
    String[] getAnswer() {
        String[] answer = new String[route.size()];
        
        return route.toArray(new String[0]);
    }
    
    public String[] solution(String[][] tickets) {
        String[] answer = {};
        ticketLeft = tickets.length;
        
        for(String[] ticket : tickets) {
            String from = ticket[0];
            String to = ticket[1];
            
            if(!graph.containsKey(from)) {
                graph.put(from, new TreeMap<String, Integer>());
            }
            
            Map<String, Integer> near = graph.get(from);
            
            near.put(to, near.getOrDefault(to, 0) + 1);
        }
        
        route.add("ICN");
        dfs("ICN");
        
        return getAnswer();
    }
}