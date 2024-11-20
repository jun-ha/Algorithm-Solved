import java.util.*;

class Solution {
    int[][] points;
    
    class Robot {
        Queue<Integer> route = new ArrayDeque<>();
        int curX;
        int curY;
        int nextX;
        int nextY;
        boolean stopped;
        
        Robot(int[] r) {
            int tmpPoint = r[0];
            this.curX = points[tmpPoint - 1][0];
            this.curY = points[tmpPoint - 1][1];
            this.nextX = points[tmpPoint - 1][0];
            this.nextY = points[tmpPoint - 1][1];
            
            for(int i = 1; i < r.length; i++) {
                route.add(r[i]);
            }
        }
        
        boolean isStop() {
            return stopped;
        }
        
        void move() {
            if(isStop()) return;
            
            if(curX == nextX && curY == nextY) {
                if(route.isEmpty()) {
                    stopped = true;
                    return;
                }
                int nextPoint = route.poll();
                nextX = points[nextPoint - 1][0];
                nextY = points[nextPoint - 1][1];
            }
            
            if(curX != nextX) {
                if(curX < nextX) curX++;
                else curX--;
            } else {
                if(curY < nextY) curY++;
                else curY--;
            }
        }
        
        int[] getCur() {
            return new int[]{curX, curY};
        }
    }

    public int countDanger(List<Robot> lst) {
        int[][] check = new int[101][101];
        int count = 0;
        for(Robot r : lst) {
            if(r.isStop()) continue;

            int[] cur = r.getCur();
            check[cur[0]][cur[1]]++;
            if(check[cur[0]][cur[1]] == 2) count++;
        }        
        return count;
    }
    
    public int solution(int[][] points, int[][] routes) {
        this.points = points;
        
        List<Robot> lst = new ArrayList<>();
        
        for(int[] route : routes) {
            Robot robot = new Robot(route);
            lst.add(robot);            
        }
        
        int answer = 0;
        answer += countDanger(lst);
        while(true) {
            boolean isAllStop = true;
            for(Robot r : lst) {
                if(!r.isStop()) {
                    isAllStop = false;
                    r.move();
                }
            }
            if(isAllStop) break;
            
            answer += countDanger(lst);
        }
        
        return answer;
    }
}