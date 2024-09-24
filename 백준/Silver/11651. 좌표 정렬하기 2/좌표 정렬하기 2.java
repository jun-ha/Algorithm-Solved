import java.util.*;
import java.io.*;

public class Main {

    private static StringBuilder sb = new StringBuilder();

    private static class Coordinate {
        int x;
        int y;
        public Coordinate(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        Coordinate[] coordinates = new Coordinate[N];

        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            coordinates[i] =  new Coordinate(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        Arrays.sort(coordinates, (c1, c2) -> c1.y == c2.y ? Integer.compare(c1.x, c2.x) : Integer.compare(c1.y, c2.y));
        Arrays.stream(coordinates).forEach(c -> sb.append(c.x).append(" ").append(c.y).append('\n'));

        System.out.println(sb);
    }


}