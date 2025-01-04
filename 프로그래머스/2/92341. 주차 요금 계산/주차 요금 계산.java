import java.util.*;

class Solution {
    
    class Time {
        int h;
        int m;
        
        public Time(String h, String m) {
            this.h = Integer.parseInt(h);
            this.m = Integer.parseInt(m);
        }
        
        public int getMinGap(Time a) {
            return Math.abs((a.h * 60 + a.m) - (h * 60 + m));
        }
    }
    
    private int calculateCost(int parkMin, int[] fees) {
        if(parkMin <= fees[0]) return fees[1];
        
        int cost = 0;
        
        cost += fees[1];
        
        cost += Math.ceil((double)(parkMin - fees[0]) / fees[2]) * fees[3];
        
        return cost;
    }
    
    public int[] solution(int[] fees, String[] records) {
        TreeMap<Integer, Time> inTime = new TreeMap<>();
        TreeMap<Integer, Integer> parkingMinute = new TreeMap<>();
        
        for(String r : records) {
            int carNum = Integer.parseInt(r.substring(6, 10));
            boolean isIn = r.substring(11).trim().equals("IN");
            Time t = new Time(r.substring(0, 2), r.substring(3, 5));
            
            if(isIn) {
                inTime.put(carNum, t);
            }
            else {
                int acc = parkingMinute.getOrDefault(carNum, 0);
                parkingMinute.put(carNum, acc + inTime.get(carNum).getMinGap(t));
                inTime.remove(carNum);
            }
        }
        
        Time lastTime = new Time("23", "59");
        
        for(Map.Entry<Integer, Time> t : inTime.entrySet()) {
            int carNum = t.getKey();
            Time in = t.getValue();
            
            int acc = parkingMinute.getOrDefault(carNum, 0);
            parkingMinute.put(carNum, acc + in.getMinGap(lastTime));
        }
        
        int[] answer = new int[parkingMinute.size()];
        int idx = 0;
        for(Map.Entry<Integer, Integer> c : parkingMinute.entrySet()) {
            answer[idx++] = calculateCost(c.getValue(), fees);
        }
        
        return answer;
    }
}