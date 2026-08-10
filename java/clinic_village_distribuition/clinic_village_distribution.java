import java.util.*;


public class clinic_village_distribution {

    static class Node{
        double load;
        int idx;

        Node(double load, int idx) {
            this.load = load;
            this.idx = idx;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] population = new int[n];
        for (int i = 0; i < n; i++) {
            population[i] = sc.nextInt();
        }

        int k=sc.nextInt();

        //Max-heap
        PriorityQueue<Node> pq= new PriorityQueue<>((a, b) -> Double.compare(b.load, a.load));
        
        int[] clinics = new int[n];
        
        Arrays.fill(clinics, 1);

        for (int i = 0; i < n; i++) {
            pq.add(new Node(population[i], i));
        }

        int extra=k-n;

        while(extra-- > 0){
            Node top = pq.poll();
            int i=top.idx;

            clinics[i]++;

            double newLoad = (double)population[i]/clinics[i];

            pq.add(new Node(newLoad, i));
        }
        System.out.printf("%.2f%n", pq.peek().load);



    }
}
