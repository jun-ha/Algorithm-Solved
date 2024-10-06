import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main {

    static class Line {
        int small;
        int big;

        public Line(int small, int big) {
            this.small = small;
            this.big = big;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int humans = Integer.parseInt(br.readLine());

        Set<Line> lines = new HashSet<>();

        for(int i = 0; i < humans; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            Line line = new Line(Math.min(a, b), Math.max(a, b));
            lines.add(line);
        }
        int railLength = Integer.parseInt(br.readLine());

        List<Line> orderByBig = lines.stream()
                .filter(l -> l.big - l.small <= railLength)
                .sorted(Comparator.comparingInt(l -> l.big))
                .collect(Collectors.toList());

        PriorityQueue<Line> pq = new PriorityQueue<>(Comparator.comparingInt(l -> l.small));

        int maxValue = 0;

        for (Line line : orderByBig) {
            pq.add(line);
            while(!pq.isEmpty() && pq.peek().small < line.big - railLength) {
                pq.poll();
            }
            maxValue = Math.max(maxValue, pq.size());
        }

        System.out.println(maxValue);
    }
}