import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String str = reader.readLine();
        StringBuilder answer = new StringBuilder();
        for(char c : str.toCharArray()){
            if(Character.isLowerCase(c)) answer.append(Character.toUpperCase(c));
            if(Character.isUpperCase(c)) answer.append(Character.toLowerCase(c));
        }
        System.out.println(answer.toString());
        
    }
}