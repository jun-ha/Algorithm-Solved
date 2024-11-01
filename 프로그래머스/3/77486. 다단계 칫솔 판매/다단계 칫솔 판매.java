import java.util.*;

class Solution {
    class Node {
        String parent;
        int profit = 0;
    }
    
    public void addProfit(Map<String, Node> map, String name, int profit) {
        Node node = map.get(name);
        if(profit / 10 == 0) {
            node.profit += profit;
            return;
        }
        
        int notMine = profit / 10;
        int mine = profit - notMine;
        
        node.profit += mine;
        
        if(node.parent == null) return;
        
        addProfit(map, node.parent, notMine);
    }
    
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        Map<String, Node> map = new HashMap<>();
        for(int i = 0; i < enroll.length; i++) {
            Node node = new Node();
            map.put(enroll[i], node);
            
            if(referral[i].equals("-")) continue;
            node.parent = referral[i];
        }
        
        for(int i = 0; i < seller.length; i++) {
            addProfit(map, seller[i], amount[i] * 100);
        }
        
        int[] answer = new int[enroll.length];
        int idx = 0;
        for(String name : enroll) {
            answer[idx++] = map.get(name).profit;
        }
        
        return answer;
    }
}