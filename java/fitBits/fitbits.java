public class fitbits {
    private static int fitsBits(int x, int n){
        int shift = 32 + (~n + 1);

        return ((((x << shift) >> shift) ^ x) == 0) ? 1 : 0;
    }
    public static void main(String[] args) {
        System.out.println("fitsBits(5, 3) = " + fitsBits(5, 3));
        System.out.println("fitsBits(-4, 3) = " + fitsBits(-4, 3));
    }   
}
