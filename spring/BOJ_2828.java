package spring03;
import java.util.*;
public class BOJ_2828 {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int N=scan.nextInt();
		int M=scan.nextInt();
		int J=scan.nextInt();
		int s=1;
		int e=M;
		int ans=0;
		for(int i=0;i<J;i++) {
			int apple=scan.nextInt();
			if(apple<=e&&apple>=s) {
				continue;
			}
			else if(Math.abs(apple-s) < Math.abs(e-apple)){
				ans+=Math.abs(apple-s);
				s=apple;
				e=s+M-1;
			}
			else {
				ans+=Math.abs(e-apple);
				e=apple;
				s=e-M+1;
			}
		}
		System.out.print(ans);
	}
}
