class Solution {
    public int[][] solution(int[][] arr) {    
        int square = Math.max(arr.length, arr[0].length);
        int[][] answer = new int[square][square];
        for(int row = 0; row < arr.length; row++){
            for(int col = 0; col < arr[0].length; col++){
                answer[row][col] = arr[row][col];
            }
        }
        return answer;
    }
}