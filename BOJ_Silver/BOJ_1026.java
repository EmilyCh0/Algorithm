package baekjoon_s;
import java.util.*;
public class BOJ_1026 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		int[] a=new int[N];
		int[] b=new int[N];
		for(int i=0;i<N;i++) {
			a[i]=scan.nextInt();
		}
		for(int i=0;i<N;i++) {
			b[i]=scan.nextInt();
		}
		Arrays.sort(a);
		Arrays.sort(b);
		int tmp=N-1;
		int ans=0;
		for(int i=0;i<N;i++) {
			ans+=a[i]*b[tmp];
			tmp--;
		}
		System.out.print(ans);
	}
}
