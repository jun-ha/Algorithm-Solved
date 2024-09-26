import java.util.*;
import java.io.*;
import java.util.stream.IntStream;

public class Main {

    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        Map<Integer, Set<Integer>> beforeMap = new HashMap<>();
        Map<Integer, Set<Integer>> afterMap = new HashMap<>();


        boolean[] hasBefore = new boolean[N + 1];

        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int before = Integer.parseInt(st.nextToken());
            int after = Integer.parseInt(st.nextToken());

            beforeMap.putIfAbsent(before, new HashSet<>());
            afterMap.putIfAbsent(after, new HashSet<>());

            beforeMap.get(before).add(after);
            afterMap.get(after).add(before);

            hasBefore[after] = true;
        }

        IntStream.rangeClosed(1, N).forEach(n -> {
            if(!hasBefore[n]){
                pq.add(n);
            }
        });

        while(!pq.isEmpty()){
            Integer next = pq.remove();
            sb.append(next).append(" ");

            try{
                beforeMap.get(next).forEach(after -> {
                    afterMap.get(after).remove(next);
                    if(afterMap.get(after).isEmpty()){
                        pq.add(after);
                    }
                });
            } catch (NullPointerException e){
            }
        }

        System.out.println(sb);
    }
}