import java.util.*;
class Solution {
    public String[] solution(String myStr) {
        ArrayList<String> list = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        
        for(char c : myStr.toCharArray()){
            if(c == 'a' || c == 'b' || c == 'c'){
                if(sb.length() != 0) {
                    list.add(sb.toString());
                    sb = new StringBuilder();
                }
                continue;
            }
            sb.append(c);
        }
        
        if(sb.length() != 0) {
            list.add(sb.toString());
        }
        
        return list.isEmpty() ? new String[] {"EMPTY"} : list.toArray(new String[list.size()]);
    }
}