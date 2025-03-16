import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int boardRow, boardCol, sharkCnt;

    static Shark[][] board;

    static boolean isValidRange(int r, int c) {
        return 0 <= r && r < boardRow && 0 <= c && c < boardCol;
    }

    static int[] moveShark(int row, int col, Shark s) {
        int len = 0;
        int dRow = 0, dCol = 0;

        switch(s.dir) {
            case 1 : { //UP
                len = boardRow;
                dRow = -1;
                dCol = 0;
                break;
            }
            case 2 : { //DOWN
                len = boardRow;
                dRow = 1;
                dCol = 0;
                break;
            }
            case 3 : { //RIGHT
                len = boardCol;
                dRow = 0;
                dCol = 1;
                break;
            }
            case 4 : { //LEFT
                len = boardCol;
                dRow = 0;
                dCol = -1;
            }
        }

        int effectiveMove = s.speed % (2 * len - 2);

        int nextR = row;
        int nextC = col;
        for(int i = 0; i < effectiveMove; i++) {
            if(!isValidRange(nextR + dRow, nextC + dCol)) {
                dRow *= -1;
                dCol *= -1;
                s.changeOppositeDirection();
            }
            nextR += dRow;
            nextC += dCol;
        }

        return new int[]{nextR, nextC};
    }

    static class Shark {
        int speed;
        int dir;
        int size;

        Shark(int speed, int dir, int size) {
            this.speed = speed;
            this.dir = dir;
            this.size = size;
        }

        void changeOppositeDirection() {
            switch(dir) {
                case 1 : dir = 2; break;
                case 2 : dir = 1; break;
                case 3 : dir = 4; break;
                case 4 : dir = 3; break;
            }
        }
    }

    static int catchShark(int pos) {
        for(int i = 0; i < boardRow; i++) {
            if(board[i][pos] == null) continue;
            Shark catched = board[i][pos];
            board[i][pos] = null;
            return catched.size;
        }
        return 0;
    }

    static void moveShark() {
        Shark[][] newBoard = new Shark[boardRow][boardCol];
        for(int i = 0; i < boardRow; i++) {
            for(int j = 0; j < boardCol; j++) {
                if(board[i][j] == null) continue;
                int[] nextPos = moveShark(i, j, board[i][j]);

                int nextR = nextPos[0];
                int nextC = nextPos[1];

                if(newBoard[nextR][nextC] == null) {
                    newBoard[nextR][nextC] = board[i][j];
                } else {
                    if(newBoard[nextR][nextC].size < board[i][j].size) {
                        newBoard[nextR][nextC] = board[i][j];
                    }
                }
            }
        }
        board = newBoard;
    }

    static void printBoard() {
        for(int i = 0; i < boardRow; i++) {
            for(int j = 0; j < boardCol; j++) {
                if(board[i][j] == null) System.out.print(0 + " ");
                else System.out.print(board[i][j].size + " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        boardRow = Integer.parseInt(st.nextToken());
        boardCol = Integer.parseInt(st.nextToken());
        sharkCnt = Integer.parseInt(st.nextToken());

        board = new Shark[boardRow][boardCol];

        for(int i = 0; i < sharkCnt; i++) {
            st = new StringTokenizer(br.readLine());
            int row = Integer.parseInt(st.nextToken());
            int col = Integer.parseInt(st.nextToken());
            int speed = Integer.parseInt(st.nextToken());
            int dir = Integer.parseInt(st.nextToken());
            int size = Integer.parseInt(st.nextToken());

            board[row - 1][col - 1] = new Shark(speed, dir, size);
        }

        int answer = 0;

        for(int pos = 0; pos < boardCol; pos++) {
            answer += catchShark(pos);
            moveShark();
        }

        System.out.println(answer);
    }
}