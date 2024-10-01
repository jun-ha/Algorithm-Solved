import java.util.*;

class Solution {
    public String solution(String[] str_list, String ex) {
        StringBuilder sb = new StringBuilder("");
        Arrays.stream(str_list).filter(str -> str.indexOf(ex) < 0).forEach(str -> sb.append(str));
        
        return sb.toString();
    }
}