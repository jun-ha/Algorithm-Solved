import java.io.*;
import java.util.*;

public class Main {
    private static Stack<Integer> stack = new Stack<>();
    //private static StringBuilder sb = new StringBuilder();

    private static void handleCommand(String commandLine){
        int command = commandLine.charAt(0) - '0';
        switch(command){
            case 1:
                stack.push(Integer.parseInt(commandLine.substring(2)));
                break;
            case 2:
                if(stack.isEmpty()){
                    System.out.println("-1");
                    //sb.append(-1).append('\n');
                } else {
                    System.out.println(stack.pop());
                    //sb.append(stack.pop()).append('\n');
                }
                break;
            case 3:
                System.out.println(stack.size());
                //sb.append(stack.size()).append('\n');
                break;
            case 4:
                if(stack.isEmpty()){
                    System.out.println(1);
                    //sb.append(1).append('\n');
                } else {
                    System.out.println(0);
                    //sb.append(0).append('\n');
                }
                break;
            case 5:
                if(stack.isEmpty()){
                    System.out.println(-1);
                    //sb.append(-1).append('\n');
                } else {
                    System.out.println(stack.peek());
                    //sb.append(stack.peek()).append('\n');
                }
                break;
            default:
                break;
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int nums = Integer.parseInt(br.readLine());

        for(int i = 0; i < nums; i++){
            String commandLine = br.readLine();
            handleCommand(commandLine);
        }
    }
}