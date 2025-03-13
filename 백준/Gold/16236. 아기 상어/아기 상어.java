import java.io.*;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int N;

    static int[][] board;

    static int sRow;
    static int sCol;
    static int sSize = 2;
    static int sSizeUpCnt = 2;

    static int time = 0;

    //Priority = UP, LEFT, RIGHT, DOWN
    static int[] dRow = {-1, 0, 0, 1};
    static int[] dCol = {0, -1, 1, 0};

    static boolean isValidRange(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < N;
    }

    static boolean findNextFish() {
        Queue<int[]> q = new ArrayDeque<>();
        boolean[][] visited = new boolean[N][N];
        int minStep = Integer.MAX_VALUE;
        int nextPosRow = Integer.MAX_VALUE;
        int nextPosCol = Integer.MAX_VALUE;
        q.add(new int[]{sRow, sCol, 0});

        while(!q.isEmpty()) {
            int[] pos = q.poll();
            int tmpRow = pos[0];
            int tmpCol = pos[1];
            int step = pos[2];
            int tmpVal = board[tmpRow][tmpCol];

            if(step > minStep) continue;
            if(tmpVal > sSize) continue;
            if(visited[tmpRow][tmpCol]) continue;
            visited[tmpRow][tmpCol] = true;

            if(0 < tmpVal && tmpVal < sSize) {
                if(nextPosRow > tmpRow || (nextPosRow == tmpRow && nextPosCol > tmpCol)) {
                    nextPosRow = tmpRow;
                    nextPosCol = tmpCol;
                }
                minStep = step;
                continue;
            }

            for(int i = 0; i < 4; i++) {
                int nextRow = tmpRow + dRow[i];
                int nextCol = tmpCol + dCol[i];

                if(isValidRange(nextRow, nextCol) && !visited[nextRow][nextCol]) {
                    q.add(new int[]{nextRow, nextCol, step + 1});
                }
            }
        }

        if(minStep != Integer.MAX_VALUE) {
            board[nextPosRow][nextPosCol] = 0;
            sSizeUpCnt--;
            if(sSizeUpCnt == 0) {
                sSize++;
                sSizeUpCnt = sSize;
            }
            time += minStep;
            sRow = nextPosRow;
            sCol = nextPosCol;
            return true;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new int[N][N];

        for(int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                int val = Integer.parseInt(st.nextToken());

                if(val == 9) {
                    sRow = i;
                    sCol = j;
                    board[i][j] = 0;
                } else {
                    board[i][j] = val;
                }
            }
        }

        while(findNextFish());

        System.out.println(time);
    }
}