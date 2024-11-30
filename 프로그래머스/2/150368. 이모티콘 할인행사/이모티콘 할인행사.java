import java.util.*;

class Solution {
    int[] prices;
    int[] rateArr;
    int[][] userArr;
    int maxSub = 0;
    int maxProfit = 0;
    
    void dfs(int idx) {
        if(idx >= rateArr.length) {
            int subCount = 0;
            int profit = 0;

            for(int[] user : userArr) {
                int disValue = user[0];
                int subValue = user[1];

                int userCost = 0;
                for(int j = 0; j < rateArr.length; j++) {
                    if(rateArr[j] >= disValue) { //buy
                        userCost += prices[j] / 100 * (100 - rateArr[j]);
                    }
                }
                if(userCost >= subValue) {
                    subCount++;
                } else {
                    profit += userCost;
                }
            }
            
            if(subCount > maxSub) {
                maxSub = subCount;
                maxProfit = profit;
            } else if (subCount == maxSub) {
                maxProfit = Math.max(maxProfit, profit);
            }
            return;
        }
        
        for(int r = 10; r <= 40; r += 10) {
            rateArr[idx] = r;
            dfs(idx + 1);
        }
    }
    
    public int[] solution(int[][] users, int[] emoticons) {
        rateArr = new int[emoticons.length];
        prices = emoticons;
        userArr = users;
        
        dfs(0);
        return new int[]{maxSub, maxProfit};
    }
}