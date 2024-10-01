import java.util.*;

class Solution {
    public String solution(String[] arr) {
        StringBuilder sb = new StringBuilder();
        Arrays.stream(arr).forEach(c -> sb.append(c));
        return sb.toString();
    }
}