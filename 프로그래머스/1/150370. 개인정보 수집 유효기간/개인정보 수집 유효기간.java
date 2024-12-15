import java.util.*;
import java.time.*;

class Solution {
    LocalDate parseDate(String date) {
        StringTokenizer st = new StringTokenizer(date, ". ");
        int year = Integer.parseInt(st.nextToken());
        int month = Integer.parseInt(st.nextToken());
        int day = Integer.parseInt(st.nextToken());
        
        return LocalDate.of(year, month, day);
    }
    
    public int[] solution(String today, String[] terms, String[] privacies) {
        LocalDate todayDate = parseDate(today);
        
        List<Integer> answer = new ArrayList<>();
        Map<Character, Integer> expiration = new HashMap<>();
        
        for(String term : terms) {
            int exp = Integer.parseInt(term.substring(2));
            expiration.put(term.charAt(0), exp);
        }
        
        int idx = 1;
        for(String privacy : privacies) {
            LocalDate regDate = parseDate(privacy);
            Character kind = privacy.charAt(11);
            int add = expiration.get(kind);
            
            LocalDate expDate = regDate.plusMonths(add).minusDays(1);
            if(expDate.getDayOfMonth() > 28) {
                expDate = LocalDate.of(expDate.getYear(), expDate.getMonth(), 28);
            }
            
            if(expDate.isBefore(todayDate)) {
                answer.add(idx);
            }
            idx++;
        }
        
        return answer
            .stream()
            .mapToInt(Integer::intValue)
            .toArray();
    }
}