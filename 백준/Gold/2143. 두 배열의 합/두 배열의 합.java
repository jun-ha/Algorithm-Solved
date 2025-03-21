import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static long[] getSumArr(int[] arr) {
        long[] sumArr = new long[arr.length + 1];
        sumArr[0] = 0;
        for(int i = 0; i < arr.length; i++) {
            sumArr[i + 1] = sumArr[i] + arr[i];
        }
        return sumArr;
    }

    static Map<Long, Integer> getCaseMap(long[] sumArr) {
        Map<Long, Integer> sumMap = new HashMap<>();
        for(int i = 0; i < sumArr.length - 1; i++) {
            for(int j = i + 1; j < sumArr.length; j++) {
                long oneCase = sumArr[j] - sumArr[i];
                sumMap.put(oneCase, sumMap.getOrDefault(oneCase, 0) + 1);
            }
        }
        return sumMap;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int N = Integer.parseInt(br.readLine());

        int[] A = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        long[] sumA  = getSumArr(A);

        int M = Integer.parseInt(br.readLine());
        int[] B = new int[M];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < M; i++) {
            B[i] = Integer.parseInt(st.nextToken());
        }
        long[] sumB = getSumArr(B);

        Map<Long, Integer> mapA = getCaseMap(sumA);
        Map<Long, Integer> mapB = getCaseMap(sumB);

        long answer = 0;
        for(Map.Entry<Long, Integer> entry : mapA.entrySet()) {
            long val1 = entry.getKey();

            if(mapB.containsKey(T - val1)) {
                answer += (long)entry.getValue() * mapB.get(T - val1);
            }
        }

        System.out.println(answer);
    }
}