import java.util.*;
import java.io.*;

public class Main {
    static int[][] map;
    static int row;
    static int col;

    static int[] dRow = {-1, 1, 0, 0};
    static int[] dCol = {0, 0, -1, 1};

    static int[][] adjs;

    static class Bridge {
        int to;
        int length = -1;
    }

    static boolean isValidRange(int r, int c) {
        return 0 <= r && r < row && 0 <= c && c < col;
    }

    static void bfsToNumbering(int r, int c, int islandNum, boolean[][] visited) {
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{r, c});

        while(!q.isEmpty()) {
            int[] tmp = q.poll();
            int tmpR = tmp[0];
            int tmpC = tmp[1];

            if(visited[tmpR][tmpC]) continue;
            visited[tmpR][tmpC] = true;
            map[tmpR][tmpC] = islandNum;

            for(int i = 0; i < 4; i++) {
                int nextR = tmpR + dRow[i];
                int nextC = tmpC + dCol[i];
                if(islandNum == 2 && i == 1) {
                    int here = 1;
                }
                if(isValidRange(nextR, nextC) && map[nextR][nextC] != 0) {
                    q.add(new int[]{nextR, nextC});
                }
            }
        }
    }

    static void numberingIsland() {
        boolean[][] visited = new boolean[row][col];

        int islandNum = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(map[i][j] == 1 && !visited[i][j]) {
                    bfsToNumbering(i, j, ++islandNum, visited);
                }
            }
        }

        adjs = new int[islandNum + 1][islandNum + 1];
        for(int i = 0; i < islandNum + 1; i++) {
            Arrays.fill(adjs[i], Integer.MAX_VALUE);
            adjs[i][i] = 0;
        }
    }

    static boolean isNearWater(int r, int c) {
        for(int i = 0; i < 4; i++) {
            int nextR = r + dRow[i];
            int nextC = c + dCol[i];
            if(isValidRange(nextR, nextC) && map[nextR][nextC] == 0) return true;
        }
        return false;
    }

    static Bridge makeBridge(int r, int c, int dRow, int dCol, int startIslandNum) {
        Bridge b = new Bridge();
        int len = 0;
        while(isValidRange(r, c) && map[r][c] == 0) {
            r += dRow;
            c += dCol;
            len++;
        }

        if(isValidRange(r, c) && map[r][c] != startIslandNum) {
            b.length = len;
            b.to = map[r][c];
        }

        return b;
    }

    static void setAdj(int r, int c) {
        int tmpIslandNum = map[r][c];

        for(int i = 0; i < 4; i++) {
            int nextR = r + dRow[i];
            int nextC = c + dCol[i];
            if(isValidRange(nextR, nextC) && map[nextR][nextC] == 0) {
                Bridge b = makeBridge(nextR, nextC, dRow[i], dCol[i], tmpIslandNum);
                if(b.length >= 2) {
                    adjs[tmpIslandNum][b.to] = Math.min(adjs[tmpIslandNum][b.to], b.length);
                    adjs[b.to][tmpIslandNum] = Math.min(adjs[b.to][tmpIslandNum], b.length);
                }
            }
        }
    }

    static void setAdjs() {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(map[i][j] != 0 && isNearWater(i, j)) {
                    setAdj(i, j);
                }
            }
        }
    }

    static void printMap() {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void printAdjs() {
        for(int i = 1; i < adjs.length; i++) {
            for(int j = 1; j < adjs.length; j++) {
                System.out.print(adjs[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static int getMinBridgeSum() {
        boolean[] visited = new boolean[adjs.length];

        int count = 0;
        int sumOfChosenBridge = 0;

        //len, isLandNum
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.add(new int[]{0, 1});

        while (!pq.isEmpty()) {
            int[] tmp = pq.poll();
            int len = tmp[0];
            int tmpNode = tmp[1];

            if(visited[tmpNode]) continue;
            visited[tmpNode] = true;
            count++;
            sumOfChosenBridge += len;

            if(count == adjs.length - 1) break;

            for(int i = 1; i < adjs.length; i++) {
                if(adjs[tmpNode][i] != Integer.MAX_VALUE && !visited[i]) {
                    pq.add(new int[]{adjs[tmpNode][i], i});
                }
            }
        }

        if(count != adjs.length - 1) return -1;

        return sumOfChosenBridge;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        row = Integer.parseInt(st.nextToken());
        col = Integer.parseInt(st.nextToken());

        map = new int[row][col];

        for(int i = 0; i < row; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < col; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        numberingIsland();
        //printMap();
        setAdjs();
        //printAdjs();

        System.out.println(getMinBridgeSum());
    }
}