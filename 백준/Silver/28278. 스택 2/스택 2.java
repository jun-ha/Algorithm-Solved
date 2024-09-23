import java.io.*;
import java.util.*;

public class Main {
    private static Stack<Integer> stack = new Stack<>();
    private static StringBuilder sb = new StringBuilder();

    private static void handleCommand(String commandLine){
        int command = commandLine.charAt(0) - '0';
        switch(command){
            case 1:
                stack.push(Integer.parseInt(commandLine.substring(2))); return;
            case 2:
                sb.append(stack.isEmpty()? -1 : stack.pop()).append('\n'); return;
            case 3:
                sb.append(stack.size()).append('\n'); return;
            case 4:
                sb.append(stack.isEmpty() ? 1 : 0).append('\n'); return;
            case 5:
                sb.append(stack.isEmpty() ? -1 : stack.peek()).append('\n'); return;
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int nums = Integer.parseInt(br.readLine());

        for(int i = 0; i < nums; i++){
            String commandLine = br.readLine();
            handleCommand(commandLine);
        }

        System.out.println(sb);
    }
}