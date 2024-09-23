import java.util.*;
import java.io.*;

public class Main{
    private static Stack<Integer> stack = new Stack<>();
    private static Queue<Integer> queue = new LinkedList<>();
    private static StringBuilder sb = new StringBuilder();

    private static void solution(String query){
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        boolean[] isQueue = new boolean[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            if(st.nextToken().equals("0")){
                isQueue[i] = true;
            }
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            String next = st.nextToken();
            if(isQueue[i]){
                stack.push(Integer.parseInt(next));
            }
        }

        int M = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        while(st.hasMoreTokens()){
            queue.add(Integer.parseInt(st.nextToken()));
        }
        while(M-->0){
            if(!stack.isEmpty()){
                sb.append(stack.pop()).append(" ");
            } else {
                sb.append(queue.poll()).append(" ");
            }
        }
        System.out.println(sb);
    }
}