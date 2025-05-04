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
        int[] cases = new int[K + 1];

        for(int i = 0; i < N; i++) {
            coins[i] = Integer.parseInt(br.readLine());
        }

        coins = Arrays.stream(coins)
                .filter(i -> i <= K)
                .sorted()
                .toArray();

        cases[0] = 1;
        for(int coin : coins) {
            for(int i = 0; i <= K; i++) {
                if(cases[i] != 0 && i + coin <= K) {
                    cases[i + coin] += cases[i];
                }
            }
        }

        System.out.println(cases[K]);
    }
}