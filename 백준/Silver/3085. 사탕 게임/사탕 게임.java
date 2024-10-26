import java.io.*;


public class Main {

    static int N;
    static char[][] board;

    static int getMax() {
        int max = Integer.MIN_VALUE;

        for(int row = 0; row < N; row++) {
            int count = 1;
            char before = board[row][0];
            for(int col = 1; col < N; col++) {
                if(board[row][col] == before) {
                    count++;
                    max = Math.max(max, count);
                }
                else {
                    before = board[row][col];
                    count = 1;
                }
            }
        }

        for(int col = 0; col < N; col++) {
            int count = 1;
            char before = board[0][col];
            for(int row = 1; row < N; row++) {
                if(board[row][col] == before) {
                    count++;
                    max = Math.max(max, count);
                }
                else {
                    before = board[row][col];
                    count = 1;
                }
            }
        }

        return max;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new char[N][N];

        int max = Integer.MIN_VALUE;

        for(int i = 0; i < N; i++) {
            String line = br.readLine();
            for(int j = 0; j < N; j++) {
                board[i][j] = line.charAt(j);
            }
        }

        for(int row = 0; row < N; row++) {
            for(int col = 0; col < N - 1; col++) {
                if(board[row][col] != board[row][col + 1]) {
                    char a = board[row][col];
                    char b = board[row][col + 1];

                    board[row][col] = b;
                    board[row][col + 1] = a;
                    
                    max = Math.max(max, getMax());

                    board[row][col] = a;
                    board[row][col + 1] = b;
                }
            }
        }
        for(int col = 0; col < N; col++) {
            for(int row = 0; row < N - 1; row++) {
                if(board[row][col] != board[row + 1][col]) {
                    char a = board[row][col];
                    char b = board[row + 1][col];

                    board[row][col] = b;
                    board[row + 1][col] = a;
                    
                    max = Math.max(max, getMax());

                    board[row][col] = a;
                    board[row + 1][col] = b;
                }
            }
        }


        System.out.println(max);
    }
}