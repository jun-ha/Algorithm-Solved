import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Stack;;
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
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
				if(s.empty()) bw.write("-1\n");
				else {
					bw.write(Integer.toString(s.peek())+"\n");
					s.pop();
				}
				break;
			case "size":
				bw.write(Integer.toString(s.size())+"\n");
				break;
			case "empty":
				if(s.empty()) bw.write("1\n");
				else bw.write("0\n");
				break;
			case "top":
				if(s.empty()) bw.write("-1\n");
				else bw.write(Integer.toString(s.peek())+"\n");
				break;
			}
		}
		bw.flush();
		br.close();
		bw.close();
	}
}