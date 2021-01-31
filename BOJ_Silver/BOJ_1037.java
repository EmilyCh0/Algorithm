package baekjoon_s;
import java.util.*;
public class BOJ_1037 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		int min=1000000;
		int max=0;
		for(int i=0;i<N;i++) {
			int tmp=scan.nextInt();
			max=Math.max(tmp, max);
			min=Math.min(tmp, min);
		}
		System.out.print(min*max);
		scan.close();
	}
}
