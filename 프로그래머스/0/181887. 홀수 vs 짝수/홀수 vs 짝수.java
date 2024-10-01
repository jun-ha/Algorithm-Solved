import java.util.*;
import java.util.stream.*;

class Solution {
    public int solution(int[] num_list) {
        int evenSum = IntStream.iterate(0, n -> n < num_list.length, n -> n + 2).map(n -> num_list[n]).sum();
        int oddSum = IntStream.iterate(1, n -> n < num_list.length, n -> n + 2).map(n -> num_list[n]).sum();
        
        return Integer.max(evenSum, oddSum);
    }
}