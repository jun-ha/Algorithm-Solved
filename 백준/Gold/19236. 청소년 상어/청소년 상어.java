import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] dRow = new int[]{0, -1, -1, 0, 1, 1, 1, 0, -1 };
    static int[] dCol = new int[]{0, 0, -1, -1, -1, 0, 1, 1, 1 };

    static int maxScore = Integer.MIN_VALUE;

    static int getNextDir(int dir) {
        if(++dir == 9) return 1;
        return dir;
    }

    static boolean isValidRange(int r, int c) {
        return 0 <= r && r < 4 && 0 <= c && c < 4;
    }

    static class Fish {
        int size;
        int dir;
        Fish(int size, int dir) {
            this.size = size;
            this.dir = dir;
        }
    }

    static class Shark {
        int row;
        int col;
        int dir;
    }

    static class Board {
        int score = 0;
        Fish[][] board = new Fish[4][4];
        Fish[] fishes = new Fish[16];
        Shark shark = new Shark();

        void init() {
            Fish removed = board[0][0];
            shark.row = 0;
            shark.col = 0;
            shark.dir = removed.dir;

            removeFish(removed.size);
            score = removed.size;
        }

        static Board copy(Board original) {
            Board newBoard = new Board();
            newBoard.score = original.score;
            for(int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if(original.board[i][j] != null) {
                        newBoard.board[i][j] = new Fish(original.board[i][j].size, original.board[i][j].dir);
                        newBoard.fishes[newBoard.board[i][j].size - 1] = newBoard.board[i][j];
                    }
                }
            }
            newBoard.shark.row = original.shark.row;
            newBoard.shark.col = original.shark.col;
            newBoard.shark.dir = original.shark.dir;
            return newBoard;
        }

        private int[] findPos(Fish f) {
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    if(board[i][j] == f) {
                        return new int[]{i, j};
                    }
                }
            }
            throw new IllegalStateException();
        }

        private boolean canMove(int r, int c) {
            if(shark.row == r && shark.col == c) return false;
            return isValidRange(r, c);
        }

        void addFish(Fish f, int row, int col) {
            fishes[f.size - 1] = f;
            board[row][col] = f;
        }

        private void removeFish(int size) {
            Fish removed = fishes[size - 1];
            fishes[size - 1] = null;
            int[] pos = findPos(removed);
            board[pos[0]][pos[1]] = null;
        }

        void moveFish() {
            for(Fish f : fishes) {
                if(f == null) continue;

                int[] pos = findPos(f);
                int row = pos[0];
                int col = pos[1];

                int nextDir = f.dir;
                for(int i = 0; i < 7; i++) {
                    int nextRow = row + dRow[nextDir];
                    int nextCol = col + dCol[nextDir];
                    if(canMove(nextRow, nextCol)) {
                        Fish changeFish = board[nextRow][nextCol];
                        board[nextRow][nextCol] = f;
                        board[row][col] = changeFish;
                        f.dir = nextDir;
                        break;
                    }
                    nextDir = getNextDir(nextDir);
                }
            }
        }

        List<Board> moveShark() {
            List<Board> boards = new ArrayList<>();

            int nextRow = shark.row;
            int nextCol = shark.col;

            while(isValidRange(nextRow, nextCol)) {
                if(board[nextRow][nextCol] != null) {
                    Board newBoard = copy(this);
                    Fish removed = board[nextRow][nextCol];

                    newBoard.score += removed.size;
                    newBoard.removeFish(removed.size);
                    newBoard.shark.row = nextRow;
                    newBoard.shark.col = nextCol;
                    newBoard.shark.dir = removed.dir;

                    boards.add(newBoard);
                }

                nextRow += dRow[shark.dir];
                nextCol += dCol[shark.dir];
            }


            return boards;
        }
    }





    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Board board = new Board();
        for(int i = 0; i < 4; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < 4; j++) {
                int size = Integer.parseInt(st.nextToken());
                int dir = Integer.parseInt(st.nextToken());
                board.addFish(new Fish(size, dir), i, j);
            }
        }
        board.init();

        Queue<Board> branch = new ArrayDeque<>();
        branch.add(board);
        while(!branch.isEmpty()) {
            Board b = branch.poll();
            maxScore = Math.max(maxScore, b.score);

            b.moveFish();
            branch.addAll(b.moveShark());
        }

        System.out.println(maxScore);
    }
}