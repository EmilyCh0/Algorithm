package baekjoon_s;
import java.util.*;
public class BOJ_1057 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		int a=scan.nextInt();
		int b=scan.nextInt();
		int cnt=0;
		while(a!=b) {
			a=(a+1)/2;
			b=(b+1)/2;
			cnt++;
		}
		System.out.print(cnt);
	}
}
