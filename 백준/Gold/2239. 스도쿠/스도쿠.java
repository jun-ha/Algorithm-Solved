import java.util.*;
import java.io.*;

public class Main {

    private static final int[][] board = new int[9][9];
    private static int emptyCount = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int i = 0; i < 9; i++) {
            String line = br.readLine();
            for(int j = 0; j < 9; j++) {
                board[i][j] = line.charAt(j) - '0';
                if(board[i][j] == 0) {
                    emptyCount++;
                }
            }
        }
        dfs();
    }

    private static void dfs() {
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == 0) {
                    boolean[] isAvailable = new boolean[10];
                    Arrays.fill(isAvailable, true);

                    checkImpossible(isAvailable, row, col);

                    for(int i = 1; i <= 9; i++){
                        if(isAvailable[i]) {
                            board[row][col] = i;
                            emptyCount--;

                            if(emptyCount == 0) {
                                printBoard();
                                System.exit(0);
                            }

                            dfs();

                            board[row][col] = 0;
                            emptyCount++;

                        }
                    }
                    return;
                }
            }
        }
    }

    private static void checkImpossible(boolean[] isAvailable, int row, int col) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] != 0) { isAvailable[board[row][i]] = false; }
            if(board[i][col] != 0) { isAvailable[board[i][col]] = false; }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for(int i = startRow; i < startRow + 3; i++) {
            for(int j = startCol; j < startCol + 3; j++) {
                if(board[i][j] != 0) { isAvailable[board[i][j]] = false; }
            }
        }

    }

    private static void printBoard() {
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                System.out.print(board[row][col]);
            }
            System.out.print("\n");
        }
    }
}