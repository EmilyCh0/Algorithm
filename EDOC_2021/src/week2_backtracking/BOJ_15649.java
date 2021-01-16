package week2_backtracking;

import java.io.*;
import java.util.StringTokenizer;
public class BOJ_15649 {
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int[] arr = new int[10];
	static boolean[] isUsed;
	static int N;
	static int M;
	static void backtrack(int k) throws IOException {
		if(k==M) {
			for(int i=0;i<M;i++) {
				bw.write(arr[i]+" ");
			}
			bw.newLine();
		}
		else {
			for(int j=0;j<N;j++) {
				if(!isUsed[j]) {
					arr[k]=j+1;
					isUsed[j]=true;
					backtrack(k+1);
					isUsed[j]=false;
				}
				
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		isUsed = new boolean[N];
		backtrack(0);
		bw.flush();
	}
}

