import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][] dp;
    static int[] sizes;
    static int[] accSum;
    static int solution(int a, int b) {
        if(dp[a][b] != 0) return dp[a][b];

        if(a == b) {
            return 0;
        }
        int minVal = Integer.MAX_VALUE;
        for(int i = 1; i <= b - a; i++) {
            minVal = Math.min(minVal, solution(a, b - i) + solution(b - i + 1, b));
        }
        dp[a][b] = minVal + accSum[b] - accSum[a - 1];
        return dp[a][b];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while(T-- > 0) {
            int K = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());

            sizes = new int[K + 1];
            accSum = new int[K + 1];
            for (int i = 1; i <= K; i++) {
                sizes[i] = Integer.parseInt(st.nextToken());
                accSum[i] = accSum[i - 1] + sizes[i];
            }

            dp = new int[K+1][K+1];
            System.out.println(solution(1, K));
        }
    }
}