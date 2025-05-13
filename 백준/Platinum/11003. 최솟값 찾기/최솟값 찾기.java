import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        //value, idx
        Deque<int[]> deque = new ArrayDeque<>();

        st = new StringTokenizer(br.readLine());
        StringBuilder result = new StringBuilder();
        for(int i = 1; i <= N; i++) {
            int val = Integer.parseInt(st.nextToken());

            while(!deque.isEmpty() && deque.peekLast()[0] >= val) {
                deque.removeLast();
            }

            deque.addLast(new int[]{val, i});

            if(deque.peekFirst()[1] < i - L + 1) {
                deque.removeFirst();
            }

            result.append(deque.peekFirst()[0]).append(" ");
        }
        System.out.println(result);
    }
}