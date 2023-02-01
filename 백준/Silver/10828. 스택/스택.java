import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Stack;;
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		Stack<Integer> s = new Stack<>();
		for(int i = 0; i < N; i++) {
			StringTokenizer line = new StringTokenizer(br.readLine());
			String order = line.nextToken();
			switch(order) {
			case "push":
				int num = Integer.parseInt(line.nextToken());
				s.push(num);
				break;
			case "pop":
				if(s.empty()) System.out.println("-1");
				else {
					
					System.out.println(Integer.toString(s.peek()));
					s.pop();
				}
				break;
			case "size":
				System.out.println(Integer.toString(s.size()));
				break;
			case "empty":
				if(s.empty()) System.out.println("1");
				else System.out.println("0");
				break;
			case "top":
				if(s.empty()) System.out.println("-1");
				else System.out.println(Integer.toString(s.peek()));
				break;
			}
		}
	}
}