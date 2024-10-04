import java.util.*;
import java.io.*;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static Map<Integer, Integer> map = new HashMap<>();

    static int[][] original_grid;
    static int[][] grid;
    static int cell_id = 2;
    static int gridRow;
    static int gridCol;

    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    static class Coordinate {
        int r;
        int c;
        public Coordinate(int x, int y) {
            this.r = x;
            this.c = y;
        }
    }

    static boolean isValidRange(int row, int col) {
        return 0 <= row && row < gridRow && 0 <= col && col < gridCol;
    }

    static void bfs(int row, int col) {
        Queue<Coordinate> q = new ArrayDeque<>();
        q.add(new Coordinate(row, col));

        int count = 0;

        while(!q.isEmpty()) {
            Coordinate curr = q.poll();

            if(grid[curr.r][curr.c] != 0) continue;
            grid[curr.r][curr.c] = cell_id;
            count++;

            for(int i = 0; i < 4; i++) {
                int nr = curr.r + dx[i];
                int nc = curr.c + dy[i];

                if(isValidRange(nr, nc) && grid[nr][nc] == 0) {
                    q.add(new Coordinate(nr, nc));
                }
            }
        }

        map.put(cell_id, count);
        cell_id++;
    }

    static int checkNear(int row, int col) {
        Set<Integer> set = new HashSet<>();
        int near = 0;

        for(int i = 0; i < 4; i++) {
            int nr = row + dx[i];
            int nc = col + dy[i];

            if(isValidRange(nr, nc) && original_grid[nr][nc] != 1 && !set.contains(grid[nr][nc])) {
                set.add(grid[nr][nc]);
                near += map.get(grid[nr][nc]);
            }
        }

        return near;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        gridRow = Integer.parseInt(st.nextToken());
        gridCol = Integer.parseInt(st.nextToken());

        grid = new int[gridRow][gridCol];
        original_grid = new int[gridRow][gridCol];

        for(int i = 0; i < gridRow; i++) {
            String line = br.readLine();
            for(int j = 0; j < gridCol; j++) {
                grid[i][j] = line.charAt(j) - '0';
                original_grid[i][j] = grid[i][j];
            }
        }

        for(int i = 0; i < gridRow; i++) {
            for(int j = 0; j < gridCol; j++) {
                if(grid[i][j] == 0) {
                    bfs(i, j);
                }
            }
        }

        for(int i = 0; i < gridRow; i++) {
            for (int j = 0; j < gridCol; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = (checkNear(i, j) + 1) % 10;
                    sb.append(grid[i][j]);
                } else {
                    sb.append(0);
                }
            }
            sb.append('\n');
        }

        System.out.println(sb);
    }
}