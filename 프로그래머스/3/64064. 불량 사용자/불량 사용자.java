import java.util.*;

class Solution {
    boolean[] visited;
    List<Integer>[] cases;
    Set<String> answerSet = new HashSet<>();
    
    void dfs(int idx) {
        if(idx == cases.length) {
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < visited.length; i++) {
                if(visited[i]) sb.append(i);
            }
            answerSet.add(sb.toString());
            return;
        }
        
        List<Integer> possibles = cases[idx];
        
        for(int p : possibles) {
            if(visited[p]) continue;
            
            visited[p] = true;
            dfs(idx + 1);
            visited[p] = false;
        }
    }
    
    boolean isMatched(String a, String b) {
        if(a.length() != b.length()) return false;
        for(int i = 0; i < a.length(); i++) {
            if(a.charAt(i) == '*' || b.charAt(i) == '*') continue;
            if(a.charAt(i) != b.charAt(i)) return false;
        }
        return true;
    }
    
    public int solution(String[] user_id, String[] banned_id) {
        visited = new boolean[user_id.length];
        cases = new List[banned_id.length];
        
        for(int i = 0; i < banned_id.length; i++) {
            cases[i] = new ArrayList<>();
            for(int j = 0; j < user_id.length; j++) {
                if(isMatched(banned_id[i], user_id[j])) {
                    cases[i].add(j);
                }
            }
        }
        
        dfs(0);
        
        return answerSet.size();
    }
}