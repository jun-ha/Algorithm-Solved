import java.util.*;
import java.util.stream.*;

class Solution {
    
    boolean isOneWordDiff(String a, String b){
        return 
            IntStream.range(0, a.length())
            .filter(i -> a.charAt(i) != b.charAt(i))
            .count() == 1 ? true : false;
    }
    
    class Data{
        String word;
        int count;
        Data(String word, int count){
            this.word = word;
            this.count = count;
        }
    }
    
    public int solution(String begin, String target, String[] words) {
        Set<String> set = new HashSet<>();
        Queue<Data> q = new LinkedList<>();
        q.add(new Data(begin, 0));
        
        while(!q.isEmpty()){
            Data data = q.poll();
            String word = data.word;
            int count = data.count;
            
            if(set.contains(word)) continue;
            set.add(word);
            if(word.equals(target)) return count;
            
            for(String nextWord : words){
                if(isOneWordDiff(word, nextWord)) q.add(new Data(nextWord, count+1));
            }
        }
        return 0;
    }
}