import java.util.*;

class Solution {
    class Bridge {
        Queue<Integer> blocks = new ArrayDeque<>();
        final int maxWeight;
        int curWeight = 0;
        int tmpTrucks = 0;
        int time = 0;
        
        public Bridge(int length, int maxWeight) {
            for(int i = 0; i < length; i++) {
                blocks.add(0);
            }
            this.maxWeight = maxWeight;
        }
        
        public boolean isAvailable(int truck) {
            if(curWeight + truck <= maxWeight) return true;
            if(curWeight - blocks.peek() + truck <= maxWeight) return true;
            
            return false;
        }
        
        public void add(int truck) {
            int out = blocks.poll();
            if(out > 0) {
                curWeight -= out;
                tmpTrucks--;
            }        
            
            blocks.add(truck);
            curWeight += truck;
            tmpTrucks++;
            
            time++;
        }
        
        public void tick() {
            int out = blocks.poll();
            if(out > 0) {
                curWeight -= out;
                tmpTrucks--;
            }
            time++;
            blocks.add(0);
        }
        
        public int finish() {
            while(tmpTrucks > 0) {
                tick();
            }
            return time;
        }
        
        public void show() {
            System.out.println("time : " + time);
            System.out.println("curWeight : " + curWeight);
        }
        
    } 
    
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Bridge bridge = new Bridge(bridge_length, weight);
        
        for(int i = 0; i < truck_weights.length; i++) {
            int t = truck_weights[i];
            
            if(bridge.isAvailable(t)) {
                bridge.add(t);
            } else {
                bridge.tick();
                i--;
                continue;
            }
        }
        
        return bridge.finish();
    }
}