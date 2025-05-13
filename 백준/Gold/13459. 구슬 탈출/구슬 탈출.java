import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static char[][] board;
    static int boardRow, boardCol;
    static int[] initRed = new int[2];
    static int[] initBlue = new int[2];
    static int[] IGNORE_POS = new int[]{-1, -1};

    //up, down, left, right
    static int[] dRow = {-1, 1, 0, 0};
    static int[] dCol = {0, 0, -1, 1};

    static boolean isRedMoveFirst(int[] redPos, int[] bluePos, int move) {
        int redRow = redPos[0];
        int redCol = redPos[1];
        int blueRow = bluePos[0];
        int blueCol = bluePos[1];
        switch (move) {
            case 0: return redRow < blueRow;   //위쪽 기울이기 + 빨강이 더 위에 있으면
            case 1: return redRow > blueRow;   //아래쪽 기울이기 + 빨강이 더 아래 있으면
            case 2: return redCol < blueCol;   //왼쪽 기울이기 + 빨강이 더 왼쪽 있으면
            case 3: return redCol > blueCol;   //오른쪽 기울이기 + 빨강이 더 오른쪽 있으면
            default: throw new IllegalArgumentException();
        }
    }

    static boolean isHole(int r, int c) {
        return board[r][c] == 'O';
    }
    static boolean isNothing(int r, int c) {
        return board[r][c] == '.';
    }

    static class MoveResult {
        int nr;
        int nc;
        boolean metHole;

        MoveResult(int nr, int nc, boolean metHole) {
            this.nr = nr;
            this.nc = nc;
            this.metHole = metHole;
        }
    }

    static boolean isSamePos(int r, int c, int rr, int cc) {
        return r == rr && c == cc;
    }

    static MoveResult moveBall(int[] movingBall, int[] otherBall, int move) {
        int row = movingBall[0];
        int col = movingBall[1];
        int otherBallRow = otherBall[0];
        int otherBallCol = otherBall[1];
        int dR = dRow[move];
        int dC = dCol[move];

        int nextRow = row + dR;
        int nextCol = col + dC;
        while(isNothing(nextRow, nextCol) && !isSamePos(nextRow, nextCol, otherBallRow, otherBallCol)) {
            row = nextRow;
            col = nextCol;
            nextRow = row + dR;
            nextCol = col + dC;
        }

        if(isHole(nextRow, nextCol)) {
            return new MoveResult(-1, -1, true);
        } else {
            return new MoveResult(row, col, false);
        }
    }

    static void solution() {
        Queue<int[]> q = new ArrayDeque<>();

        //공의 위치 정보, 현재 시도 횟수(최대 10), 이전 움직임 정보(중복 방지)
        q.add(new int[]{initRed[0], initRed[1], initBlue[0], initBlue[1], 0, -1});

        while (!q.isEmpty()) {
            int[] tmp = q.poll();

            int[] redPos = new int[]{tmp[0], tmp[1]};
            int[] bluePos = new int[]{tmp[2], tmp[3]};
            int tmpCnt = tmp[4];
            int beforeMove = tmp[5];

            if(tmpCnt >= 10) continue;

            for(int move = 0; move < 4; move++) {
                if(move == beforeMove) continue;

                MoveResult redMove;
                MoveResult blueMove;
                if(isRedMoveFirst(redPos, bluePos, move)) {
                    redMove = moveBall(redPos, IGNORE_POS, move);
                    blueMove = moveBall(bluePos, new int[]{redMove.nr, redMove.nc}, move);
                } else {
                    blueMove = moveBall(bluePos, IGNORE_POS, move);
                    redMove = moveBall(redPos, new int[]{blueMove.nr, blueMove.nc}, move);
                }

                //빨간 공만 들어간 경우
                if(redMove.metHole && !blueMove.metHole) {
                    System.out.println(1);
                    return;
                }

                //파란 공만 들어간 경우
                if(blueMove.metHole) {
                    continue;
                }

                q.add(new int[]{redMove.nr, redMove.nc, blueMove.nr, blueMove.nc, tmpCnt + 1, move});
            }
        }

        System.out.println(0);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        boardRow = Integer.parseInt(st.nextToken());
        boardCol = Integer.parseInt(st.nextToken());

        board = new char[boardRow][boardCol];

        for(int i = 0; i < boardRow; i++) {
            String line = br.readLine();
            for(int j = 0; j < boardCol; j++) {
                board[i][j] = line.charAt(j);
                if(board[i][j] == 'R') {
                    initRed[0] = i;
                    initRed[1] = j;
                    board[i][j] = '.';
                } else if(board[i][j] == 'B') {
                    initBlue[0] = i;
                    initBlue[1] = j;
                    board[i][j] = '.';
                }
            }
        }
        solution();
    }
}