package week3_dp_binarySearch;
import java.util.*;
import java.io.*;
public class BOJ_12865 {	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int N=Integer.parseInt(st.nextToken());
		int K=Integer.parseInt(st.nextToken());
		int[] arrW = new int[N+1];
		int[] arrV = new int[N+1];

		for(int i=1;i<N+1;i++) {
			st = new StringTokenizer(br.readLine()," ");
			arrW[i]=Integer.parseInt(st.nextToken());
			arrV[i]=Integer.parseInt(st.nextToken());
		}
		int[][] dp = new int[N+1][K+1];
		
		for(int i=1;i<N+1;i++) {
			for(int j=1;j<K+1;j++) {
				dp[i][j]=dp[i-1][j];
				if(j-arrW[i]>=0) {	// arrW[i] 무게만큼 넣을 수 있는 무게를 판단할때...
					dp[i][j]=Math.max(dp[i-1][j], dp[i-1][j-arrW[i]]+arrV[i]);
				}
			}
		}	
		System.out.print(dp[N][K]);
	}
}

/*

// 시간 초과
package week3_dp_binarySearch;
import java.util.*;
import java.io.*;
public class BOJ_12865 {	
	static int[] arrW;
	static int[] arrV;
	static int totalW;
	static int totalV;
	static int N;
	static int K;
	static int ans;
	public static void put(int idx) {
		if(idx==N) {
			if(totalV>ans) {
				ans=totalV;
			}
			return;
		}
		if(totalW+arrW[idx]>K) {	// 무게 초과
			put(idx+1);
		}
		else{
			totalW+=arrW[idx];
			totalV+=arrV[idx];
			put(idx+1);
			totalW-=arrW[idx];
			totalV-=arrV[idx];
			put(idx+1);
			
		}
	}
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		N=Integer.parseInt(st.nextToken());
		K=Integer.parseInt(st.nextToken());
		arrW = new int[N];
		arrV = new int[N];
		totalW=0;
		totalV=0;
		ans=0;
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine()," ");
			arrW[i]=Integer.parseInt(st.nextToken());
			arrV[i]=Integer.parseInt(st.nextToken());
		}
		put(0);
		System.out.print(ans);
	}
}

*/