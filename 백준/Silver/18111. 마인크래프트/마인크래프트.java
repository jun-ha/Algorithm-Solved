import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int row = Integer.parseInt(st.nextToken());
        int col = Integer.parseInt(st.nextToken());
        int inventory = Integer.parseInt(st.nextToken());

        int[] blocks = new int[row * col];

        int sum = 0;
        int idx = 0;
        for(int i = 0; i < row; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < col; j++) {
                int block = Integer.parseInt(st.nextToken());
                sum += block;
                blocks[idx++] = block;
            }
        }

        Arrays.sort(blocks);

        int maxHeight = (sum + inventory) / (row * col);
        if(maxHeight > 256) maxHeight = 256;

        int minTime = Integer.MAX_VALUE;
        int tmpMax = Integer.MIN_VALUE;

        int height = maxHeight;
        while(height >= 0) {
            int time = 0;
            for(int b : blocks) {
                if(b < height) time += height - b;
                else time += (b - height) * 2;
            }

            if(time < minTime) {
                minTime = time;
                tmpMax = height;
            }
            height--;
        }

        System.out.println(minTime + " " + tmpMax);
    }
}