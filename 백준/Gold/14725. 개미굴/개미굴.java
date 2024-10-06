import java.util.*;
import java.io.*;

public class Main {
    static StringBuilder sb = new StringBuilder();

    static class Node {
        String name;
        int level;
        Map<String, Node> children = new TreeMap<>();

        public Node(String name, int level) {
            this.name = name;
            this.level = level;
        }
    }

    static void printNode(Node node) {
        if(!node.name.equals("root")) {
            sb.append("--".repeat(node.level - 1))
                    .append(node.name)
                    .append("\n");
        }

        for(Map.Entry<String, Node> child : node.children.entrySet()) {
            printNode(child.getValue());
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        Node root = new Node("root", 0);
        for(int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());

            Node tmp = root;
            for(int level = 1; level <=k; level++) {
                String name = st.nextToken();

                tmp.children.putIfAbsent(name, new Node(name, level));

                tmp = tmp.children.get(name);
            }
        }

        printNode(root);

        System.out.println(sb);
    }
}