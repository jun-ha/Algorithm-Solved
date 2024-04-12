import java.util.*;

class Solution {
    public int solution(String[] order) {
        int totalPrice = 0;
        for(String menu : order){
            if(menu.contains("americano") || menu.equals("anything")) totalPrice += 4500;
            else totalPrice += 5000;
        }
        return totalPrice;
    }
}