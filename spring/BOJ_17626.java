package spring01;
import java.util.*;
public class BOJ_17626 {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int dp[] = new int[N+1];
		dp[0]=0;
		dp[1]=1;
		int min=50001;
		for(int i=2;i<=N;i++) {
			min=50001;
			for(int j=1;j*j<=i;j++) {
				min=Math.min(min, dp[i-j*j]);
			}
			dp[i]=min+1;
		}
		System.out.print(dp[N]);
	}
}
