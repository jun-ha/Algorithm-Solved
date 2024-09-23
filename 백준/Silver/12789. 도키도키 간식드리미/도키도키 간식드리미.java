import java.util.*;
import java.io.*;


public class Main {
    private static Stack<Integer> stack = new Stack<>();
    private static int next = 1;
    private static int N;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            if(!stack.isEmpty() && stack.peek() == next){
                next++;
                stack.pop();
                i--;
                continue;
            }

            int tmp = Integer.parseInt(st.nextToken());
            if(tmp == next) {
                next++;
                continue;
            }
            stack.push(tmp);
        }
        while(true){
            if(!stack.isEmpty() && stack.peek() == next){
                next++;
                stack.pop();
                continue;
            }
            break;
        }
        System.out.println(stack.isEmpty() ? "Nice" : "Sad");
    }
}