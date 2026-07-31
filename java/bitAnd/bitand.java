import java.util.*;
class bitand
{
    private static int bitAnd(int a, int b){
        return ~(~a|~b);
    }
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=bitAnd(a,b);
		System.out.println(c);
	}
}