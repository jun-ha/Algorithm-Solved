import java.util.*;
import java.io.*;

public class Main {

    enum Direction {
        LEFT, RIGHT, UP, DOWN
    }

    static class Block {
        int value;

        public Block(int value) {
            this.value = value;
        }
    }

    static class Board {
        int size;
        Block[][] arr;

        public Board() {}
        public Board(int size) {
            this.size = size;
            arr = new Block[size][size];
        }

        private Block[] extractLine(int startRow, int startCol, int dRow, int dCol) {
            Block[] line = new Block[size];
            for(int i = 0; i < size; i++) {
                line[i] = arr[startRow + dRow * i][startCol + dCol * i];
            }
            return line;
        }

        private void exchangeLine(Block[][] arr, Block[] line, int startRow, int startCol, int dRow, int dCol) {
            for(int i = 0; i < size; i++) {
                arr[startRow + dRow * i][startCol + dCol * i] = line[i];
            }
        }

        public Board move(Direction dir) {
            Board board = new Board(size);

            int startRow = 0, startCol = 0, dStartRow = 0, dStartCol = 0, dRow = 0, dCol = 0;
            switch (dir) {
                case LEFT:
                    startRow = 0;
                    startCol = 0;
                    dStartRow = 1;
                    dStartCol = 0;
                    dRow = 0;
                    dCol = 1;
                    break;
                case RIGHT:
                    startRow = 0;
                    startCol = size-1;
                    dStartRow = 1;
                    dStartCol = 0;
                    dRow = 0;
                    dCol = -1;
                    break;
                case UP:
                    startRow = 0;
                    startCol = 0;
                    dStartRow = 0;
                    dStartCol = 1;
                    dRow = 1;
                    dCol = 0;
                    break;
                case DOWN:
                    startRow = size-1;
                    startCol = 0;
                    dStartRow = 0;
                    dStartCol = 1;
                    dRow = -1;
                    dCol = 0;
            }

            for(int i = 0; i < size; i++) {
                Block[] newLine = moveLine(extractLine(startRow + dStartRow * i, startCol + dStartCol * i, dRow, dCol));

                exchangeLine(board.arr, newLine, startRow + dStartRow * i, startCol + dStartCol * i, dRow, dCol);
            }

            return board;
        }

        public int getMaxValue() {
            return Arrays
                    .stream(arr)
                    .flatMap(Arrays::stream)
                    .filter(b -> b != null)
                    .reduce((b1, b2) -> b1.value >= b2.value ? b1 : b2)
                    .get().value;
        }

        private Block[] moveLine(Block[] line) {
            Block[] newLine = new Block[line.length];
            Queue<Block> queue = new ArrayDeque<>();

            Arrays.stream(line).forEach(b -> {
                if (b != null) queue.add(b);
            });

            if(queue.size() <= 1) {
                newLine[0] = queue.poll();
                return newLine;
            }

            Queue<Block> combine = new ArrayDeque<>();
            Block before = queue.poll();

            while (!queue.isEmpty()) {
                if(before == null) {
                    before = queue.poll();
                    continue;
                }

                Block tmp = queue.poll();

                if(before.value == tmp.value) {
                    Block newBlock = new Block(tmp.value * 2);
                    combine.add(newBlock);
                    before = null;
                } else {
                    combine.add(before);
                    before = tmp;
                }

            }

            if(before != null) combine.add(before);

            int idx = 0;
            while(!combine.isEmpty()) {
                newLine[idx++] = combine.poll();
            }

            return newLine;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int boardSize = Integer.parseInt(br.readLine());

        Board board = new Board(boardSize);

        for(int i = 0; i < boardSize; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < boardSize; j++) {
                int value = Integer.parseInt(st.nextToken());

                if(value == 0) {
                    board.arr[i][j] = null;
                } else {
                    Block block = new Block(value);
                    board.arr[i][j] = block;
                }
            }
        }

        Queue<Board> queue = new ArrayDeque<>(1024);
        queue.add(board);

        for(int i = 0; i < 5; i++) {
            int count = queue.size();
            for(int c = 0; c < count; c++) {
                Board b = queue.poll();
                queue.add(b.move(Direction.LEFT));
                queue.add(b.move(Direction.RIGHT));
                queue.add(b.move(Direction.UP));
                queue.add(b.move(Direction.DOWN));
            }
        }

        int maxValue = Integer.MIN_VALUE;
        while(!queue.isEmpty()) {
            maxValue = Math.max(maxValue, queue.poll().getMaxValue());
        }

        System.out.println(maxValue);
    }
}