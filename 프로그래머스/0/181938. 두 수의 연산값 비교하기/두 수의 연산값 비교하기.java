class Solution {
    public int solution(int a, int b) {
        return Integer.max(Integer.parseInt(Integer.toString(a) + Integer.toString(b)), 2 * a * b);
    }
}