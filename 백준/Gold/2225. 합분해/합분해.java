import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][] dp;
    static int solution(int n, int k) {
        if(dp[n][k] != 0) return dp[n][k];

        if(k == 0) return 0;
        if(n == 0 || k == 1) return 1;

        int result = 0;
        for(int i = 0; i <= n; i++) {
            result += solution(i, k - 1) % 1000000000;
            result %= 1000000000;
        }
        dp[n][k] = result;
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        dp = new int[N+1][K+1];
        System.out.println(solution(N, K));
    }
}