import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int[][] getChangeCaseArr(char[][] board, char[][] caseArr) {
        int row = board.length;
        int col = board[0].length;
        int[][] changeArr = new int[row + 1][col + 1];
        Arrays.fill(changeArr[0], 0);
        for(int i = 0; i < row + 1; i++) {
            changeArr[i][0] = 0;
        }


        //가로 누적합
        for(int i = 1; i < row + 1; i++) {
            for(int j = 1; j < col + 1; j++) {
                changeArr[i][j] = changeArr[i][j - 1] + (board[i - 1][j - 1] == caseArr[i - 1][j - 1] ? 0 : 1);
            }
        }

        //사각형 누적합
        for(int i = 1; i < row + 1; i++) {
            for(int j = 1; j < col + 1; j++) {
                changeArr[i][j] += changeArr[i - 1][j];
            }
        }

        return changeArr;
    }

    static int getMinValue(int[][] changeCase, int row, int col, int K) {
        return changeCase[row][col] - changeCase[row - K][col] - changeCase[row][col - K] + changeCase[row - K][col - K];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int row = Integer.parseInt(st.nextToken());
        int col = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        char[][] board = new char[row][col];

        for(int i = 0; i < row; i++) {
            String line = br.readLine();
            for(int j = 0; j < col; j++) {
                board[i][j] = line.charAt(j);
            }
        }

        char[] line1 = new char[col];
        char[] line2 = new char[col];

        for(int i = 0; i < col; i++) {
            if(i % 2 == 0) {
                line1[i] = 'B';
                line2[i] = 'W';
            } else {
                line1[i] = 'W';
                line2[i] = 'B';
            }
        }

        char[][] case1 = new char[row][col]; //BWBW...
        char[][] case2 = new char[row][col]; //WBWB...
        for(int i = 0; i < row; i++) {
            if(i % 2 == 0) {
                case1[i] = line1;
                case2[i] = line2;
            } else {
                case1[i] = line2;
                case2[i] = line1;
            }
        }

        int[][] changeCase1 = getChangeCaseArr(board, case1);
        int[][] changeCase2 = getChangeCaseArr(board, case2);

        int answer = Integer.MAX_VALUE;

        for(int startRow = K; startRow <= row; startRow++) {
            for(int startCol = K; startCol <= col; startCol++) {
                int val1 = getMinValue(changeCase1, startRow, startCol, K);
                int val2 = getMinValue(changeCase2, startRow, startCol, K);
                answer = Math.min(answer, Math.min(val1, val2));
            }
        }

        System.out.println(answer);
    }
}