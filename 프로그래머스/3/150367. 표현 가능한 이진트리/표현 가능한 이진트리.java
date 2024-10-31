import java.util.*;

class Solution {
    String toBinaryString(long number) {
        StringBuilder sb = new StringBuilder();
        while(number > 0) {
            sb.append(number % 2 == 0? "0" : "1");
            number /= 2;
        }
        return sb.reverse().toString();
    }
    
    int checkRoot(String bString, int start, int end) {
        if(start == end) return 1;
        int mid = (start + end) / 2;
        
        if(bString.charAt(mid) == '0') {
            for(int i = start; i <= end; i++) {
                if(bString.charAt(i) == '1') return 0;
            }
            return 1;
        }
        
        return checkRoot(bString, start, mid - 1) * checkRoot(bString, mid + 1, end);
    }
    
    int solution(long number) {
        String bString = toBinaryString(number);
        
        int k = 2;
        while(bString.length() > k - 1) {
            k *= 2;
        }
        bString = "0".repeat(k - 1 - bString.length()) + bString;
        
        return checkRoot(bString, 0, bString.length() - 1);
    }
    
    public int[] solution(long[] numbers) {
        int[] answer = new int[numbers.length];
        
        int idx = 0;
        for(long n : numbers) {
            answer[idx++] = solution(n);
        }
        
        return answer;
    }
}