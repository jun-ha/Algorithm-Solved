class Solution {
    public int[][] solution(int n) {
        int[][] answer = new int[n][n];
        int count = 0;
        int minRow = 0, minCol = 0;
        int maxRow = n-1, maxCol = n-1;
        while(count < n*n){
            int row = minRow, col = minCol;
            for(; col <= maxCol; col++){
                answer[row][col] = ++count;
            }
            col--; row++;
            for(; row <= maxRow; row++){
                answer[row][col] = ++count;
            }
            row--; col--;
            for(; col >= minCol; col--){
                answer[row][col] = ++count;
            }
            col++; row--;
            for(; row > minRow; row--){
                answer[row][col] = ++count;
            }
            row++;
            minRow++; minCol++; maxRow--; maxCol--;            
        }
        return answer;
    }
}