import java.util.*;
import java.io.*;

public class Main {

    static class Balloon{
        public int id;
        public int move;

        public Balloon(int id, int move){
            this.id = id;
            this.move = move;
        }
    }
    private static Deque<Balloon> deque = new ArrayDeque<>();
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        int id = 1;
        while (st.hasMoreTokens()) {
            int move = Integer.parseInt(st.nextToken());
            deque.addLast(new Balloon(id++, move));
        }

        while(!deque.isEmpty()){
            Balloon nextBalloon = deque.removeFirst();
            sb.append(nextBalloon.id).append(" ");

            if(deque.isEmpty()) break;

            int move = Math.abs(nextBalloon.move);
            boolean dir = nextBalloon.move > 0;

            if(dir){
                for(int i = 1; i < move; i++){
                    deque.addLast(deque.removeFirst());
                }
            } else{
                for(int i = 0; i < move; i++){
                    deque.addFirst(deque.removeLast());
                }
            }
        }
        System.out.println(sb);

    }
}