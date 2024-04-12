import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        ArrayList<Integer> list = new ArrayList<>();
        int totalProcesses = progresses.length;
        int idx = 0;
        while(idx < totalProcesses){
            for(int i = idx; i < totalProcesses; i++){
                progresses[i] += speeds[i];
            }    
            if(progresses[idx] >= 100){
                int count = 1;
                while(idx+1 < totalProcesses && progresses[idx+1] >= 100) {
                    idx++;
                    count++;
                }
                list.add(count);
                idx++;
            }
        }
        return list.stream().mapToInt(i->i).toArray();
        
    }
}