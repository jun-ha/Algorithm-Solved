class Solution {
    public int solution(int[] num_list, int n) {
        for(int k : num_list) {
            if(k == n) return 1;
        }
        return 0;
    }
}