import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int[][] dp;
    static int[][] board;
    static int boardRow;
    static int boardCol;

    static int[] dRow = {-1, 1, 0, 0};
    static int[] dCol = {0, 0, -1, 1};

    static boolean isValidRange(int r, int c) {
        return 0 <= r && r < boardRow && 0 <= c && c < boardCol;
    }

    static int solution(int r, int c) {
        if(dp[r][c] != -1) return dp[r][c];
        if(r == boardRow - 1 && c == boardCol - 1) return 1;

        int cases = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + dRow[i];
            int nc = c + dCol[i];

            if(isValidRange(nr, nc) && board[nr][nc] < board[r][c]) {
                cases += solution(nr, nc);
            }
        }
        dp[r][c] = cases;
        return dp[r][c];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        boardRow = Integer.parseInt(st.nextToken());
        boardCol = Integer.parseInt(st.nextToken());

        board = new int[boardRow][boardCol];
        for(int i = 0; i < boardRow; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < boardCol; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dp = new int[boardRow][boardCol];
        for(int i = 0; i < boardRow; i++) {
            Arrays.fill(dp[i], -1);
        }

        System.out.println(solution(0, 0));
    }
}