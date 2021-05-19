package baekjoon_s;
import java.util.*;
public class BOJ_1463 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		if(N==2||N==3) {
			System.out.print(1);
		}
		else if(N==1) {
			System.out.print(0);
		}
		else {
			int[] dp=new int[N+1];
			dp[1]=0; dp[2]=1; dp[3]=1;
			for(int i=4;i<=N;i++) {
				int tmp=i;
				if(tmp%3==0&&(dp[tmp/3]<dp[tmp-1])) {
					dp[tmp]=dp[tmp/3]+1;
				}
				else if(tmp%2==0&&(dp[tmp/2]<dp[tmp-1])) {
					dp[tmp]=dp[tmp/2]+1;
				}
				else {
					dp[tmp]=dp[tmp-1]+1;
				}
			}
			System.out.print(dp[N]);
		}
	}
}
