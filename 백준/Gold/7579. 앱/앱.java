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
        int targetValue = Integer.parseInt(st.nextToken());

        int[] values = new int[N];
        int[] costs = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            values[i] = Integer.parseInt(st.nextToken());
        }

        int costSum = 0;
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            costs[i] = Integer.parseInt(st.nextToken());
            costSum += costs[i];
        }

        int[] costArr = new int[costSum + 1];
        Arrays.fill(costArr, -1);
        costArr[0] = 0;

        for(int i = 0; i < N; i++) {
            int tmpCost = costs[i];
            int tmpValue = values[i];
            for(int cost = costSum; cost >= tmpCost; cost--) {
                if(costArr[cost - tmpCost] != -1) {
                    costArr[cost] = Math.max(costArr[cost], costArr[cost - tmpCost] + tmpValue);
                }
            }
        }

        for(int cost = 0; cost <= costSum; cost++) {
            if(costArr[cost] >= targetValue) {
                System.out.println(cost);
                break;
            }
        }
    }
}