import java.util.*;
import java.util.stream.*;

class Solution {
    public int solution(int[] num_list) {
        return Math.max(IntStream.iterate(0, n -> n < num_list.length, n -> n + 2).map(n -> num_list[n]).sum(), IntStream.iterate(1, n -> n < num_list.length, n -> n + 2).map(n -> num_list[n]).sum());
    }
}