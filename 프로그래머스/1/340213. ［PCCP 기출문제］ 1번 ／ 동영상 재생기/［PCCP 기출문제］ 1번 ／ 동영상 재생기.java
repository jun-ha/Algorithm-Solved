class Solution {
    class Time {
        int minute;
        int second;
        
        Time (int m, int s) {
            this.minute = m;
            this.second = s;
        }
        
        Time(String s) {
            this(Integer.parseInt(s.substring(0, 2)), Integer.parseInt(s.substring(3)));
        }
        
        public void add(int s) {
            second += s;
            if(second > 60) {
                second -= 60;
                minute++;
            }
        }
        
        public void sub(int s) {
            second -= s;
            if(second < 0) {
                minute--;
                second += 60;
            }
            
            if(minute < 0) {
                minute = 0;
                second = 0;
            }
        }
        
        public void sync(Time t) {
            minute = t.minute;
            second = t.second;
        }
        
        public boolean isGreaterThanOrEqualTo(Time t) {
            return minute == t.minute? second >= t.second : minute > t.minute;
        }
        
        @Override
        public String toString() {
            return new StringBuilder()
                .append(minute < 10 ? "0" : "")
                .append(minute)
                .append(":")
                .append(second < 10 ? "0" : "")
                .append(second)
                .toString();
        }
        
    }
    
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        Time max = new Time(video_len);
        Time now = new Time(pos);
        Time op_s = new Time(op_start);
        Time op_e = new Time(op_end);
        
        if(now.isGreaterThanOrEqualTo(op_s) && !now.isGreaterThanOrEqualTo(op_e)) now.sync(op_e);
        
        for (String command : commands) {
            if(command.equals("next")) now.add(10);
            else now.sub(10);
            
            System.out.println(now);
            
            if(now.isGreaterThanOrEqualTo(max)) now.sync(max);
            if(now.isGreaterThanOrEqualTo(op_s) && !now.isGreaterThanOrEqualTo(op_e)) now.sync(op_e);
        }
        
        return now.toString();
    }
}