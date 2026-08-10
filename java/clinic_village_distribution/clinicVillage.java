import java.util.*;

public class clinicVillage {

    static class Village {
        int population;
        int clinics;

        Village(int population) {
            this.population = population;
            this.clinics = 1;
        }

        double load() {
            return (double) population / clinics;
        }
    }

    public static double minimumMaximumLoad(int[] population, int k) {
        
        // max heap based on load
        PriorityQueue<Village> pq = new PriorityQueue<>(
            (a, b) -> Double.compare(b.load(), a.load())
        );

        // 1 clinic per village
        for (int p : population) {
            pq.add(new Village(p));
        }

        int remaining = k - population.length;

        while (remaining > 0) {

            // village with max load
            Village v = pq.poll();
            v.clinics++;
            pq.add(v);

            remaining--;
        }

        return pq.peek().load();
    }

    public static void main(String[] args) {
        int[] population1 = {200, 20, 50};
        int k1 = 5;

        int[] population2 = {100, 100, 100, 100};
        int k2 = 8;

        int[] population3 = {1000, 10, 10};
        int k3 = 5;

        System.out.printf("%.2f%n", minimumMaximumLoad(population1, k1));
        System.out.printf("%.2f%n", minimumMaximumLoad(population2, k2));
        System.out.printf("%.2f%n", minimumMaximumLoad(population3, k3));
    }
}