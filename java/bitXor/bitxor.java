public class bitxor {
    private static int bitXor(int a, int b) {
        return ~(a & b) & ~(~a & ~b);
    }
    public static void main(String[] args) {
        int a = 4;
        int b = 5;
        int c = bitXor(a, b);
        System.out.println(c);
    }
}
