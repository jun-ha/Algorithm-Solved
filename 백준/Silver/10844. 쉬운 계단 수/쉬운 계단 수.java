import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[][] dp = new int[N + 1][10];
        for(int i = 1; i <= 9; i++) {
            dp[1][i] = 1;
        }

        for(int i = 2; i <= N; i++) {
            // 끝자리가 0, 9인 경우는 이전 단계의 1, 8의 개수와 동일하다.
            dp[i][0] = dp[i-1][1];
            dp[i][9] = dp[i-1][8];

            for(int j = 1; j <= 8; j++) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
            }
        }
        
        System.out.println(
                Arrays.stream(dp[N]).reduce(0, (a, b) -> (a + b) % 1000000000)
        );
    }
}