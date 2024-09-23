import java.util.*;
import java.io.*;

public class Main{
    private static Queue<Integer> queue = new LinkedList<>();
    private static int last;
    private static StringBuilder sb = new StringBuilder();

    private static void solution(String query){
        StringTokenizer st = new StringTokenizer(query);
        switch(st.nextToken()){
            case "push":
                last = Integer.parseInt(st.nextToken());
                queue.add(last);
                return;
            case "pop": sb.append(queue.isEmpty()? -1 : queue.poll()).append('\n'); return;
            case "size": sb.append(queue.size()).append('\n'); return;
            case "empty": sb.append(queue.isEmpty()? 1 : 0).append('\n'); return;
            case "front": sb.append(queue.isEmpty()? -1 : queue.peek()).append('\n'); return;
            case "back": sb.append(queue.isEmpty()? -1 : last).append('\n'); return;
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