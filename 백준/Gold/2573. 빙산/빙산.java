import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int boardRow, boardCol;
    static int[] dRow = {-1, 1, 0, 0};
    static int[] dCol = {0, 0, -1, 1};

    static boolean isValidRange(int r, int c) {
        return 0 <= r && r < boardRow && 0 <= c && c < boardCol;
    }

    static void bfsToErase(int[][] board, int r, int c) {
        Queue<int[]> q = new ArrayDeque<>();
        q.add(new int[]{r, c});

        while(!q.isEmpty()) {
            int row = q.peek()[0];
            int col = q.peek()[1];
            q.poll();

            board[row][col] = 0;

            for(int i = 0; i < 4; i++) {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if(isValidRange(nRow, nCol) && board[nRow][nCol] != 0) {
                    board[nRow][nCol] = 0;
                    q.add(new int[]{nRow, nCol});
                }
            }
        }
    }

    static int[][] melt(final int[][] board) {
        int[][] copy = new int[board.length][];
        for (int i = 0; i < board.length; i++) {
            copy[i] = Arrays.copyOf(board[i], board[i].length);
        }

        for(int i = 0; i < boardRow; i++) {
            for(int j = 0; j < boardCol; j++) {
                if(copy[i][j] != 0) {
                    for(int k = 0; k < 4; k++) {
                        int nRow = i + dRow[k];
                        int nCol = j + dCol[k];
                        if(isValidRange(nRow, nCol) && board[nRow][nCol] == 0) {
                            copy[i][j]--;
                        }
                    }
                    copy[i][j] = Math.max(copy[i][j], 0);
                }
            }
        }
        return copy;
    }

    static boolean isSeperated(final int[][] board) {
        int[][] copy = new int[boardRow][boardCol];
        for (int i = 0; i < boardRow; i++) {
            copy[i] = Arrays.copyOf(board[i], boardCol);
        }

        for(int i = 0; i < boardRow; i++) {
            for(int j = 0; j < boardCol; j++) {
                if(copy[i][j] != 0) {
                    bfsToErase(copy, i, j);
                    return !isAllMelted(copy);
                }
            }
        }

        return false;
    }

    static boolean isAllMelted(final int[][] board) {
        for(int i = 0; i < boardRow; i++) {
            for(int j = 0; j < boardCol; j++) {
                if(board[i][j] != 0) return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        boardRow = Integer.parseInt(st.nextToken());
        boardCol = Integer.parseInt(st.nextToken());

        int[][] board = new int[boardRow][boardCol];
        for(int i = 0; i < boardRow; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < boardCol; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int result = 0;
        while(!isSeperated(board) && !isAllMelted(board)) {
            board = melt(board);
            result++;
        }

        System.out.println(isAllMelted(board) ? 0 : result);
    }
}