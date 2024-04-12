import java.util.*;
import java.util.stream.*;

class Solution {
    public int solution(int[] nums) {
        int kind = (int)(Arrays.stream(nums).distinct().count());
        return kind < nums.length/2 ? kind : nums.length/2;
    }
}