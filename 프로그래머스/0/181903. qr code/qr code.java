import java.util.*;

class Solution {
    public String solution(int q, int r, String code) {
        StringBuilder sb = new StringBuilder();
        for(int idx = 0; idx < code.length(); idx++){
            if(idx % q == r) sb.append(code.charAt(idx));
        }
        return sb.toString();
    }
}