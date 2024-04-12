import java.util.*;
import java.util.stream.*;
class Solution {
    public String[] solution(String[] str_list) {
        for(int idx = 0; idx < str_list.length; idx++){
            if(str_list[idx].charAt(0) == 'l'){
                return Arrays.stream(str_list)
                    .limit(idx)
                    .toArray(String[]::new);
            }
            if(str_list[idx].charAt(0) == 'r'){
                return Arrays.stream(str_list)
                    .skip(idx+1)
                    .toArray(String[]::new);
            }
        }
        return new String[0];
    }
}