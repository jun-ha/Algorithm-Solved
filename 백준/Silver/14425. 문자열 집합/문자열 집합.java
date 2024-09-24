import java.io.*;
import java.util.*;

public class Main {

    private static Set<String> set = new HashSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int answer = 0;

        while(N-->0){
            set.add(br.readLine());
        }

        while(M-->0){
            if(set.contains(br.readLine())) answer++;
        }
        System.out.println(answer);
    }
}