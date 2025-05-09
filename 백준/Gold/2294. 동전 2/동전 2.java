import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] coins = new int[N];
        for(int i = 0; i < N; i++) {
            coins[i] = Integer.parseInt(br.readLine());
        }
        coins = Arrays.stream(coins).sorted().distinct().toArray();

        int[] dp = new int[K + 1];
        int INF = 99999;
        Arrays.fill(dp, INF);
        dp[0] = 0;

        for(int i = coins.length - 1; i >= 0; i--) {
            int val = coins[i];

            for(int j = 0; j + val <= K; j++) {
                dp[j + val] = Math.min(dp[j + val], dp[j] + 1);
            }
        }
        System.out.println(dp[K] == INF ? -1 : dp[K]);
    }
}