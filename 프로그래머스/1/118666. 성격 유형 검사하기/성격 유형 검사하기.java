import java.util.*;

class Solution {
    public String solution(String[] survey, int[] choices) {
        Map<Character, Integer> score = new HashMap<>();
        
        for(int i = 0; i < survey.length; i++) {
            if(choices[i] < 4) {
                score.put(survey[i].charAt(0), score.getOrDefault(survey[i].charAt(0), 0) + 4 - choices[i]);
            } else {
                score.put(survey[i].charAt(1), score.getOrDefault(survey[i].charAt(1), 0) + choices[i] - 4);
            }
        }
        
        return new StringBuilder()
            .append(score.getOrDefault('R', 0) >= score.getOrDefault('T', 0) ? 'R' : 'T')
            .append(score.getOrDefault('C', 0) >= score.getOrDefault('F', 0) ? 'C' : 'F')
            .append(score.getOrDefault('J', 0) >= score.getOrDefault('M', 0) ? 'J' : 'M')
            .append(score.getOrDefault('A', 0) >= score.getOrDefault('N', 0) ? 'A' : 'N')
            .toString();
    }
}