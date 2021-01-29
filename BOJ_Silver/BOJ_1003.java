package baekjoon_s;
import java.util.*;
public class BOJ_1003 {
	public static void main(String args[]) {
		Scanner scan=new Scanner(System.in);
		int N=scan.nextInt();
		int[] dp0=new int[41];
		int[] dp1=new int[41];
		dp0[0]=1; 
		dp0[1]=0; 
		dp1[0]=0;
		dp1[1]=1;
		for(int i=2;i<=40;i++) {
			dp0[i]=dp0[i-2]+dp0[i-1];
			dp1[i]=dp1[i-2]+dp1[i-1];
		}
		for(int i=0;i<N;i++) {
			int idx=scan.nextInt();
			System.out.println(dp0[idx]+" "+dp1[idx]);
		}
	}
}
