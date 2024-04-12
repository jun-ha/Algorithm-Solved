import java.util.*;
class Solution {
    public String[] solution(String[] str_list) {
        for(int idx = 0; idx < str_list.length; idx++){
            if(str_list[idx].charAt(0) == 'l'){
                return Arrays.copyOfRange(str_list, 0, idx);
            }
            if(str_list[idx].charAt(0) == 'r'){
                return Arrays.copyOfRange(str_list, idx+1, str_list.length);
            }
        }
        return new String[0];
    }
}