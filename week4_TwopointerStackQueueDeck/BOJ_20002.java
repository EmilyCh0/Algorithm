package week4_TwopointerStackQueueDeck;
import java.io.*;
import java.util.*;
public class BOJ_20002 {
	static int ans;
	static int N;
	static int[][] arr;
	public static void func(int i, int j) {
		int tmp=arr[i][j];		
		ans=Math.max(tmp, ans);
		int w=1;
		while(w<N-Math.max(i, j)) {
			for(int k=i;k<=i+w;k++) {
				tmp+=arr[k][j+w];
			}
			for(int k=j;k<j+w;k++) {
				tmp+=arr[i+w][k];
			}
			ans=Math.max(tmp, ans);
			w++;			
		}		
	}
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N][N];
		for(int i=0;i<N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			for(int j=0;j<N;j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		ans=arr[0][0];
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				func(i,j);
			}
		}
		System.out.print(ans);
	}
}
