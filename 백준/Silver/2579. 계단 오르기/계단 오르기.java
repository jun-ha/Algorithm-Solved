import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numOfStairs = Integer.parseInt(br.readLine());
        int[] stairs = new int[numOfStairs];
        for(int i = 0; i < numOfStairs; i++) {
            stairs[i] = Integer.parseInt(br.readLine());
        }

        if(numOfStairs == 1 || numOfStairs == 2) {
            int sum = 0;
            for(int s : stairs) {
                sum += s;
            }
            System.out.println(sum);
            return;
        }

        // #0 not choose idx-1
        // #1 choose idx-1, not choose idx-2
        // #2 choose idx-1, choose idx-2
        int[] caseArr = new int[3];

        caseArr[0] = stairs[0];
        caseArr[1] = stairs[1];
        caseArr[2] = stairs[0] + stairs[1];

        for(int i = 2; i < numOfStairs; i++) {
            int[] tmp = Arrays.copyOf(caseArr, 3);
            caseArr[0] = Math.max(tmp[1], tmp[2]);
            caseArr[1] = tmp[0] + stairs[i];
            caseArr[2] = tmp[1] + stairs[i];
        }
        System.out.println(Math.max(caseArr[1], caseArr[2]));
    }
}