import java.util.*;
import java.util.stream.*;

class Solution {
    private static class Music {
        int id;
        int playTime;
        
        public Music(int id, int playTime) {
            this.id = id;
            this.playTime = playTime;
        }
    }
    
    public int[] solution(String[] genres, int[] plays) {
        Map<String, Integer> genreCount = new HashMap<>();
        Map<String, PriorityQueue<Music>> playTimeCount = new HashMap<>();
        
        for(int i = 0; i < genres.length; i++) {
            String genre = genres[i];
            int playTime = plays[i]; 
            
            genreCount.put(genre, genreCount.getOrDefault(genre, 0) + playTime);
            Music music = new Music(i, playTime);
            
            if(playTimeCount.containsKey(genre)) {
                playTimeCount.get(genre).add(music);
            } else {
                PriorityQueue<Music> pq = 
                    new PriorityQueue<>((m1, m2) -> Integer.compare(m2.playTime, m1.playTime)); 
                
                pq.add(music);
                playTimeCount.put(genre, pq);
            }
        }
        
        List<Integer> list = new ArrayList<>();
        
        genreCount
            .entrySet()
            .stream()
            .sorted((e1, e2) -> Integer.compare(e2.getValue(), e1.getValue()))
            .forEach(e -> {
                String genre = e.getKey();
            
                PriorityQueue<Music> pq = playTimeCount.get(genre);
                int maxCount = 2;
                while(maxCount > 0 && !pq.isEmpty()) {
                    maxCount--;
                    list.add(pq.poll().id);
                }
            });
        
        
        
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}