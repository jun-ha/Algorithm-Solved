import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long answer = 0L;

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        Jewelry[] jewelries = new Jewelry[N];
        TreeMap<Integer, Integer> bags = new TreeMap<>();

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int weight = Integer.parseInt(st.nextToken());
            int price = Integer.parseInt(st.nextToken());
            jewelries[i] = new Jewelry(weight, price);
        }

        for(int i = 0; i < K; i++) {
            int capacity = Integer.parseInt(br.readLine());
            if(bags.containsKey(capacity)) {
                bags.put(capacity, bags.get(capacity) + 1);
            } else {
                bags.put(capacity, 1);
            }
        }

        Arrays.sort(jewelries,
                Comparator.comparing((Jewelry j) -> j.price).reversed().thenComparing(jewelry -> jewelry.weight));

        //Arrays.sort(bags);

        for(int i = 0; i < N; i++) {
            int weight = jewelries[i].weight;
            int price = jewelries[i].price;

            int availableCapacity;
            try{
                availableCapacity = bags.tailMap(weight, true).firstEntry().getKey();
            } catch(Exception e) {
                continue;
            }

            if(bags.get(availableCapacity) == 1) {
                bags.remove(availableCapacity);
            } else {
                bags.put(availableCapacity, bags.get(availableCapacity) - 1);
            }

            answer += price;
        }
        System.out.println(answer);
    }

    private static class Jewelry {
        int weight;
        int price;
        Jewelry(int weight, int price) {
            this.weight = weight;
            this.price = price;
        }
    }


}