class Solution {
    public int solution(int[][] board, int[][] skill) {
        int answer = 0;
        int N = board.length;
        int M = board[0].length;
        int[][] newBoard = new int[N + 1][M + 1];
        
        for(int[] s : skill) {
            int type = s[0];
            int r1 = s[1];
            int c1 = s[2];
            int r2 = s[3];
            int c2 = s[4];
            int degree = s[5];
            
            if(type == 1) degree *= -1;
            
            newBoard[r1][c1] += degree;
            newBoard[r1][c2+1] += -degree;
            newBoard[r2+1][c1] += -degree;
            newBoard[r2+1][c2+1] += degree;
        }
        
        for(int i = 0; i < N + 1; i++) {
            for(int j = 1; j < M + 1; j++) {
                newBoard[i][j] += newBoard[i][j-1];
            }
        }
        for(int j = 0; j < M + 1; j++) {
            for(int i = 1; i < N + 1; i++) {
                newBoard[i][j] += newBoard[i-1][j];
            }
        }
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(board[i][j] + newBoard[i][j] > 0) answer++;
            }
        }
        
        
        return answer;
    }
}