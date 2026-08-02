class Evnfibonaccisum {

    public static int sumEvenFibonaccibrute(int n) {

        int first = 1;
        int second = 1;
        int sum = 0;

        while (first <= n) {

            if (first % 2 == 0) {
                sum += first;
            }

            int next = first + second;
            first = second;
            second = next;
        }

        return sum;
    }

    public static int sumEvenFibonacciOptimal(int n) {

        int previousEven = 0;
        int currentEven = 2;
        int sum = 0;

        while (currentEven <= n) {

            sum += currentEven;

            int nextEven = (4 * currentEven) + previousEven;

            previousEven = currentEven;
            currentEven = nextEven;
        }

        return sum;
    }

    public static void main(String[] args) {

        int n = 50;

        System.out.println("Sum of even Fibonacci numbers optimal approach : " + sumEvenFibonacciOptimal(n));

        System.out.println("\nSum of even Fibonacci numbers brute force approach: " + sumEvenFibonaccibrute(n));
    }
}