import java.util.*;
import java.io.*;

public class Main{
    private static Deque<Integer> deque = new ArrayDeque<>();
    private static StringBuilder sb = new StringBuilder();

    private static void solution(String query){
        StringTokenizer st = new StringTokenizer(query);
        int command = Integer.parseInt(st.nextToken());
        switch(command){
            case 1: deque.addFirst(Integer.parseInt(st.nextToken())); return;
            case 2: deque.addLast(Integer.parseInt(st.nextToken())); return;
            case 3: sb.append(deque.isEmpty()? -1 : deque.removeFirst()).append('\n'); return;
            case 4: sb.append(deque.isEmpty()? -1 : deque.removeLast()).append('\n'); return;
            case 5: sb.append(deque.size()).append('\n'); return;
            case 6: sb.append(deque.isEmpty()? 1 : 0).append('\n'); return;
            case 7: sb.append(deque.isEmpty()? -1 : deque.peekFirst()).append('\n'); return;
            case 8: sb.append(deque.isEmpty()? -1 : deque.peekLast()).append('\n'); return;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        while(n-->0){
            solution(br.readLine());
        }
        System.out.println(sb);
    }
}