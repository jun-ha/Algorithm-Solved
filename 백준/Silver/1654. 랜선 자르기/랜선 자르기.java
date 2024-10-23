import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int have, need;

        StringTokenizer st = new StringTokenizer(br.readLine());
        have = Integer.parseInt(st.nextToken());
        need = Integer.parseInt(st.nextToken());

        int[] lines = new int[have];

        for(int i = 0; i < have; i++) {
            lines[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(lines);

        long minRange = 1;
        long maxRange = lines[have-1];

        long answer = Integer.MIN_VALUE;
        while(minRange <= maxRange) {
            long mid = (minRange + maxRange) / 2;

            long tmp = 0;
            for(int l : lines) {
                tmp += l / mid;
            }

            if(tmp >= need) {
                minRange = mid + 1;
                answer = Math.max(answer, mid);
            } else {
                maxRange = mid - 1;
            }
        }

        System.out.println(answer);

    }
}