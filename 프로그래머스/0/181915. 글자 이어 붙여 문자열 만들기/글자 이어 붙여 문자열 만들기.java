import java.util.*;

class Solution {
    public String solution(String my_string, int[] index_list) {
        StringBuilder sb = new StringBuilder();
        Arrays.stream(index_list).forEach(n -> sb.append(my_string.charAt(n)));
        return sb.toString();
    }
}