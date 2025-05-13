import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int[][] dp;
    static int[][] forest;
    static int[] dRow = {-1, 1, 0, 0};
    static int[] dCol = {0, 0, -1, 1};

    static boolean isValidRange(int r, int c) {
        int N = dp.length;
        return 0 <= r && r < N && 0 <= c && c < N;
    }

    static int solution(int r, int c) {
        if(dp[r][c] != -1) return dp[r][c];

        int result = 0;
        for(int i = 0; i < 4; i++) {
            int nr = r + dRow[i];
            int nc = c + dCol[i];
            if(isValidRange(nr, nc) && forest[r][c] < forest[nr][nc]) {
                result = Math.max(result, solution(nr, nc) + 1);
            }
        }
        dp[r][c] = result;
        return result;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        dp = new int[N][N];
        forest = new int[N][N];
        for(int i = 0; i < N; i++) {
            Arrays.fill(dp[i], -1);
        }

        for(int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                forest[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int result = Integer.MIN_VALUE;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                result = Math.max(result, solution(i, j));
            }
        }

        System.out.println(result + 1);
    }
}