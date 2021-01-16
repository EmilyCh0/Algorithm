package week2_backtracking;

import java.util.*;
public class BOJ_15649 {
	static int[] arr = new int[10];
	static boolean[] isUsed;
	static int N;
	static int M;
	static void backtrack(int k) {
		if(k==M) {
			for(int i=0;i<M;i++) {
				System.out.print(arr[i]+" ");
			}
			System.out.println("");
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
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		N = scan.nextInt();
		M = scan.nextInt();
		isUsed = new boolean[N];
		backtrack(0);
	}
}
